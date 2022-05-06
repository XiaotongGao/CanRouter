
#ifndef _HARDWARE_H_
#define _HARDWARE_H_

//
//	hardware.h
//
//	-------------------------------------------------------------------
//! @addtogroup HARDWARE
//! <h3> API Functions for hardware access </h3>
//!
//! These functions can be used to access hardware resources. Most
//! resources are simple jobs like LED control. The functions are
//! made in a blocking style returning when the work is done.
//! Please note that not all resources are available on all targets.
//!
//! <h3> Targets: </h3>
//! - PCAN-Router Pro FD
//!
//	-------------------------------------------------------------------
//
//	Copyright (C) PEAK-System Technik GmbH, Darmstadt
//	more Info at http://www.peak-system.com 
//
//! @{


////////////////////////////////////////////////////////////
//! @name errors
//! A function returns one of these errors:
//! @{
#define	HW_ERR_OK				0		//!< OK, no error
#define	HW_ERR_ILLPARAMVAL	1		//!< invalid parameter value
#define	HW_ERR_RESOURCE		2		//!< hardware resource is not available
/*! @}*/


////////////////////////////////////////////////////////////
//! @name LED-handles
//! Handles to the LEDs. Not all LEDs are available on all targets.
//! @{
#define	HW_LED_STATUS		0		//!< status LED
#define	HW_LED_CAN1			1		//!< LED CAN1
#define	HW_LED_CAN2			2		//!< LED CAN2
#define	HW_LED_CAN3			3		//!< LED CAN3
#define	HW_LED_CAN4			4		//!< LED CAN4
#define	HW_LED_CAN5			5		//!< LED CAN5
#define	HW_LED_CAN6			6		//!< LED CAN6
#define	HW_LED_SD1			7		//!< LED 1 SD card socket
#define	HW_LED_SD2			8		//!< LED 2 SD card socket

#define  HW_LED_SD_CARD    HW_LED_SD2
#define  HW_LED_EMMC       HW_LED_SD1
/*! @}*/


////////////////////////////////////////////////////////////
//! @name LED-colors
//! Colors used for the LEDs
//! @{
#define	HW_LED_OFF			0		//!< LED switch OFF
#define	HW_LED_RED			1		//!< LED switch red
#define	HW_LED_GREEN		2		//!< LED switch green
#define	HW_LED_ORANGE		3		//!< LED switch orange
/*! @}*/


////////////////////////////////////////////////////////////
//! Only for PCAN-Router Pro FD
//! @{
// FPGA version
// v6  first version for tests
// v7  mods to support DMA based burst reads
// v8  CAN controller Gen 3 v5 added (bugfix: redundant status frame, firmware hangs up in BusOFF recovery)
// v9  small mods to IRQ pin and internal logic
// v10 modification of two IO pins due to issue at USB card reader enumeration
#define     HW_FPGA_VERSION         ((*((volatile uint32_t *) 0x64000000)) & 0xFF)

#define		HW_ENA_SELFHOLD			GPIOI->BSRR = 1UL << 8					//!< assert selfhold
#define		HW_DIS_SELFHOLD			GPIOI->BSRR = 1UL << 24					//!< deassert selfhold

#define		HW_USBC_CABLE_PRSNT		(( FPGA->SYS_STAT >> 31) & 1)			//!< high if USBC cable is present

#define		HW_MSD_ACCESS_CPU		GPIOJ->BSRR = 1UL << 2 | 1UL << 1		//!< MSD signal muxers to CPU
#define		HW_MSD_ACCESS_USBC		GPIOJ->BSRR = 1UL << 18 | 1UL << 17		//!< MSD signal muxers to USB

#define		HW_USB_CR_ASSERT_RST	GPIOJ->BSRR = 1UL << 7					//!< force USB card reader into reset
#define		HW_USB_CR_DEASSERT_RST	GPIOJ->BSRR = 1UL << 23					//!< release USB card reader from reset

#define		HW_ENA_ACCU_BACKUP		GPIOK->BSRR = 1UL << 0					//!< enable ACCU backup
#define		HW_DIS_ACCU_BACKUP		GPIOK->BSRR = 1UL << 16					//!< disable ACCU backup

#define		HW_ENA_ACCU_CHARGE		GPIOI->BSRR = 1UL << 13					//!< enable ACCU charge
#define		HW_DIS_ACCU_CHARGE		GPIOI->BSRR = 1UL << 29					//!< disable ACCU charge

#define		HW_BR_REACH_MASTER		GPIOI->BSRR = 1UL << 12					//!< BR-Reach PHY as master
#define		HW_BR_REACH_SLAVE		GPIOI->BSRR = 1UL << 28					//!< BR-Reach PHY as slave

#define		HW_ENA_ETH_PHY			GPIOB->BSRR = 1UL << 13 | 1UL << 12		//!< deassert ETH reset, ETH enable
#define		HW_DIS_ETH_PHY			GPIOB->BSRR = 1UL << 29 | 1UL << 28		//!< assert ETH reset, ETH disable

#define		HW_BUZZER_ON			FPGA->SYS_CNTL_SET = 1UL << 30			//!< buzzer (beeper) ON
#define		HW_BUZZER_OFF			FPGA->SYS_CNTL_CLR = 1UL << 30			//!< buzzer (beeper) OFF

#define		HW_SYS_T15_STAT			((( GPIOK->IDR >> 3) & 1) ^ 1)			//!< status of terminal 15

#define		HW_ACCU_CHARGE_STAT		((( GPIOI->IDR >> 15) & 1) ^ 1)			//!< is ACCU charging ?
#define		HW_ACCU_BACKUP_STAT		((( GPIOK->IDR >>  1) & 1) ^ 1)			//!< ACCU backup running ?
#define		HW_ACCU_CHARGE_FAULT	((( GPIOK->IDR >>  2) & 1) ^ 1)			//!< ACCU charger in fault state ?

#define		HW_MSD_BTN_STAT			((( GPIOH->IDR >> 6) & 1) ^ 1)			//!< SD card button pressed ?
/*! @}*/


////////////////////////////////////////////////////////////
//! @name types
//! Basetypes for hardware functions
//! @{
#define	HWResult_t		uint32_t			//!< status code type for API functions
#define	LEDHandle_t		uint8_t			//!< handle type
#define	LEDColor_t		uint8_t			//!< color type
/*! @}*/


#ifdef __cplusplus
extern "C" {
#endif


////////////////////////////////////////////////////////////
//! @name functions
//! This section will describe the API functions. The functions will target
//! to the main() level.
//! @{


//! @brief
//! Initialize hardware (port pins, cpu internals etc.). Call this on
//! main() entry.
//!
//! @return		one error of HW_ERR_...
HWResult_t		HW_Init ( void);



//! @brief
//! Retrieve the module ID from the solder pins or coding switch.
//!
//! @param		buffer		Buffer for the ID
//!
//! @return		one error of HW_ERR_...
HWResult_t		HW_GetModuleID (	uint8_t  *buffer);


//! @brief
//! Read digital inputs. Each bit will represent a digital pin.
//!
//! @param		buffer		Buffer for DIN-value
//!
//! @return		one error of HW_ERR_...
HWResult_t  HW_GetDIN ( uint32_t  *buffer);


//! @brief
//! Set digital outputs. Each bit will represent a digital pin.
//! 
//! @param		buffer		Buffer for DOUT-value
//!
//! @return		one error of HW_ERR_...
HWResult_t  HW_SetDOUT ( uint32_t  *buffer);



//! @brief
//! Set a LED to a specific color.
//!
//! @param		hLED		handle of the LED, see LED-handles
//! @param		color		color to set, see HW_LED_RED ...
//!
//! @return		one error of HW_ERR_...
HWResult_t		HW_SetLED (	LEDHandle_t  hLED, LEDColor_t  color);



//! @brief
//! Jumps to the Bootloader. This function will never return. The user
//! can pass a set of timing values to use or NULL for default timing.
//! 
//! HW_JumpToBootloader ( NULL);		// use default timing for bootloader
//!
//! @param		timing		buffer with timing values for the bootloader or NULL
//!
//! @return		this function will never return
void		HW_JumpToBootloader ( const CANTiming_t  *timing);



//! @brief
//! we will enter power down by removing all conditions forcing the
//! power supply to work. You have to remove the external wake-IN
//! condition (e.g. terminal 15) too. Otherwise the supply will stay
//! active.
void  HW_EnterPowerDown ( void);



//! @brief
//! pass control of USB MSD devices to me (CPU). Do some other stuff to
//! prepare SD card reader for next USB enumeration cycle.
void  HW_PassUsbToMe ( void);



//! @brief
//! pass control of USB MSD devices to host (e.g. windows machine).
void  HW_PassUsbToHost ( void);



//! @brief
//! reset module and start from CAN bootloader again.
void  HW_ResetModule ( void);



/*! @}*/

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif

