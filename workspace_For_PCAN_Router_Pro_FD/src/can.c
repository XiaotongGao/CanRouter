
#include <stdint.h>
#include <stdlib.h>
#include "ARMCM7_DP.h"
#include "can.h"
#include "hardware_private.h"
#include "pcan_core_fd.h"
#include "stm32f765xx.h"
#include "core_cm7.h"


#define		CAN_BUS_MAX			CAN_BUS6


#define	DMA_IDX_2		0
#define	DMA_IDX_4		1


// read 24 WORDs from FPGA using six quad-bursts. Do not modify this value !
// Reading WORD[23] will work like a "release receive buffer"
#define	DMA_RD_SZ		24




typedef union {

uint8_t   data8[8];
uint16_t  data16[4];
uint32_t  data32[2];
uint64_t  data64;
} m64_t;



//                                    DLC   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  A,  B,  C,  D,  E,  F
//                                    LEN   0,  1,  2,  3,  4,  5,  6,  7,  8,  8,  8,  8,  8,  8,  8,  8
static const uint16_t  TxBufferSize[16]   = { 20, 24, 24, 24, 24, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28};


//                                    DLC   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  A,  B,  C,  D,  E,  F
//                                    LEN   0,  1,  2,  3,  4,  5,  6,  7,  8, 12, 16, 20, 24, 32, 48, 64
static const uint16_t  TxBufferSizeFD[16] = { 20, 24, 24, 24, 24, 28, 28, 28, 28, 32, 36, 40, 44, 52, 68, 84};


// 64 WORDs per CAN as filter for 11 bit IDs.
// Each bit controls one ID.
static  uint32_t  StdFilters[6][64];


// DMA index for CAN_Read
static uint8_t  dma_idx;



//! @brief      local wait delay
//! @param[in]  n  microseconds to wait
void  __WaitMicros ( uint32_t n)
{
	uint32_t d;

	
	n *= 100;

	for ( d = 0; d < n; d++)
	{	
		__asm volatile ("nop");
	}
}




//! @brief      send message on CAN bus
//! @param[in]  hBus  handle for CAN bus, see of CAN_BUS...
//! @param[in]  buff  buffer of record, can be CAN_BUFFER_TX_MSG or CAN_BUFFER_RX_MSG or CAN_BUFFER_TX_PAUSE
CANResult_t  CAN_Write ( CANHandle_t  hBus, void  *buff)
{
	CANResult_t  ret;
	uint16_t  stat;
	uint32_t  *buff32, type_size;
	volatile uint32_t  *tx_port;

	
	ret = CAN_ERR_OK;
	
	if ( hBus > CAN_BUS_MAX)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	if ( buff == NULL)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	// check TX cache
	stat = FPGA->CAN[hBus].CAN_STAT;
	
	if ( !( stat & ( 1 << 0)))
	{
		// TX cache is full
		ret = CAN_ERR_TX_FULL;
		goto exit;
	}
	

	buff32 = buff;
	
	// initial
	type_size = CAN_BUFFER_TX_MSG << 16;
	
	if ((( *buff32 >> 16) & 0x0FFF) == CAN_BUFFER_RX_MSG)
	{
		// buffer is receive message
		CANRxMsg_t  *rx_msg;
		
		
		rx_msg = buff;
		
		if ( rx_msg->msgtype & CAN_MSGTYPE_RTR)
		{
			// remote request (20 bytes for record)
			type_size |= 20;
		}
		
		else if ( rx_msg->msgtype & CAN_MSGTYPE_FDF)
		{
			// FD message (up to 84 bytes for record)
			type_size |= TxBufferSizeFD[rx_msg->dlc];
		}
		
		else
		{
			// classical message (max 28 bytes for record)
			type_size |= TxBufferSize[rx_msg->dlc];
		}
		
		buff32 += 3;
	}
	
	else if ((( *buff32 >> 16) & 0xFFFF) == CAN_BUFFER_TX_MSG)
	{
		// buffer is transmit message
		CANTxMsg_t  *tx_msg;
		
		
		tx_msg = buff;
		
		if ( tx_msg->msgtype & CAN_MSGTYPE_RTR)
		{
			// remote request (20 bytes for record)
			type_size |= 20;
		}
		
		else if ( tx_msg->msgtype & CAN_MSGTYPE_FDF)
		{
			// FD message (up to 84 bytes for record)
			type_size |= TxBufferSizeFD[tx_msg->dlc];
		}
		
		else
		{
			// classical message (max 28 bytes for record)
			type_size |= TxBufferSize[tx_msg->dlc];
		}
		
		buff32 += 1;
	}
	
	else if ((( *buff32 >> 16) & 0xFFFF) == CAN_BUFFER_TX_PAUSE)
	{
		// buffer is transmit pause (size is always 8)
		type_size = CAN_BUFFER_TX_PAUSE << 16 | 8;

		buff32 += 1;
	}

	else
	{
		// unsupported buffer
		ret = CAN_ERR_ILL_BUFFER;
		goto exit;
	}
	

	// address of TX port
	tx_port = &FPGA->CAN[hBus].CAN_TX;

	// write record to CAN controller
	// first WORD
	*tx_port = type_size;

	// remaining WORDs
	type_size &= 0x0000FFFF;
	type_size >>= 2;
	type_size -= 1;

	switch ( type_size)
	{
		case 20: *tx_port = *buff32++;
		case 19: *tx_port = *buff32++;
		case 18: *tx_port = *buff32++;
		case 17: *tx_port = *buff32++;
		case 16: *tx_port = *buff32++;
		case 15: *tx_port = *buff32++;
		case 14: *tx_port = *buff32++;
		case 13: *tx_port = *buff32++;
		case 12: *tx_port = *buff32++;
		case 11: *tx_port = *buff32++;
		case 10: *tx_port = *buff32++;
		case  9: *tx_port = *buff32++;
		case  8: *tx_port = *buff32++;
		case  7: *tx_port = *buff32++;
		case  6: *tx_port = *buff32++;
		case  5: *tx_port = *buff32++;
		case  4: *tx_port = *buff32++;
		case  3: *tx_port = *buff32++;
		case  2: *tx_port = *buff32++;
		case  1: *tx_port = *buff32++;
		case  0:
		default:
			break;
	}
	
	exit:
	return ret;
}




//! @brief      read central receive cache from FPGA.
//! @param[in]  hBus  not used here.
//! @param[out] buff  buffer for data record. Must be visible to DMA controller e.g. DTCM
CANResult_t  CAN_Read ( CANHandle_t  hBus, CANBuffer_t  *buff)
{
	CANResult_t  ret;
	uint32_t  stat;

	
	ret = CAN_ERR_RX_EMPTY;
	
	if ( buff == NULL)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}

	// dummy read (still needed?)
	stat = FPGA->SYS_7;
	__DSB();
	
	stat = FPGA->SYS_STAT;

	// check overrun of central RX cache
	if ( stat & ( 1 << 1))
	{
		// todo
		// overrun of central rx-cache
		
		// Each of the 6 CAN-controllers have a small receive fifo. Hardware-logic copies a receive-/status-message
		// from each individual CAN-fifo into a centralized big fifo as soon as it is completely received.
		// In case there is not enough space left in this centralized fifo the can-message is discarded and this flag is set.
		
	}

	__DSB();

	// data present in centralized FIFO ?
	if ( stat & ( 1 << 0))
	{
		// use two alternating DMA streams for data transfer. This will speed up
		// external memory access significantly comparing to CPU initiated single
		// WORD reads.
		if ( dma_idx == DMA_IDX_2)
		{
			// start DMA for this transfer immediately
			DMA2_Stream2->M0AR = (uint32_t) buff;
			__DMB();
			DMA2_Stream2->CR |= 1;

			// prepare other Stream while started Stream is running
			DMA2->HIFCR = 0x3F << 0;

			DMA2_Stream4->FCR  = 7;
			DMA2_Stream4->NDTR = DMA_RD_SZ;
			DMA2_Stream4->PAR  = (uint32_t) &FPGA->SYS_MSG_BOX;
			
			DMA2_Stream4->CR =	1 << 23 |	// MBURST, x4 burst
										1 << 21 |	// PBURST, x4 burst
										2 << 13 |	// MSIZE, 32 bit
										2 << 11 |	// PSIZE, 32 bit
										1 << 10 |	// MINC, dst increment
										1 <<  9 |	// PINC, src increment
										2 <<  6;		// DIR, mem to mem

			// change index for next time
			dma_idx = DMA_IDX_4;

			// wait for end of running transfer
			while ( DMA2_Stream2->CR & 1)
			 {}
		}

		else
		{
			// start DMA for this transfer immediately
			DMA2_Stream4->M0AR = (uint32_t) buff;
			__DMB();
			DMA2_Stream4->CR |= 1;

			// prepare other Stream while started Stream is running
			DMA2->LIFCR = 0x3F << 16;

			DMA2_Stream2->FCR  = 7;
			DMA2_Stream2->NDTR = DMA_RD_SZ;
			DMA2_Stream2->PAR  = (uint32_t) &FPGA->SYS_MSG_BOX;
			
			DMA2_Stream2->CR =	1 << 23 |	// MBURST, x4 burst
										1 << 21 |	// PBURST, x4 burst
										2 << 13 |	// MSIZE, 32 bit
										2 << 11 |	// PSIZE, 32 bit
										1 << 10 |	// MINC, dst increment
										1 <<  9 |	// PINC, src increment
										2 <<  6;		// DIR, mem to mem

			// change index for next time
			dma_idx = DMA_IDX_2;

			// wait for end of running transfer
			while ( DMA2_Stream4->CR & 1)
			 {}
		}
		
		// record read from CANx
		ret = CAN_ERR_OK;
	}


	exit:
	return ret;
}



//! @brief      add 11 bit ID to filter LUT
//! @param[in]  hBus      CAN bus for filter entry see CAN_BUSx
//! @param[in]  extended  not used yet (reserved)
//! @param[in]  FromID    start CAN-ID
//! @param[in]  ToID      end CAN-ID
CANResult_t  CAN_FilterAdd ( CANHandle_t  hBus, uint8_t  extended, uint32_t  FromID, uint32_t  ToID)
{
	CANResult_t  ret;
	uint32_t  i;
	
	
	ret = CAN_ERR_OK;
	
	if ( hBus > CAN_BUS_MAX)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	if ( FromID > ToID  ||  ToID > 0x7FF)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	// stage 1: set single bits
	while ( FromID <= ToID  &&  ( FromID & 0x7))
	{
		StdFilters[hBus][FromID >> 5] |= ( 1 << ( FromID & 0x1F));
		FromID++;
	}
	
	// stage 2: set flags byte-wise
	while (( FromID + 7) <= ToID)
	{
		StdFilters[hBus][FromID >> 5] |= ( 0xFF << ( FromID & 0x1F));
		FromID += 8;
	}
	
	// stage 3: set rest of flags
	while ( FromID <= ToID)
	{
		StdFilters[hBus][FromID >> 5] |= ( 1 << ( FromID & 0x1F));
		FromID++;
	}
	
	// write filter to CAN controller. 64x32 = 2048 bits
	for ( i = 0; i < 64; i++)
	{
		m64_t  cmd;
		
		
		cmd.data32[0] = i << 24 | PCAN_CORE_FD_CMD_SET_STD_FILTER;
		cmd.data32[1] = StdFilters[hBus][i];
		
		FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	}
	
	exit:
	return ret;
}



//! @brief      remove 11 bit ID from filter LUT
//! @param[in]  hBus      CAN bus for filter entry see CAN_BUSx
//! @param[in]  extended  not used yet (reserved)
//! @param[in]  FromID    start CAN-ID
//! @param[in]  ToID      end CAN-ID
CANResult_t  CAN_FilterRem ( CANHandle_t  hBus, uint8_t  extended, uint32_t  FromID, uint32_t  ToID)
{
	CANResult_t  ret;
	uint32_t  i;
	
	
	ret = CAN_ERR_OK;
	
	if ( hBus > CAN_BUS_MAX)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	if ( FromID > ToID  ||  ToID > 0x7FF)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	// stage 1: set single bits
	while ( FromID <= ToID  &&  ( FromID & 0x7))
	{
		StdFilters[hBus][FromID >> 5] &= ~( 1 << ( FromID & 0x1F));
		FromID++;
	}
	
	// stage 2: set flags byte-wise
	while (( FromID + 7) <= ToID)
	{
		StdFilters[hBus][FromID >> 5] &= ~( 0xFF << ( FromID & 0x1F));
		FromID += 8;
	}
	
	// stage 3: set rest of flags
	while ( FromID <= ToID)
	{
		StdFilters[hBus][FromID >> 5] &= ~( 1 << ( FromID & 0x1F));
		FromID++;
	}
	
	// write filter to CAN controller. 64x32 = 2048 bits
	for ( i = 0; i < 64; i++)
	{
		m64_t  cmd;
		
		
		cmd.data32[0] = i << 24 | PCAN_CORE_FD_CMD_SET_STD_FILTER;
		cmd.data32[1] = StdFilters[hBus][i];
		
		FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	}
	
	exit:
	return ret;
}




//! This function removes all CAN-IDs from the filter.
//!
//! @param		hBus				handle for CAN bus, see CAN_BUS...
//! @param		extended			not used yet, 29 bit IDs received always
//!
//! @return		CANResult_t		one result of CAN_ERR_...
CANResult_t  CAN_FilterReset ( CANHandle_t  hBus, uint8_t  extended)
{
	CANResult_t  ret;
	uint32_t  i;
	
	
	ret = CAN_ERR_OK;
	
	if ( hBus > CAN_BUS_MAX)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}


	for ( i = 0; i < 64; i++)
	{
		m64_t  cmd;


		StdFilters[hBus][i] = 0;
		
		cmd.data32[0] = i << 24 | PCAN_CORE_FD_CMD_SET_STD_FILTER;
		cmd.data32[1] = StdFilters[hBus][i];
		
		FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	}

	exit:
	return ret;
}



//! @brief      uninitialize CAN bus (enter reset-mode)
//! @param[in]  hBus  CAN bus to enter reset-mode
CANResult_t  CAN_UnInitialize ( CANHandle_t  hBus)
{
	CANResult_t  ret;
	m64_t  cmd;
	
	
	ret = CAN_ERR_OK;
	
	if ( hBus > CAN_BUS_MAX)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	// reset-mode
	cmd.data32[0] = hBus << 12 | PCAN_CORE_FD_CMD_RESETMODE;
	cmd.data32[1] = 0;
	FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	
	// wait to flush TX cache
	//__WaitMicros ( 80);
	
	exit:
	return ret;
}



//! @brief      initialize CAN bus
//! @param[in]  hBus    bus to initialize
//! @param[in]  timing  bitrate and config settings
CANResult_t  CAN_Initialize ( CANHandle_t  hBus, const CANTiming_t  *timing)
{
	CANResult_t  ret;
	m64_t  cmd;
	
	
	ret = CAN_ERR_OK;
	
	if ( hBus > CAN_BUS_MAX)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	if ( timing == NULL)
	{
		ret = CAN_ERR_ILL_PARAM;
		goto exit;
	}
	
	
	// reset-mode
	cmd.data32[0] = hBus << 12 | PCAN_CORE_FD_CMD_RESETMODE;
	cmd.data32[1] = 0;
	FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	
	
	// flush tx-cache start
	FPGA->CAN[hBus].CAN_CNTL = 1 << 6;
	do
	{
		__WaitMicros(5);
	} while(( FPGA->CAN[hBus].CAN_STAT & 2)==0);	// wait until cache empty
	
	// flush tx-cache end
	FPGA->CAN[hBus].CAN_CNTL = 2 << 6;
	
	
	// clock rate
	if ( timing->can_clk == CAN_CLOCK_80M)
	{
		// from PLL, CLK_DIV to 20 MHz
		FPGA->CAN[hBus].CAN_CNTL = 1 << 5 | 4 << 2 | 2;
	}
	
	else if ( timing->can_clk == CAN_CLOCK_60M)
	{
		// from CLK_DIV
		FPGA->CAN[hBus].CAN_CNTL = 1 << 5 | 0 << 2 | 1;
	}
	
	else if ( timing->can_clk == CAN_CLOCK_40M)
	{
		// from CLK_DIV
		FPGA->CAN[hBus].CAN_CNTL = 1 << 5 | 1 << 2 | 1;
	}
	
	else if ( timing->can_clk == CAN_CLOCK_30M)
	{
		// from CLK_DIV
		FPGA->CAN[hBus].CAN_CNTL = 1 << 5 | 2 << 2 | 1;
	}
	
	else if ( timing->can_clk == CAN_CLOCK_24M)
	{
		// from CLK_DIV
		FPGA->CAN[hBus].CAN_CNTL = 1 << 5 | 3 << 2 | 1;
	}
	
	else if ( timing->can_clk == CAN_CLOCK_20M)
	{
		// from CLK_DIV
		FPGA->CAN[hBus].CAN_CNTL = 1 << 5 | 4 << 2 | 1;
	}
	
	else
	{
		ret = CAN_ERR_ILL_SETUP;
		goto exit;
	}
	
	
	// arbitration timing
	cmd.data32[0] = ( timing->nom_sjw-1) << 24 | ( timing->warning_limit) << 16 | PCAN_CORE_FD_CMD_SET_TIMING_SLOW;	// SJW | EWL | CMD
	cmd.data32[1] = ( timing->nom_brp-1) << 16 | ( timing->nom_tseg1-1) << 8 | ( timing->nom_tseg2-1);				// BRP | seg1 | seg2
	FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	
	
	// FD data timing
	cmd.data32[0] = ( timing->data_sjw-1) << 24 | PCAN_CORE_FD_CMD_SET_TIMING_FAST;													// SJW | CMD
	cmd.data32[1] = ( timing->data_brp-1) << 16 | ( timing->data_tseg1-1) << 8 | ( timing->data_tseg2-1);			// BRP | seg1 | seg2
	FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	
	
	switch ( timing->can_mode)
	{
		case 0:
			// mode "CAN-FD"

			// clear force20 | iso
			cmd.data32[0] = 1 << 20 | 1 << 18 | PCAN_CORE_FD_CMD_CLR_DIS_OPTION;
			cmd.data32[1] = 0;

			FPGA->CAN[hBus].CAN_CMD = cmd.data64;
			break;


		case 1:
			// mode "CAN-FD-ISO"

			// set iso
			cmd.data32[0] = 1 << 18 | PCAN_CORE_FD_CMD_SET_EN_OPTION;
			cmd.data32[1] = 0;

			FPGA->CAN[hBus].CAN_CMD = cmd.data64;

			// clear force20
			cmd.data32[0] = 1 << 20 | PCAN_CORE_FD_CMD_CLR_DIS_OPTION;
			cmd.data32[1] = 0;

			FPGA->CAN[hBus].CAN_CMD = cmd.data64;
			break;


		case 2:
			// mode "CAN_20_AB"

			// set force20 | iso
			// (force20 will have higher prio)
			cmd.data32[0] = 1 << 20 | 1 << 18 | PCAN_CORE_FD_CMD_SET_EN_OPTION;
			cmd.data32[1] = 0;

			FPGA->CAN[hBus].CAN_CMD = cmd.data64;
			break;


		default:
			return CAN_ERR_ILL_SETUP;
	}
	
	
	if ( timing->listen_only)
	{
		// listen-only-mode
		cmd.data32[0] = PCAN_CORE_FD_CMD_LISTENONLYMODE;
		cmd.data32[1] = 0;
	}
	
	else
	{
		// normal-mode
		cmd.data32[0] = PCAN_CORE_FD_CMD_NORMALMODE;
		cmd.data32[1] = 0;
	}
	
	FPGA->CAN[hBus].CAN_CMD = cmd.data64;
	
	exit:
	return ret;
}



//! @brief      initial at startup
void  CAN_Startup ( void)
{
	// prepare DMA for very first transfer
	dma_idx = DMA_IDX_2;
	
	DMA2->LIFCR = 0x3F << 16;

	DMA2_Stream2->FCR  = 7;
	DMA2_Stream2->NDTR = DMA_RD_SZ;
	DMA2_Stream2->PAR  = (uint32_t) &FPGA->SYS_MSG_BOX;
	
	DMA2_Stream2->CR =	1 << 23 |	// MBURST, x4 burst
								1 << 21 |	// PBURST, x4 burst
								2 << 13 |	// MSIZE, 32 bit
								2 << 11 |	// PSIZE, 32 bit
								1 << 10 |	// MINC, dst increment
								1 <<  9 |	// PINC, src increment
								2 <<  6;		// DIR, mem to mem
}




