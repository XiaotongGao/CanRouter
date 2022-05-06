
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "ARMCM7_DP.h"
#include "can.h"
#include "hardware.h"
#include "hardware_private.h"
#include "stm32f765xx.h"


// protos against warnings
void  EEPROM_Init ( void) __attribute__((weak));



//! @brief      dummy weak function for HW_Init() below.
//!             Overwritten if eeprom.c is added to project
void  EEPROM_Init ( void)
{
}



static void  HW_WaitMicros ( uint32_t  n)
{
	uint32_t d;

	
	n *= 100;

	for ( d = 0; d < n; d++)
	{	
		__NOP();
	}
}



void  HW_PassUsbToHost ( void)
{
	// MSD control by USBC
	HW_MSD_ACCESS_USBC;
	HW_WaitMicros ( 20);

	__DMB();

	// run card reader
	HW_USB_CR_DEASSERT_RST;
}



void  HW_PassUsbToMe ( void)
{
	uint32_t  i;


	// USB card reader reset
	HW_USB_CR_ASSERT_RST;
	HW_WaitMicros ( 20);

	// switch MSD signal lines
	HW_MSD_ACCESS_CPU;
	HW_WaitMicros ( 10);

	// generate I2C dummy clocks to prevent firmware eeprom
	// blocking I2C bus, so SD card reader can safely boot
	// on next USB enumeration cycle
	__DMB();

	for ( i = 0; i < 12; i++)
	{
		FPGA->SYS_CNTL_CLR = 1 << 24;
		HW_WaitMicros ( 4);
		FPGA->SYS_CNTL_SET = 1 << 24;
		HW_WaitMicros ( 4);
	}

}



void  HW_ResetModule ( void)
{
	// FPGA reset
	GPIOG->BSRR = 1 << 22;
	
	HW_WaitMicros ( 50);

	// reset
	NVIC_SystemReset();
}



//! @brief      get DINs 3...0 from I/O pins
//! @param[out] buffer  result buffer (single uint32_t)
HWResult_t  HW_GetDIN ( uint32_t  *buffer)
{
	if ( buffer == NULL)
	 { return HW_ERR_ILLPARAMVAL;}

	buffer[0] = (( GPIOK->IDR >> 4) & 0xF) ^ 0xF;
	
	return HW_ERR_OK;
}



//! @brief      get module ID from hex-switch
//! @param[out] buffer  result buffer (single uint8_t)
HWResult_t  HW_GetModuleID (	uint8_t  *buffer)
{
	if ( buffer == NULL)
	 { return HW_ERR_ILLPARAMVAL;}


	buffer[0] = (( GPIOJ->IDR >> 12) & 0xF) ^ 0xF;
	
	return HW_ERR_OK;
}



//! @brief      enter CAN bootloader from application
//! @param[in]  timing  bitrates for all CANs
void  HW_JumpToBootloader ( const CANTiming_t  *timing)
{
	// FPGA reset
	GPIOG->BSRR = 1 << 22;
	
	// invoke PCANFlash loader
	BL_INVOKE->version = 1;
	
	strncpy ( &BL_INVOKE->str_invoke[0], "call bootloader!", sizeof ( BL_INVOKE->str_invoke));
	
	// zero
	memset ( &BL_INVOKE->timing[0], 0, 6 * sizeof ( CANTiming_t));
	
	if ( timing)
	{
		// copy timings for loader
		memcpy ( &BL_INVOKE->timing[0], timing, 6 * sizeof ( CANTiming_t));
	}
	
	// reset
	NVIC_SystemReset();
}



//! @brief      set LED to a specific color
//! @param[in]  hLED   handle for LED see HW_LED_...
//! @param[in]  color  color for LED
HWResult_t  HW_SetLED (	LEDHandle_t  hLED, LEDColor_t  color)
{
	HWResult_t  ret;
	
	
	ret = HW_ERR_OK;
	
	switch ( hLED)
	{
		case HW_LED_STATUS:
			// status LED
			GPIOJ->BSRR = 1UL << 9UL;
			GPIOB->BSRR = 1UL << 15UL;

			switch ( color) {
				case HW_LED_OFF:
					break;


				case HW_LED_RED:
					GPIOJ->BSRR = 1UL << 25UL;
					break;


				case HW_LED_GREEN:
					GPIOB->BSRR = 1UL << 31UL;
					break;


				case HW_LED_ORANGE:
					GPIOJ->BSRR = 1UL << 25UL;
					GPIOB->BSRR = 1UL << 31UL;
					break;
			}
			break;
			
			
		case HW_LED_CAN1:
		case HW_LED_CAN2:
		case HW_LED_CAN3:
		case HW_LED_CAN4:
		case HW_LED_CAN5:
		case HW_LED_CAN6:
			// CAN LED
			hLED -= 1;
			
			switch ( color)
			{
				case HW_LED_OFF:
					FPGA->CAN[hLED].CAN_CNTL = 2 << 10 | 2 << 8;
					break;
					
					
				case HW_LED_RED:
					FPGA->CAN[hLED].CAN_CNTL = 2 << 10 | 1 << 8;
					break;
					
					
				case HW_LED_GREEN:
					FPGA->CAN[hLED].CAN_CNTL = 1 << 10 | 2 << 8;
					break;
					
					
				case HW_LED_ORANGE:
					FPGA->CAN[hLED].CAN_CNTL = 1 << 10 | 1 << 8;
					break;
					
					
				default:
					ret = HW_ERR_ILLPARAMVAL;
					break;
			}
			break;
			
			
		case HW_LED_SD1:
			// SD card LED 1
			switch ( color) {
				case HW_LED_OFF:
					FPGA->SYS_CNTL_SET = 3 << 20;
					break;


				case HW_LED_RED:
					FPGA->SYS_CNTL_CLR = 1 << 20;
					FPGA->SYS_CNTL_SET = 1 << 21;
					break;


				case HW_LED_GREEN:
					FPGA->SYS_CNTL_CLR = 1 << 21;
					FPGA->SYS_CNTL_SET = 1 << 20;
					break;


				case HW_LED_ORANGE:
					FPGA->SYS_CNTL_CLR = 3 << 20;
					break;
			}
			break;


		case HW_LED_SD2:
			// SD card LED 2
			switch ( color) {
				case HW_LED_OFF:
					FPGA->SYS_CNTL_SET = 3 << 22;
					break;


				case HW_LED_RED:
					FPGA->SYS_CNTL_CLR = 1 << 22;
					FPGA->SYS_CNTL_SET = 1 << 23;
					break;


				case HW_LED_GREEN:
					FPGA->SYS_CNTL_CLR = 1 << 23;
					FPGA->SYS_CNTL_SET = 1 << 22;
					break;


				case HW_LED_ORANGE:
					FPGA->SYS_CNTL_CLR = 3 << 22;
					break;
			}
			break;


		default:
			ret = HW_ERR_RESOURCE;
			break;
	}
	
	
	return ret;
}



//! @brief      enter power down
//!             we will enter power down by removing conditions forcing the
//!             power supply to work. You have to remove the external wake-IN
//!             condition (e.g. terminal 15) too. Otherwise the supply will stay
//!             active.
void  HW_EnterPowerDown ( void)
{
	static const uint8_t  sleep[16] = {
		3, 3, 0, 2, 1, 3, 3, 3, 3, 2, 3, 3, 3, 3, 3, 3
	};


	// put all CANs into sleep.
	// Only affecting wake-up capable PHYs like TJA1043.
	FPGA->CAN[CAN_BUS1].CAN_PHY = 1UL << 31 | 1UL << 30 | sleep[FPGA->CAN[CAN_BUS1].CAN_PHY & 0xF] << 28;
	FPGA->CAN[CAN_BUS2].CAN_PHY = 1UL << 31 | 1UL << 30 | sleep[FPGA->CAN[CAN_BUS2].CAN_PHY & 0xF] << 28;
	FPGA->CAN[CAN_BUS3].CAN_PHY = 1UL << 31 | 1UL << 30 | sleep[FPGA->CAN[CAN_BUS3].CAN_PHY & 0xF] << 28;
	FPGA->CAN[CAN_BUS4].CAN_PHY = 1UL << 31 | 1UL << 30 | sleep[FPGA->CAN[CAN_BUS4].CAN_PHY & 0xF] << 28;
	FPGA->CAN[CAN_BUS5].CAN_PHY = 1UL << 31 | 1UL << 30 | sleep[FPGA->CAN[CAN_BUS5].CAN_PHY & 0xF] << 28;
	FPGA->CAN[CAN_BUS6].CAN_PHY = 1UL << 31 | 1UL << 30 | sleep[FPGA->CAN[CAN_BUS6].CAN_PHY & 0xF] << 28;

	// disable ACCU backup.
	// Shutdown backup regulator if accumulator is present
	HW_DIS_ACCU_BACKUP;

	// release selfhold
	HW_DIS_SELFHOLD;
}




//! @brief      initial at power up
HWResult_t  HW_Init ( void)
{
	// basic initialization for CAN
	CAN_Startup();
	
	// local (weak) func or from eeprom.c
	EEPROM_Init();
	
	return HW_ERR_OK;
}

