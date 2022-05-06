
#ifndef  _CAN_USER_H_
#define  _CAN_USER_H_


// Each single value listed here will be a 'true' value. If hardware needs a '-1' decrement this is done by CAN_Initialize().
//                                           clock                arbitration phase               misc               CAN-FD data phase
//    struct CANTiming_t = {                   can_clk,        brp, tseg1, tseg2, sjw,      limit, lo, mod,       brp, tseg1, tseg2, sjw  }
//                                         max. values:       1024,   256,   128, 128,        255,  1,   2,      1024,    32,    16,  16
#define	_80M___1M_80____4M_80_ISO		{ CAN_CLOCK_80M,          1,    63,    16,  16,         96,  0,   1,         1,    15,     4,   4}		// 80 MHz,   1M    80%,   4M 80%, ISO
#define	_80M_800K_80____4M_80_ISO		{ CAN_CLOCK_80M,          1,    79,    20,  20,         96,  0,   1,         1,    15,     4,   4}		// 80 MHz, 800K    80%,   4M 80%, ISO
#define	_80M_500K_80____4M_80_ISO		{ CAN_CLOCK_80M,          1,   127,    32,  32,         96,  0,   1,         1,    15,     4,   4}		// 80 MHz, 500K    80%,   4M 80%, ISO
#define	_80M_250K_80____2M_80_ISO		{ CAN_CLOCK_80M,          2,   127,    32,  32,         96,  0,   1,         2,    15,     4,   4}		// 80 MHz, 250K    80%,   2M 80%, ISO
#define	_80M_125K_80____2M_80_ISO		{ CAN_CLOCK_80M,          4,   127,    32,  32,         96,  0,   1,         4,     7,     2,   2}		// 80 MHz, 125K    80%,   2M 80%, ISO
#define	_80M_100K_80____1M_80_ISO		{ CAN_CLOCK_80M,          4,   159,    40,  40,         96,  0,   1,         4,    15,     4,   4}		// 80 MHz, 100K    80%,   1M 80%, ISO
#define	_80M__95K_80__500K_80_ISO		{ CAN_CLOCK_80M,          8,    83,    21,  21,         96,  0,   1,         8,    15,     4,   4}		// 80 MHz,  95K238 80%, 500K 80%, ISO
#define	_80M__83K_80__500K_80_ISO		{ CAN_CLOCK_80M,         16,    47,    12,  12,         96,  0,   1,        16,     7,     2,   2}		// 80 MHz,  83K333 80%, 500K 80%, ISO
#define	_80M__50K_80__500K_80_ISO		{ CAN_CLOCK_80M,         16,    79,    20,  20,         96,  0,   1,        16,     7,     2,   2}		// 80 MHz,  50K    80%, 500K 80%, ISO
#define	_80M__47K_80__500K_80_ISO		{ CAN_CLOCK_80M,         21,    63,    16,  16,         96,  0,   1,        16,     7,     2,   2}		// 80 MHz,  47K619 80%, 500K 80%, ISO
#define	_80M__33K_80__500K_80_ISO		{ CAN_CLOCK_80M,         24,    79,    20,  20,         96,  0,   1,        16,     7,     2,   2}		// 80 MHz,  33K333 80%, 500K 80%, ISO

// customer definition
#define	_80M_500K_80____2M_80_ISO		{ CAN_CLOCK_80M,          10,   12,     3,   1,         96,  0,   1,         4,     7,     2,   1}		// 80 MHz,  500K   80%,   2M 80%, ISO


#define	_40M___1M_80____4M_80_ISO		{ CAN_CLOCK_40M,          1,    31,     8,   8,         96,  0,   1,         1,     7,     2,   2}		// 40 MHz,   1M    80%,   4M 80%, ISO
#define	_40M_800K_80____4M_80_ISO		{ CAN_CLOCK_40M,          1,    39,    10,  10,         96,  0,   1,         1,     7,     2,   2}		// 40 MHz, 800K    80%,   4M 80%, ISO
#define	_40M_500K_80____4M_80_ISO		{ CAN_CLOCK_40M,          1,    63,    16,  16,         96,  0,   1,         1,     7,     2,   2}		// 40 MHz, 500K    80%,   4M 80%, ISO
#define	_40M_250K_80____2M_80_ISO		{ CAN_CLOCK_40M,          2,    63,    16,  16,         96,  0,   1,         2,     7,     2,   2}		// 40 MHz, 250K    80%,   2M 80%, ISO
#define	_40M_125K_80____1M_80_ISO		{ CAN_CLOCK_40M,          4,    63,    16,  16,         96,  0,   1,         4,     7,     2,   2}		// 40 MHz, 125K    80%,   1M 80%, ISO
#define	_40M_100K_80____1M_80_ISO		{ CAN_CLOCK_40M,          4,    79,    20,  20,         96,  0,   1,         4,     7,     2,   2}		// 40 MHz, 100K    80%,   1M 80%, ISO
#define	_40M__95K_80__500K_80_ISO		{ CAN_CLOCK_40M,          4,    83,    21,  21,         96,  0,   1,         4,    15,     4,   4}		// 40 MHz,  95K238 80%, 500K 80%, ISO
#define	_40M__83K_80__250K_80_ISO		{ CAN_CLOCK_40M,         16,    23,     6,   6,         96,  0,   1,        16,     7,     2,   2}		// 40 MHz,  83K333 80%, 250K 80%, ISO
#define	_40M__50K_80__250K_80_ISO		{ CAN_CLOCK_40M,         16,    39,    10,  10,         96,  0,   1,        16,     7,     2,   2}		// 40 MHz,  50K    80%, 250K 80%, ISO
#define	_40M__47K_80__250K_80_ISO		{ CAN_CLOCK_40M,         21,    31,     8,   8,         96,  0,   1,        16,     7,     2,   2}		// 40 MHz,  47K619 80%, 250K 80%, ISO
#define	_40M__33K_80__250K_80_ISO		{ CAN_CLOCK_40M,         24,    39,    10,  10,         96,  0,   1,        16,     7,     2,   2}		// 40 MHz,  33K333 80%, 250K 80%, ISO



#ifdef __cplusplus
extern "C" {
#endif

// this struct equals a 'CANRxMsg_t' but with an additional WORD due to DMA burst handling.
// DMA transfer will read 24 WORDs from RX cache. This is done by six quad-bursts.
// Otherwise (for 23 WORDs) the DMA engine will split transfers which will need more time.
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

uint32_t  unused;		//!< one WORD more for DMA transfer (six quad-bursts)
} CANRxMsgDMA_t;


// user function protos

void  CAN_UserInit ( void);


void  CAN_UserInvokeBootloader ( uint8_t  settings);

void CAN_2_CANFD_Routing(CANHandle_t  hBus_CANFD, CANRxMsgDMA_t* RxMsg);

void CANFD_2_CAN_Routing(CANHandle_t  hBus_CAN, CANRxMsgDMA_t* RxMsg);

CANResult_t  CAN_UserRead ( CANHandle_t  hBus, void  *buff);



#ifdef __cplusplus
}
#endif


#endif

