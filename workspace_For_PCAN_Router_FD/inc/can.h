
#ifndef  _CAN_H_
#define  _CAN_H_

//
//	can.h
//
//	-------------------------------------------------------------------
//! @addtogroup CAN
//! <h3> API Functions for CAN access </h3>
//!
//! The functions can be used to access the CAN buses.
//! The functions are interrupt protected internally and will target to the
//! main() level. If the user want to send from interrupts like timers
//! he has to build own wrapper functions for interrupt safety.
//!
//! <h3> Targets: </h3>
//! - PCAN-Router FD
//! - PCAN-Router Pro FD
//!
//	-------------------------------------------------------------------
//
//	Copyright (C) PEAK-System Technik GmbH, Darmstadt
//	more Info at http://www.peak-system.com 
//
//! @{


////////////////////////////////////////////////////////////
//! @name buses
//! Use one of these handles to access a CAN bus. Typically this
//! is done by a 'hBus' parameter.
//! @{
#define	CAN_BUS1		0				//!< CAN BUS 1
#define	CAN_BUS2		1				//!< CAN BUS 2
#define	CAN_BUS3		2				//!< CAN BUS 3
#define	CAN_BUS4		3				//!< CAN BUS 4
#define	CAN_BUS5		4				//!< CAN BUS 5
#define	CAN_BUS6		5				//!< CAN BUS 6
#define	CAN_BUSX		0xFFUL		//!< CAN BUS not specified
/*! @}*/


////////////////////////////////////////////////////////////
//! @name errors
//! A function returns one of these error codes:
//! @{
#define	CAN_ERR_OK				0		//!< OK, no error
#define	CAN_ERR_RX_EMPTY		1		//!< receive queue empty
#define	CAN_ERR_TX_FULL		2		//!< transmit queue full
#define	CAN_ERR_ILL_BUFFER	3		//!< bad buffer
#define	CAN_ERR_ILL_PARAM		4		//!< bad parameter
#define	CAN_ERR_ILL_SETUP		5		//!< bad setup value
/*! @}*/


////////////////////////////////////////////////////////////
//! @name clockrates
//! These are the possible clock rates for a CAN controller.
//! @{
#define	CAN_CLOCK_20M		20000000UL		//!< 20 MHz
#define	CAN_CLOCK_24M		24000000UL		//!< 24 MHz
#define	CAN_CLOCK_30M		30000000UL		//!< 30 MHz
#define	CAN_CLOCK_40M		40000000UL		//!< 40 MHz
#define	CAN_CLOCK_60M		60000000UL		//!< 60 MHz
#define	CAN_CLOCK_80M		80000000UL		//!< 80 MHz
/*! @}*/


////////////////////////////////////////////////////////////
//! @name buffertypes
//! Types of the different buffers.
//! @{
#define	CAN_BUFFER_INVALID			0x0000	//!< invalid BUFFER, do not use
#define	CAN_BUFFER_RX_MSG				0x0001	//!< receive message BUFFER
#define	CAN_BUFFER_ERROR_FRAME		0x0002	//!< error frame BUFFER
#define	CAN_BUFFER_STATUS				0x0003	//!< status notification BUFFER
#define	CAN_BUFFER_CRITICAL			0x0102	//!< receive cache level is critical

#define	CAN_BUFFER_TX_MSG				0x1000	//!< transmit message BUFFER
#define	CAN_BUFFER_TX_PAUSE			0x1002	//!< transmit pause to next message
/*! @}*/	


////////////////////////////////////////////////////////////
//! @name messagetypes
//! Types for CAN messages. Can be combined for e.g. EXTENDED | RTR
//! @{
#define	CAN_MSGTYPE_STANDARD		( 0 << 0)	//!< 11 bit standard identifier
#define	CAN_MSGTYPE_RTR			( 1 << 0)	//!< remote request
#define	CAN_MSGTYPE_EXTENDED		( 1 << 1)	//!< 29 bit extended identifier
#define	CAN_MSGTYPE_SRR			( 1 << 2)	//!< self receive request
#define	CAN_MSGTYPE_SINGLESHOT	( 1 << 3)	//!< single shot (no retransmit on error / arbitration lost)
#define	CAN_MSGTYPE_FDF			( 1 << 4)	//!< FD format frame
#define	CAN_MSGTYPE_BRS			( 1 << 5)	//!< bitrate switch
#define	CAN_MSGTYPE_ESI			( 1 << 6)	//!< error state indicator
/*! @}*/


////////////////////////////////////////////////////////////
//! @name dlcvalues
//! dlc values for the different lengths of CAN-FD messages
//! @{
#define	CAN_LEN0_DLC		0x0
#define	CAN_LEN1_DLC		0x1
#define	CAN_LEN2_DLC		0x2
#define	CAN_LEN3_DLC		0x3
#define	CAN_LEN4_DLC		0x4
#define	CAN_LEN5_DLC		0x5
#define	CAN_LEN6_DLC		0x6
#define	CAN_LEN7_DLC		0x7
#define	CAN_LEN8_DLC		0x8
#define	CAN_LEN12_DLC		0x9
#define	CAN_LEN16_DLC		0xA
#define	CAN_LEN20_DLC		0xB
#define	CAN_LEN24_DLC		0xC
#define	CAN_LEN32_DLC		0xD
#define	CAN_LEN48_DLC		0xE
#define	CAN_LEN64_DLC		0xF
/*! @}*/


////////////////////////////////////////////////////////////
//! @name types
//! Some basetypes for CAN functions
//! @{
#define	CANResult_t			uint32_t		//!< return type for functions
#define	CANHandle_t			uint8_t		//!< CAN handle type
/*! @}*/


////////////////////////////////////////////////////////////
//! @name structures
//! structures for CAN messages
//! @{

//! @brief
//! struct for CAN timing. The values passed by this struct are 'real' timing values.
//! If hardware needs a '-1' decrement this is done internally.
typedef struct {

uint32_t  can_clk;				//!< clock for CAN controller, see CAN_CLOCK_...

uint16_t  nom_brp;				//!< prescaler for arbitration phase ( 1..1024)
uint16_t  nom_tseg1;				//!< Tseg1 for arbitration phase ( 1..256)
uint8_t   nom_tseg2;				//!< Tseg2 for arbitration phase ( 1..128)
uint8_t   nom_sjw;				//!< SJW for arbitration phase ( 1..128)

uint8_t   warning_limit;		//!< error warning limit ( ewl typical 96)
uint8_t   listen_only;			//!< 0=normal, 1=listen only mode
uint8_t   can_mode;				//!< 0=CAN-FD nonISO, 1=CAN-FD ISO, 2=CAN_20_AB (forced)

uint16_t  data_brp;				//!< prescaler for CAN-FD data phase ( 1..1024)
uint8_t   data_tseg1;			//!< Tseg1 for CAN-FD data phase ( 1..32)
uint8_t   data_tseg2;			//!< Tseg2 for CAN-FD data phase ( 1..16)
uint8_t   data_sjw;				//!< SJW for CAN-FD data phase ( 1..16)

} CANTiming_t;



//! @brief
//! struct for a CAN transmit message.
typedef struct {

uint16_t  size;					//!< size of the whole struct (computed by CAN_Write)
uint16_t  bufftype;				//!< type of the BUFFER, set this to CAN_BUFFER_TX_MSG

uint32_t  tag[2];					//!< a tag field for user e.g. object pointer

uint8_t   res1:4;					//!< reserved
uint8_t   dlc:4;					//!< data length code of message
uint8_t   res2;					//!< reserved
uint16_t  msgtype;				//!< type of message, bitfield, see CAN_MSGTYPE_...

uint32_t  id;						//!< identifier of message

union {
	uint8_t   data8[64];			//!< data of message (byte based)
	uint16_t  data16[32];		//!< data of message (half word based)
	uint32_t  data32[16];		//!< data of message (word based)
};

} CANTxMsg_t;



//! @brief
//! struct for a TX pause (to limit busload). CAN controller pauses reading
//! of TX cache for 'delay' microseconds
typedef struct {

uint16_t  size;				//!< size of the whole struct (computed by CAN_Write)
uint16_t  bufftype;			//!< type of the BUFFER, set this to CAN_BUFFER_TX_PAUSE

uint32_t  delay:10;			//!< delay in micros (1 ... 1023)
uint32_t  reserved:22;		//!< reserved (set to zero)

} CANTxPause_t;



//! @brief
//! struct for a CAN receive message.
typedef struct {

uint16_t  size;					//!< size of the whole struct
uint16_t  bufftype:12;			//!< type of the BUFFER (CAN_BUFFER_RX_MSG)
uint16_t  hBus:4;

uint32_t  time[2];				//!< timestamp of message

uint32_t  tag[2];					//!< a tag field for user e.g. object pointer

uint8_t   res1:4;					//!< reserved
uint8_t   dlc:4;					//!< data length code of message
uint8_t   res2;					//!< reserved
uint16_t  msgtype;				//!< type of message, bitfield, see CAN_MSGTYPE_...

uint32_t  id;						//!< identifier of message

union {
	uint8_t   data8[64];			//!< data of message (byte based)
	uint16_t  data16[32];		//!< data of message (half word based)
	uint32_t  data32[16];		//!< data of message (word based)
};

} CANRxMsg_t;



//! @brief
//! struct for a status notification from the CAN controller.
typedef struct {

uint16_t  size;					//!< size of the whole struct
uint16_t  bufftype:12;			//!< type of the BUFFER (CAN_BUFFER_STATUS)
uint16_t  hBus:4;

uint32_t  time[2];				//!< timestamp of status change

uint8_t   res1:4;					//!< reserved
uint8_t   res2:1;					//!< reserved
uint8_t   err_passive:1;		//!< 0=error active, 1=error passive
uint8_t   err_status:1;			//!< 0=no error status, 1=error status (depends on warning limit)
uint8_t   bus_status:1;			//!< 1=bus status (CAN controller not involved in bus activity)
uint8_t   res3[3];				//!< reserved

} CANStatus_t;



//! @brief
//! struct for critical cache level notification. Data might be lost.
typedef struct {

uint16_t  size;					//!< size of the whole struct
uint16_t  bufftype:12;			//!< type of the BUFFER (CAN_BUFFER_STATUS)
uint16_t  hBus:4;

uint32_t  time[2];				//!< timestamp

uint32_t  u32;						//!< reserved

} CANCritical_t;



//! @brief
//! struct for error frame
typedef struct {

uint16_t  size;					//!< size of the whole struct
uint16_t  bufftype:12;			//!< type of the BUFFER (CAN_BUFFER_ERROR_FRAME)
uint16_t  hBus:4;

uint32_t  time[2];				//!< timestamp

uint8_t   res1:4;					//!< reserved
uint8_t   type:3;					//!< 0=bit err, 1=form err, 2=stuff err, 3=other err, 4=err cnt decrement
uint8_t   dir:1;					//!< 0=TX, 1=RX
uint8_t   code:7;					//!< error code, see SJA1000
uint8_t   res2:1;					//!< reserved
uint8_t   tx_cnt;					//!< TX error counter
uint8_t   rx_cnt;					//!< RX error counter
} CANErrFrame_t;



//! @brief
//! this union shows the overlay of all BUFFERs that can be read from the receive queue.
typedef union {

// base layout for a BUFFER.
struct {
	uint16_t  size;				//!< size of the whole struct
	uint16_t  bufftype:12;		//!< type of the BUFFER (CAN_BUFFER_...)
	uint16_t  hBus:4;

	uint32_t  data32[22];		//!< data for the BUFFER
};

// receive message
CANRxMsg_t   msg;				//!< receive message BUFFER

// status notification
CANStatus_t  status;			//!< status notification BUFFER

// critical notification
CANCritical_t  critical;	//!< cache critical level BUFFER

// error frame
CANErrFrame_t  error;		//!< error frame BUFFER

} CANBuffer_t;


/*! @}*/


#ifdef __cplusplus
extern "C" {
#endif


////////////////////////////////////////////////////////////
//! @name functions
//! This section will describe the API functions. The functions are target
//! to the main() level. Interrupt protection is done internally.
//! @{


//! @brief
//! This function will initialize a CAN controller.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		timing			buffer for timing values to set up CAN controller
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_Initialize ( CANHandle_t  hBus, const CANTiming_t  *timing);



//! @brief
//! This function will uninitialize a CAN controller.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_UnInitialize ( CANHandle_t  hBus);



//! @brief
//! This function adds CAN-IDs to the filter.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		extended			not used yet, 29 bit IDs received always
//! @param		FromID			start ID (including)
//! @param		ToID				end ID (including)
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_FilterAdd ( CANHandle_t  hBus, uint8_t  extended, uint32_t  FromID, uint32_t  ToID);



//! @brief
//! This function removes CAN-IDs from the filter.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		extended			not used yet, 29 bit IDs received always
//! @param		FromID			start ID (including)
//! @param		ToID				end ID (including)
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_FilterRem ( CANHandle_t  hBus, uint8_t  extended, uint32_t  FromID, uint32_t  ToID);



//! @brief
//! This function removes all CAN-IDs from the filter.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		extended			not used yet, 29 bit IDs received always
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_FilterReset ( CANHandle_t  hBus, uint8_t  extended);



//! @brief
//! CAN_Write() is used to write data to the transmit queue.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		buff				message buffer (CAN_BUFFER_TX_MSG or CAN_BUFFER_RX_MSG or CAN_BUFFER_TX_PAUSE)
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_Write ( CANHandle_t  hBus, void  *buff);



//! @brief
//! CAN_Read() will return a BUFFER from the receive queue.
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		buff				buffer for RX message (CANRxMsg_t)
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_Read ( CANHandle_t  hBus, CANBuffer_t  *buff);



//! @brief
//! initial (once) at startup
void  CAN_Startup ( void);


/*! @}*/

#ifdef __cplusplus
}
#endif

/*! @}*/

#endif

