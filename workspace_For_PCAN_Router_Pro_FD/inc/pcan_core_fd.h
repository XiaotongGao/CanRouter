
#ifndef _PCAN_CORE_FD_H_
#define _PCAN_CORE_FD_H_



// PCAN-Core FD commands
#define	PCAN_CORE_FD_CMD_NOP							0x000		// NOP
#define	PCAN_CORE_FD_CMD_RESETMODE					0x001		// enter reset mode
#define	PCAN_CORE_FD_CMD_NORMALMODE				0x002		// enter normal mode
#define	PCAN_CORE_FD_CMD_LISTENONLYMODE			0x003		// enter listen only mode

#define	PCAN_CORE_FD_CMD_SET_TIMING_SLOW			0x004		// set slow timing
#define	PCAN_CORE_FD_CMD_SET_TIMING_FAST			0x005		// set fast timing

#define	PCAN_CORE_FD_CMD_SET_STD_FILTER			0x006		// set 11 bit standard filter
#define	PCAN_CORE_FD_CMD_RESERVED_2				0x007		// reserved
#define	PCAN_CORE_FD_CMD_RESERVED_3				0x008		// reserved

#define	PCAN_CORE_FD_CMD_TX_ABORT					0x009		// abort transmission
#define	PCAN_CORE_FD_CMD_WR_ERR_CNT				0x00A		// write error counters

#define	PCAN_CORE_FD_CMD_SET_EN_OPTION			0x00B		// set/enable special option
#define	PCAN_CORE_FD_CMD_CLR_DIS_OPTION			0x00C		// clr/disable special option

#define	PCAN_CORE_FD_CMD_SET_ERR_GEN1				0x00D		// set error generator (endless) part 1
#define	PCAN_CORE_FD_CMD_SET_ERR_GEN2				0x00E		// set error generator (endless) part 2
#define	PCAN_CORE_FD_CMD_DIS_ERR_GEN				0x00F		// disable error generation

#define	PCAN_CORE_FD_CMD_RX_BARRIER				0x010		// receive frame barrier

#define	PCAN_CORE_FD_CMD_SET_ERR_GEN_S			0x011		// set error generator (single)



#endif
