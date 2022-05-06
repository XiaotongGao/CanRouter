
#ifndef  _CAN_USER_H_
#define  _CAN_USER_H_


// Each single value listed here will be a 'true' value. If hardware needs a '-1' decrement this is done by CAN_Initialize().
//                                           clock                arbitration phase               misc               CAN-FD data phase
//    struct CANTiming_t = {                   can_clk,        brp, tseg1, tseg2, sjw,      limit, lo, mod,       brp, tseg1, tseg2, sjw  }
//                                         max. values:       1024,   256,   128, 128,        255,  1,   2,      1024,    32,    16,  16
#define	_80M___1M_80____4M_80_ISO		{ CAN_CLOCK_80M,          1,    63,    16,   1,         96,  0,   1,         1,    15,     4,   1}		// 80 MHz,   1M    80%,   4M 80%, ISO
#define	_80M_800K_80____4M_80_ISO		{ CAN_CLOCK_80M,          1,    79,    20,   1,         96,  0,   1,         1,    15,     4,   1}		// 80 MHz, 800K    80%,   4M 80%, ISO
#define	_80M_500K_80____4M_80_ISO		{ CAN_CLOCK_80M,          1,   127,    32,   1,         96,  0,   1,         1,    15,     4,   1}		// 80 MHz, 500K    80%,   4M 80%, ISO
#define	_80M_250K_80____2M_80_ISO		{ CAN_CLOCK_80M,          2,   127,    32,   1,         96,  0,   1,         2,    15,     4,   1}		// 80 MHz, 250K    80%,   2M 80%, ISO

//Weltermaster Motor .corp CANFD comfiguration
#define	_80M_500K_80____2M_80_ISO		{ CAN_CLOCK_80M,          10,   12,     3,   1,         96,  0,   1,         4,     7,     2,   1}		// 80 MHz,  500K   80%,   2M 80%, ISO


#define	_80M_125K_80____2M_80_ISO		{ CAN_CLOCK_80M,          4,   127,    32,   1,         96,  0,   1,         4,     7,     2,   1}		// 80 MHz, 125K    80%,   2M 80%, ISO
#define	_80M_100K_80____1M_80_ISO		{ CAN_CLOCK_80M,          4,   159,    40,   1,         96,  0,   1,         4,    15,     4,   1}		// 80 MHz, 100K    80%,   1M 80%, ISO
#define	_80M__95K_80__500K_80_ISO		{ CAN_CLOCK_80M,          8,    83,    21,   1,         96,  0,   1,         8,    15,     4,   1}		// 80 MHz,  95K238 80%, 500K 80%, ISO
#define	_80M__83K_80__500K_80_ISO		{ CAN_CLOCK_80M,         16,    47,    12,   1,         96,  0,   1,        16,     7,     2,   1}		// 80 MHz,  83K333 80%, 500K 80%, ISO
#define	_80M__50K_80__500K_80_ISO		{ CAN_CLOCK_80M,         16,    79,    20,   1,         96,  0,   1,        16,     7,     2,   1}		// 80 MHz,  50K    80%, 500K 80%, ISO
#define	_80M__47K_80__500K_80_ISO		{ CAN_CLOCK_80M,         21,    63,    16,   1,         96,  0,   1,        16,     7,     2,   1}		// 80 MHz,  47K619 80%, 500K 80%, ISO
#define	_80M__33K_80__500K_80_ISO		{ CAN_CLOCK_80M,         24,    79,    20,   1,         96,  0,   1,        16,     7,     2,   1}		// 80 MHz,  33K333 80%, 500K 80%, ISO


// user function protos

#ifdef __cplusplus
extern "C" {
#endif

void  CAN_UserInit ( void);


void  CAN_UserInvokeBootloader ( uint8_t  settings);


CANResult_t  CAN_UserRead ( CANHandle_t  hBus, void  *buff);


#ifdef __cplusplus
}
#endif


#endif
