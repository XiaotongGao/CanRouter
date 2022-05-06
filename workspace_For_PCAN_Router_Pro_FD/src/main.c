
#include <stdint.h>
#include "can.h"
#include "can_user.h"
#include "hardware.h"
#include "route_map.h"

// abstract:
// This example shows the routing of CAN messages:
// > from CAN1 to CAN2 and vice versa
// > from CAN3 to CAN4 and vice versa
// > from CAN5 to CAN6 and vice versa
//
// CAN1 is used for classical CAN, CAN2 will use CAN-FD messages.
// Fragmentation from larger CAN-FD to classical CAN is not done.
// See code below how to convert the msgtype for CAN/CAN-FD.


// identifier is needed by PEAKFlash.exe -> do not delete
const char Ident[] __attribute__ ((used)) = { "PCAN-Router_Pro_FD"};


// variables for LED toggle
static uint8_t LED_toggleCAN1;
static uint8_t LED_toggleCAN2;
static uint8_t LED_toggleCAN3;
static uint8_t LED_toggleCAN4;
static uint8_t LED_toggleCAN5;
static uint8_t LED_toggleCAN6;



//! @brief      entry point from startup_STM32F7.c
int  main ( void)
{
	// finalize initialization
	HW_Init();
	
	// init CAN
	CAN_UserInit();
	
	// set green LEDs for CANs
	HW_SetLED ( HW_LED_CAN1, HW_LED_GREEN);
	HW_SetLED ( HW_LED_CAN2, HW_LED_GREEN);
	HW_SetLED ( HW_LED_CAN3, HW_LED_GREEN);
	HW_SetLED ( HW_LED_CAN4, HW_LED_GREEN);
	HW_SetLED ( HW_LED_CAN5, HW_LED_GREEN);
	HW_SetLED ( HW_LED_CAN6, HW_LED_GREEN);
	
	// send the greeting message
	// main_greeting();
	
	// main loop
	while ( 1)
	{
		// RX message located in DTCM memory for DMA based read transfer.
		// We need DTCM RAM here due to data integrity because CPU data-cache
		// is not visible to DMA controller. Keep a central single "point of read"
		// and do not read CAN data from different threads.
		static CANRxMsgDMA_t  RxMsg  __attribute__((section(".bss.dtcm")));
		
		
		if ( CAN_UserRead ( CAN_BUSX, &RxMsg) == CAN_ERR_OK)
		{
			switch ( RxMsg.hBus)
			{
				case CAN_BUS1: // CAN
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
					
					// Keep a central single "point of read"
					// and do not read CAN data from different threads.
					CAN_2_CANFD_Routing(CAN_BUS2, &RxMsg);

					break;
					
					
				case CAN_BUS2: // CANFD
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
					
					// Keep a central single "point of read"
					// and do not read CAN data from different threads.
					CANFD_2_CAN_Routing( CAN_BUS1, &RxMsg );

					break;
					
					
				case CAN_BUS3: // CAN
					// message received from CAN3
					LED_toggleCAN3 ^= 1;

					if ( LED_toggleCAN3)
					{
						HW_SetLED ( HW_LED_CAN3, HW_LED_ORANGE);
					}
					
					else
					{
						HW_SetLED ( HW_LED_CAN3, HW_LED_GREEN);
					}
					
					CAN_2_CANFD_Routing(CAN_BUS4, &RxMsg);
					break;
					
					
				case CAN_BUS4: // CANFD
					// message received from CAN4
					LED_toggleCAN4 ^= 1;

					if ( LED_toggleCAN4)
					{
						HW_SetLED ( HW_LED_CAN4, HW_LED_ORANGE);
					}
					
					else
					{
						HW_SetLED ( HW_LED_CAN4, HW_LED_GREEN);
					}
					// Keep a central single "point of read"
					// and do not read CAN data from different threads.
					CANFD_2_CAN_Routing( CAN_BUS3, &RxMsg );

					break;
					
					
				case CAN_BUS5: // CAN
					// message received from CAN5
					LED_toggleCAN5 ^= 1;

					if ( LED_toggleCAN5)
					{
						HW_SetLED ( HW_LED_CAN5, HW_LED_ORANGE);
					}
					
					else
					{
						HW_SetLED ( HW_LED_CAN5, HW_LED_GREEN);
					}
					
					CAN_2_CANFD_Routing(CAN_BUS6, &RxMsg);
					break;
					
					
				case CAN_BUS6: // CANFD
					// message received from CAN6
					LED_toggleCAN6 ^= 1;

					if ( LED_toggleCAN6)
					{
						HW_SetLED ( HW_LED_CAN6, HW_LED_ORANGE);
					}
					
					else
					{
						HW_SetLED ( HW_LED_CAN6, HW_LED_GREEN);
					}
					// Keep a central single "point of read"
					// and do not read CAN data from different threads.
					CANFD_2_CAN_Routing( CAN_BUS5, &RxMsg );
					
					break;
			}
		}
	}
}
