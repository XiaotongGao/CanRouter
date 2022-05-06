
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
//! - PCAN-Router FD
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
#define	HW_LED_CAN1			1		//!< LED CAN1
#define	HW_LED_CAN2			2		//!< LED CAN2
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
//! Only for PCAN-Router FD
//! @{
// FPGA version
// v1  first version for release
// v2  bugfix: error frames send in listen-only-mode
// v3  CAN controller Gen 3 v4 added (Checked by Bosch Testbench)
// v4  CAN controller Gen 3 v5 added (bugfix: redundant status frame, firmware hangs up in BusOFF recovery)
#define FPGA_VERSION         ((*((volatile uint16_t *) 0x80000000)) & 0xFF)
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
//! Removes all conditions holding the power supply active. After this
//! the module will enter power-down state for e.g. remote wake up.
void  HW_EnterPowerDown ( void);


/*! @}*/

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif

