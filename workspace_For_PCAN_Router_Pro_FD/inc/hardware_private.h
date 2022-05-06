
#ifndef  _HARDWARE_PRIVATE_H_
#define  _HARDWARE_PRIVATE_H_


#define	FPGA				((FPGA_t*)	0x64000000)
#define	BL_INVOKE		((BootLoaderInvoke_t*)	0x2001FF00)


typedef struct {
	uint32_t     version;
	char       str_invoke[32];
	CANTiming_t  timing[6];
} BootLoaderInvoke_t;



typedef volatile struct {
	uint32_t  CAN_CNTL;
	uint32_t  CAN_1;
	uint32_t  CAN_STAT;
	uint32_t  CAN_3;
	union {
	uint64_t  CAN_CMD;
	struct {
		uint32_t CAN_CMD_L;
		uint32_t CAN_CMD_H;
		} cmd;
	}; 
	uint32_t  CAN_TX;
	uint32_t  CAN_7;
	uint32_t  CAN_PHY;
	
	uint32_t  CAN_[503];
	
} CANX_t;




typedef volatile struct {
	
	// each block uses 512 WORDs
	
	// Block 0 -> SYS block
	uint32_t  SYS_CNTL_VER;
	uint32_t  SYS_1;
	uint32_t  SYS_CNTL_SET;
	uint32_t  SYS_3;
	uint32_t  SYS_CNTL_CLR;
	uint32_t  SYS_5;
	uint32_t  SYS_STAT;
	uint32_t  SYS_7;
	
	uint32_t  SYS_8;
	uint32_t  SYS_9;
	uint32_t  SYS_10;
	uint32_t  SYS_11;
	uint32_t  SYS_TIME_L;
	uint32_t  SYS_TIME_H;
	uint32_t  SYS_14;
	uint32_t  SYS_15;

	uint32_t  SYS_DOUT_SET;		// set DOUTs (zeros have no effect)
	uint32_t  SYS_17;
	uint32_t  SYS_DOUT_CLR;		// clear DOUTs (zeros have no effect)
	uint32_t  SYS_19;
	uint32_t  SYS_DOUT_NOT;		// invert DOUTs (zeros have no effect)
	uint32_t  SYS_21;
	uint32_t  SYS_DOUT_WR;		// write DOUTs using all bits (ones and zeros)
	uint32_t  SYS_23;

	uint32_t  SYS_24;
	uint32_t  SYS_25;
	uint32_t  SYS_26;
	uint32_t  SYS_27;
	uint32_t  SYS_28;
	uint32_t  SYS_29;
	uint32_t  SYS_30;
	uint32_t  SYS_31;

	uint32_t  SYS_MSG_BOX[24];
	
	uint32_t  SYS_[512-32-24];
	
	// Block 1 - 6 -> CAN1 - CAN6
	CANX_t    CAN[6];
	
} FPGA_t;




#ifdef __cplusplus
extern "C" {
#endif

void  __WaitMicros ( uint32_t n);



#ifdef __cplusplus
}
#endif

#endif

