
#include <stdint.h>
#include <stdlib.h>
#include "can.h"
#include "can_user.h"
#include "hardware.h"


// timings for CAN1 and CAN2
static const CANTiming_t  Timing_CANx[2] = {
_80M_500K_80____2M_80_ISO,	  // CAN1
_80M_500K_80____2M_80_ISO	  // CAN2
};

// use bugfix if FPGA version is 3 or earlier. Code below is for version 4 or later.
//static uint8_t  busOFF[2];



//! @brief      invoke CAN bootloader
//! @param[in]  settings  select set of bitrates for CAN buses (see code below)
void  CAN_UserInvokeBootloader ( uint8_t  settings)
{
	if ( settings == 1)
	{
		// with this path the bootloader will use it's default timing
		HW_JumpToBootloader ( NULL);
	}

	else if ( settings == 2)
	{
		// with this path the bootloader will use the timings from the
		// list below.
		static const CANTiming_t  TimingForBootloader[2] = {
			_80M_500K_80____2M_80_ISO,    // CAN1
			_80M_500K_80____2M_80_ISO     // CAN2
		};

		HW_JumpToBootloader ( &TimingForBootloader[0]);
	}

	else if ( settings == 3)
	{
		// with this path the bootloader will use the timings from application.
		HW_JumpToBootloader ( &Timing_CANx[0]);
	}

}



// CAN_UserRead
// This wrapper is used to pre-process some incoming data.
CANResult_t  CAN_UserRead ( CANHandle_t  hBus, void  *buff)
{
	CANResult_t  ret;
	CANBuffer_t  *rx_buff;
	
	
	ret = CAN_ERR_RX_EMPTY;
	rx_buff = buff;
	
	if ( CAN_Read ( hBus, rx_buff) == CAN_ERR_OK)
	{
		// buffer read from CANx. Check type of buffer.
		switch ( rx_buff->bufftype)
		{
			case CAN_BUFFER_STATUS:
				// the buffer is a status notification from the CAN controller.
				if ( /*!busOFF[hBus]  &&*/  rx_buff->status.bus_status)
				{
					// CAN controller not involved into bus activities
					
					// uninitialize (this includes a TX-path flush)
					CAN_UnInitialize ( hBus);
					
					// initialize CAN controller
					CAN_Initialize ( hBus, &Timing_CANx[hBus]);
				}

				// remember last state to suppress initialization endless loop
				// due to redundant status frame
				//busOFF[hBus] = rx_buff->status.bus_status;
				break;
				
				
			case CAN_BUFFER_RX_MSG:
				// the buffer is a receive message. Forward to application.
				ret = CAN_ERR_OK;
				break;
				
				
			case CAN_BUFFER_CRITICAL:
				// receive queue level was critical. Data might be lost.
				break;
		}
	}
	
	return ret;
}



// init CAN1 and CAN2
void  CAN_UserInit ( void)
{
	// init CAN1
	//busOFF[CAN_BUS1] = 0;
	CAN_Initialize ( CAN_BUS1, &Timing_CANx[CAN_BUS1]);
	
	// receive all 11 bit standard CAN-IDs
	CAN_FilterAdd ( CAN_BUS1, CAN_MSGTYPE_STANDARD, 0x000, 0x7FF);
	

	// init CAN2
	//busOFF[CAN_BUS2] = 0;
	CAN_Initialize ( CAN_BUS2, &Timing_CANx[CAN_BUS2]);
	
	// receive all 11 bit standard CAN-IDs
	CAN_FilterAdd ( CAN_BUS2, CAN_MSGTYPE_STANDARD, 0x000, 0x7FF);
}
