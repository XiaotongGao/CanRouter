
#include <stdint.h>
#include <stdlib.h>
#include "can.h"
#include "can_user.h"
#include "hardware.h"
#include "route_map.h"

// identifier is needed by PEAK-Flash.exe -> do not delete
const char Ident[] __attribute__ ((used)) = { "PCAN-Router_FD"};

// variables for LED toggle
static uint8_t LED_toggleCAN1;
static uint8_t LED_toggleCAN2;


// main()
// entry point from startup
int  main ( void)
{
	// init hardware and timer 0. Timer 0 is free running
	// with 1 us resolution without any IRQ.
	HW_Init();
	
	// init CAN
	CAN_UserInit();
	
	// set green LEDs for CAN1 and CAN2
	HW_SetLED ( HW_LED_CAN1, HW_LED_GREEN);
	HW_SetLED ( HW_LED_CAN2, HW_LED_GREEN);
	
	// main loop
	while ( 1)
	{
		CANRxMsg_t  RxMsg;
		// process messages from CAN1 -> standard CAN
		if ( CAN_UserRead ( CAN_BUS1, &RxMsg ) == CAN_ERR_OK)
		{
			// message received from CAN1
			LED_toggleCAN1 ^= 1;

			if ( LED_toggleCAN1)
			{
				HW_SetLED ( HW_LED_CAN1, HW_LED_ORANGE);
			}
			
			else
			{
				HW_SetLED ( HW_LED_CAN1, HW_LED_GREEN);
			}
#if (FOR_MIFA_FVCM | FOR_WM_HDMAP)
			if (RxMsg.msgtype != MSGTYPE_FD_CAN)
			{
#if (FOR_MIFA_FVCM == ON)
				const Route_Map_One2One_t *map = IndexToOutputMsg(RxMsg.id, DIRECTION_STANDAR_TO_FD);
				if (map != NULL)
				{	
					// set info
					mapDataFromInToOutOne2One(&RxMsg, map, DIRECTION_STANDAR_TO_FD);
					// forward message to CAN2 -> CAN FD
					CAN_Write ( CAN_BUS2, &RxMsg );
				}
#else
				special_map_for_G10(&RxMsg);
				CAN_Write ( CAN_BUS2, &RxMsg );
#endif
			}
#else
			/* forward directly*/
			CAN_Write ( CAN_BUS2, &RxMsg );
				
#endif // #if (FOR_MIFA_FVCM | FOR_WM_HDMAP) end
		}


		// process messages from CAN2 -> CAN FD
		if ( CAN_UserRead ( CAN_BUS2, &RxMsg ) == CAN_ERR_OK)
		{
			// message received from CAN2
			LED_toggleCAN2 ^= 1;

			if ( LED_toggleCAN2)
			{
				HW_SetLED ( HW_LED_CAN2, HW_LED_ORANGE);
			}
			
			else
			{
				HW_SetLED ( HW_LED_CAN2, HW_LED_GREEN);
			}
#if (FOR_MIFA_FVCM | FOR_SRR_BYTE | FOR_SRR_BIT)
			if (RxMsg.msgtype == MSGTYPE_FD_CAN)
			{
#if (FOR_MIFA_FVCM == ON)
				const Route_Map_One2One_t *map1 = IndexToOutputMsg(RxMsg.id, DIRECTION_FD_TO_STANDARD);
				if (map1 != NULL)
				{
					// set info
					mapDataFromInToOutOne2One(&RxMsg, map1, DIRECTION_FD_TO_STANDARD);
					// forward message to CAN1 -> standard CAN 
					CAN_Write ( CAN_BUS1, &RxMsg );
				}
#endif
				
#if (FOR_SRR_BYTE == ON)
				const Route_Map_One2Multi_t *map2 = IsOne2MultiMsg(RxMsg.id);
				if (map2 != NULL)
				{
					for (int i = 0; i < map2->split_count; i ++)
					{
						// set info
						mapDataFromInToOutOne2One(&RxMsg, &(map2->sub_map[i]), DIRECTION_FD_TO_STANDARD);
						// forward message to CAN1 -> standard CAN 
						CAN_Write ( CAN_BUS1, &RxMsg );
					}
				}
#elif (FOR_SRR_BIT == ON)
				srr_canfd2can_route_by_signals(&RxMsg);
#endif

			}
#else		
			/* forward directly ??? */
			CAN_Write ( CAN_BUS1, &RxMsg );
#endif
		}
	}
}
