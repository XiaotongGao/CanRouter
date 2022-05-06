
#include "route_map.h"

// initialize data length map
uint8_t m_data_length_map[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

#if (FOR_SRR_BIT == ON)
const uint32_t srr_can_ids[20] = {
		0x2c6u, 0x2c7u, 0x2c8u, 0x2c9u, 0x2cau, 0x2cbu, 0x2ccu, 0x2cdu, 0x2ceu, 0x2cfu, 
		0x2d0u, 0x2d1u, 0x2d2u, 0x2d3u, 0x2d4u, 0x2d5u, 0x2d6u, 0x2d7u, 0x2d8u, 0x2d9u
};
#endif

// init map table
// CAN -> CAN 
const Route_Map_One2One_t map_table_one2one_CAN_2_CAN[3] =
{
	// {
	// 	0x418, // CAN id in
	// 	0x1F5, // CAN id out
	// 	DIRECTION_STANDAR_TO_STANDAR,
	// 	MSGTYPE_STANDARD_CAN,
	// 	1,
	// 	{
	// 		{0, 3}
	// 	},
	// 	CAN_LEN5_DLC
	// },
	// {
	// 	0x200,
	// 	0x348,
	// 	DIRECTION_STANDAR_TO_STANDAR,
	// 	MSGTYPE_STANDARD_CAN,
	// 	4,
	// 	{
	// 		{2, 0},
	// 		{3, 1},
	// 		{4, 2},
	// 		{5, 3}
	// 	},
	// 	CAN_LEN5_DLC
	// },
	// {
	// 	0x208,
	// 	0x34A,
	// 	DIRECTION_STANDAR_TO_STANDAR,
	// 	MSGTYPE_STANDARD_CAN,
	// 	4,
	// 	{
	// 		{4, 0},
	// 		{5, 1},
	// 		{6, 2},
	// 		{7, 3}
	// 	},
	// 	CAN_LEN6_DLC
	// }
};


#if (FOR_MIFA_FVCM == ON)
// CAN-->CANFD 
const Route_Map_One2One_t map_table_one2one_CAN_2_CANFD[19] =
{
	{
		0x152, // CAN id in
		0x152, // CAN id out
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x1E0,
		0x1E0,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x153,
		0x153,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x150,
		0x150,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x423,
		0x423,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x793,
		0x793,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x4B3,
		0x4B3,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x6B3,
		0x6B3,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x1DA,
		0x1DA,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x15B,
		0x15B,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
	{
		0x1F3,
		0x1F3,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN32_DLC
	},
	{
		0x2F3,
		0x1F3,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 8},
			{1, 9},
			{2, 10},
			{3, 11},
			{4, 12},
			{5, 13},
			{6, 14},
			{7, 15},
		},
		CAN_LEN32_DLC
	},
	{
		0x3F3,
		0x1F3,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 16},
			{1, 17},
			{2, 18},
			{3, 19},
			{4, 20},
			{5, 21},
			{6, 22},
			{7, 23},
		},
		CAN_LEN32_DLC
	},
	{
		0x4F3,
		0x1F3,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 24},
			{1, 25},
			{2, 26},
			{3, 27},
			{4, 28},
			{5, 29},
			{6, 30},
			{7, 31},
		},
		CAN_LEN32_DLC
	},
	{
		0x1F0,
		0x1F0,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN24_DLC
	},
	{
		0x2F0,
		0x1F0,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 8},
			{1, 9},
			{2, 10},
			{3, 11},
			{4, 12},
			{5, 13},
			{6, 14},
			{7, 15},
		},
		CAN_LEN24_DLC
	},
	{
		0x3F0,
		0x1F0,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 16},
			{1, 17},
			{2, 18},
			{3, 19},
			{4, 20},
			{5, 21},
			{6, 22},
			{7, 23},
		},
		CAN_LEN24_DLC
	},
	{
		0x154,
		0x154,
		DIRECTION_STANDAR_TO_FD,
		MSGTYPE_FD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	}
};
#endif

#if (FOR_MIFA_FVCM == ON)
// CANFD-->CAN start
const Route_Map_One2One_t map_table_one2one_CANFD_2_CAN[43] =
{
	{
		0x308,
		0x308,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x2A4,
		0x2A4,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x157,
		0x157,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0xFD,
		0xFD,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x3A0,
		0x3A0,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x342,
		0x342,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x7DF,
		0x7DF,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x723,
		0x723,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0xA4,
		0xA4,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x134,
		0x134,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x95,
		0x95,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x96,
		0x96,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x97,
		0x97,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x98,
		0x98,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x99,
		0x99,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x198,
		0x198,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x193,
		0x193,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x1BF,
		0x1BF,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x185,
		0x185,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x188,
		0x188,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x332,
		0x332,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x334,
		0x334,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x32B,
		0x32B,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x2F1,
		0x2F1,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0xA9,
		0xA9,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x2E3,
		0x2E3,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x2E1,
		0x2E1,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x2F2,
		0x2F2,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0xAA,
		0xAA,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x331,
		0x331,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x18A,
		0x18A,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x80,
		0x80,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x3B0,
		0x3B0,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x9E,
		0x9E,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x192,
		0x192,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x1FE,
		0x1FE,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x132,
		0x132,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x91,
		0x91,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x94,
		0x94,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x1BD,
		0x1BD,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x184,
		0x184,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x189,
		0x189,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	},
    {
		0x190,
		0x190,
		DIRECTION_FD_TO_STANDARD,
		MSGTYPE_STANDARD_CAN,
		8,
		{
			{0, 0},
			{1, 1},
			{2, 2},
			{3, 3},
			{4, 4},
			{5, 5},
			{6, 6},
			{7, 7},
		},
		CAN_LEN8_DLC
	}
};
#endif

#if (FOR_MIFA_FVCM | FOR_SRR_BYTE)
#if (FOR_MIFA_FVCM == ON)
const Route_Map_One2Multi_t map_table_one2multi[2] =
#elif (FOR_SRR_BYTE == ON)
const Route_Map_One2Multi_t map_table_one2multi[20] =
#endif
{
	#if (FOR_MIFA_FVCM == ON)
    {
        0xA5,
        2,
        {
            {
                0xA5,
                0xA5,
                DIRECTION_FD_TO_STANDARD,
                MSGTYPE_STANDARD_CAN,
				8,
                {
                    {0, 0},
                    {1, 1},
                    {2, 2},
                    {3, 3},
                    {4, 4},
                    {5, 5},
                    {6, 6},
                    {7, 7},
                },
                CAN_LEN8_DLC
            },
            {
                0xA5,
                0x1A5,
                DIRECTION_FD_TO_STANDARD,
                MSGTYPE_STANDARD_CAN,
				8,
                {
                    {8, 0},
                    {9, 1},
                    {10, 2},
                    {11, 3},
                    {12, 4},
                    {13, 5},
                    {14, 6},
                    {15, 7},
                },
                CAN_LEN8_DLC
            }
        }
    },
    {
        0xA8,
        2,
        { 
            {
                0xA8,
                0xA8,
                DIRECTION_FD_TO_STANDARD,
                MSGTYPE_STANDARD_CAN,
				8,
                {
                    {0, 0},
                    {1, 1},
                    {2, 2},
                    {3, 3},
                    {4, 4},
                    {5, 5},
                    {6, 6},
                    {7, 7},
                },
                CAN_LEN8_DLC
            },
            {
                0xA8,
                0x1A8,
                DIRECTION_FD_TO_STANDARD,
                MSGTYPE_STANDARD_CAN,
				8,
                {
                    {8, 0},
                    {9, 1},
                    {10, 2},
                    {11, 3},
                    {12, 4},
                    {13, 5},
                    {14, 6},
                    {15, 7},
                },
                CAN_LEN8_DLC
            }
        }
    },
#elif (FOR_SRR_BYTE == ON)
	/* ADU ---------------------------------------------------------------------------------------------- start ------------------------------------------------------------------------------ */
	{
		0x2C6,
		3,
		{
			{
				0x2C6,
				0x3C6,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C6,
				0x4C6,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C6,
				0x5C6,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2C7,
		3,
		{
			{
				0x2C7,
				0x3C7,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C7,
				0x4C7,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C7,
				0x5C7,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2C8,
		3,
		{
			{
				0x2C8,
				0x3C8,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C8,
				0x4C8,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C8,
				0x5C8,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2C9,
		3,
		{
			{
				0x2C9,
				0x3C9,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C9,
				0x4C9,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2C9,
				0x5C9,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2CA,
		3,
		{
			{
				0x2CA,
				0x3CA,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CA,
				0x4CA,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CA,
				0x5CA,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2CB,
		3,
		{
			{
				0x2CB,
				0x3CB,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CB,
				0x4CB,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CB,
				0x5CB,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2CC,
		3,
		{
			{
				0x2CC,
				0x3CC,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CC,
				0x4CC,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CC,
				0x5CC,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2CD,
		3,
		{
			{
				0x2CD,
				0x3CD,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CD,
				0x4CD,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CD,
				0x5CD,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2CE,
		3,
		{
			{
				0x2CE,
				0x3CE,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CE,
				0x4CE,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CE,
				0x5CE,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2CF,
		3,
		{
			{
				0x2CF,
				0x3CF,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CF,
				0x4CF,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2CF,
				0x5CF,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D0,
		3,
		{
			{
				0x2D0,
				0x3D0,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D0,
				0x4D0,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D0,
				0x5D0,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D1,
		3,
		{
			{
				0x2D1,
				0x3D1,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D1,
				0x4D1,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D1,
				0x5D1,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D2,
		3,
		{
			{
				0x2D2,
				0x3D2,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D2,
				0x4D2,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D2,
				0x5D2,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D3,
		3,
		{
			{
				0x2D3,
				0x3D3,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D3,
				0x4D3,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D3,
				0x5D3,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D4,
		3,
		{
			{
				0x2D4,
				0x3D4,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D4,
				0x4D4,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D4,
				0x5D4,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D5,
		3,
		{
			{
				0x2D5,
				0x3D5,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D5,
				0x4D5,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D5,
				0x5D5,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D6,
		3,
		{
			{
				0x2D6,
				0x3D6,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D6,
				0x4D6,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D6,
				0x5D6,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D7,
		3,
		{
			{
				0x2D7,
				0x3D7,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D7,
				0x4D7,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D7,
				0x5D7,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D8,
		3,
		{
			{
				0x2D8,
				0x3D8,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D8,
				0x4D8,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D8,
				0x5D8,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	},
	{
		0x2D9,
		3,
		{
			{
				0x2D9,
				0x3D9,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{5, 0},
					{10, 1},
					{11, 2},
					{12, 3},
					{13, 4},
					{14, 5},
					{15, 6},
					{16, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D9,
				0x4D9,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{18, 0},
					{19, 1},
					{22, 2},
					{23, 3},
					{34, 4},
					{39, 5},
					{40, 6},
					{41, 7}
				},
				CAN_LEN8_DLC
			},
			{
				0x2D9,
				0x5D9,
				DIRECTION_FD_TO_STANDARD,
				MSGTYPE_STANDARD_CAN,
				8,
				{
					{42, 0},
					{43, 1},
					{44, 2},
					{45, 3},
					{47, 4},
					{48, 5},
					{51, 6},
					{52, 7}
				},
				CAN_LEN8_DLC
			}
		}
	}
#endif
};
#endif
const Route_Map_One2One_t* IndexToOutputMsg(uint32_t uCan_id, uint8_t uDirection)
{
    uint8_t ulen;
    const Route_Map_One2One_t* ret = NULL;

    switch (uDirection)
    {
#if (FOR_MIFA_FVCM == ON)
        case DIRECTION_STANDAR_TO_FD:
            ulen = sizeof(map_table_one2one_CAN_2_CANFD)/sizeof(Route_Map_One2One_t);
            for (int i = 0; i < ulen; i++)
            {
                if (uCan_id == map_table_one2one_CAN_2_CANFD[i].id_in)
                {
                    ret = &(map_table_one2one_CAN_2_CANFD[i]);
                    break;
                }
            }
            break;

        case DIRECTION_FD_TO_STANDARD:
            ulen = sizeof(map_table_one2one_CANFD_2_CAN)/sizeof(Route_Map_One2One_t);
            for (int i = 0; i < ulen; i++)
            {
                if (uCan_id == map_table_one2one_CANFD_2_CAN[i].id_in)
                {
                    ret = &(map_table_one2one_CANFD_2_CAN[i]);
                    break;
                }
            }
            break;
#endif
		case DIRECTION_STANDAR_TO_STANDAR:
			ulen = sizeof(map_table_one2one_CAN_2_CAN)/sizeof(Route_Map_One2One_t);
            for (int i = 0; i < ulen; i++)
            {
                if (uCan_id == map_table_one2one_CAN_2_CAN[i].id_in)
                {
                    ret = &(map_table_one2one_CAN_2_CAN[i]);
                    break;
                }
            }
        default:
            break;
    }

    return ret;
}

void mapDataFromInToOutOne2One(CANRxMsgDMA_t* RxMsg, const Route_Map_One2One_t *map, Transfer_Direction_t direction)
{
	// reset id
	RxMsg->id = map->id_out;
	// reset message type
	RxMsg->msgtype = map->msg_type_out;
	// reset data length
	RxMsg->dlc = map->dlc_out;

	uint8_t tmp[8] = {0};
	// store data to temperary memory
	for (int i = 0; i < map->byte_count; i++)
	{
		tmp[i] = RxMsg->data8[map->byte_map[i][BYTE_IN]];
	}
	
	if ((direction == DIRECTION_STANDAR_TO_FD) || (direction == DIRECTION_STANDAR_TO_STANDAR))
	{
		// initialize data field of send frame
		memset(RxMsg->data8, 0x00, m_data_length_map[map->dlc_out]);
	}

    // frame data is byte based by default
    for (int i = 0; i < map->byte_count; i++)
    {
        RxMsg->data8[map->byte_map[i][BYTE_OUT]] = tmp[i];
    }

}

#if (FOR_MIFA_FVCM | FOR_SRR_BYTE)
const Route_Map_One2Multi_t* IsOne2MultiMsg(uint32_t uCan_id)
{
    const Route_Map_One2Multi_t* ret = NULL;
    for (int i = 0; i < sizeof(map_table_one2multi)/sizeof(Route_Map_One2Multi_t); i++)
    {
        if (map_table_one2multi[i].id_in == uCan_id)
        {
            ret =  &(map_table_one2multi[i]);
            break;
        }
    }

    return ret;
}
#endif


#if (FOR_SRR_BIT == ON)

bool set_message(
	struct srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_t *message_in, 
	struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_t *message_out_0, 
	struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_t *message_out_1,
	struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_t *message_out_2,
	struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_t *message_out_3
)
{
	if (!message_in)
		return FALSE;
	
	// frame - 0
	message_out_0->ui_id_obj_suffix_0 = message_in->ui_id_obj_suffix_0;
	message_out_0->ref_point_pos_obj_suffix_0 = message_in->ref_point_pos_obj_suffix_0;
	message_out_0->e_maintenance_state_obj_suffix_0 = message_in->e_maintenance_state_obj_suffix_0;
	message_out_0->ui_class_confidence_obj_suffix_0 = message_in->ui_class_confidence_obj_suffix_0;
	message_out_0->ref_point_pos_obj_suffix_1 = message_in->ref_point_pos_obj_suffix_1;
	message_out_0->f_vrel_y_obj_suffix_0 = message_in->f_vrel_y_obj_suffix_0;
	message_out_0->f_dist_y_obj_suffix_0 = message_in->f_dist_y_obj_suffix_0;
	message_out_0->ui_life_cycles_obj_suffix_0 = message_in->ui_life_cycles_obj_suffix_0;
	message_out_0->f_vrel_x_obj_suffix_0 = message_in->f_vrel_x_obj_suffix_0;
	message_out_0->e_dynamic_property_obj_suffix_0 = message_in->e_dynamic_property_obj_suffix_0;
	
	// frame - 1
	message_out_1->f_dist_x_obj_suffix_0 = message_in->f_dist_x_obj_suffix_0;
	message_out_1->f_orientation_obj_suffix_0 = message_in->f_orientation_obj_suffix_0;
	message_out_1->f_width_obj_suffix_0 = message_in->f_width_obj_suffix_0;
	message_out_1->f_length_obj_suffix_0 = message_in->f_length_obj_suffix_0;
	message_out_1->ui_probability_of_existence_obj_suffix_0 = message_in->ui_probability_of_existence_obj_suffix_0;
	message_out_1->ui_dyn_confidence_obj_suffix_0 = message_in->ui_dyn_confidence_obj_suffix_0;
	message_out_1->e_classification_obj_suffix_0 = message_in->e_classification_obj_suffix_0;
	message_out_1->ui_probability_of_existence_obj_suffix_1 = message_in->ui_probability_of_existence_obj_suffix_1;
	message_out_1->ui_id_obj_suffix_1 = message_in->ui_id_obj_suffix_1;

	// frame - 2
	message_out_2->f_vrel_y_obj_suffix_1 = message_in->f_vrel_y_obj_suffix_1;
	message_out_2->f_dist_y_obj_suffix_1 = message_in->f_dist_y_obj_suffix_1;
	message_out_2->f_vrel_x_obj_suffix_1 = message_in->f_vrel_x_obj_suffix_1;
	message_out_2->f_dist_x_obj_suffix_1 = message_in->f_dist_x_obj_suffix_1;
	message_out_2->f_width_obj_suffix_1 = message_in->f_width_obj_suffix_1;
	message_out_2->f_length_obj_suffix_1 = message_in->f_length_obj_suffix_1;

	// frame - 3
	message_out_3->f_rcs_obj_suffix_1 = message_in->f_rcs_obj_suffix_1;
	message_out_3->ui_class_confidence_obj_suffix_1 = message_in->ui_class_confidence_obj_suffix_1;
	message_out_3->e_classification_obj_suffix_1 = message_in->e_classification_obj_suffix_1;
	message_out_3->e_dynamic_property_obj_suffix_1 = message_in->e_dynamic_property_obj_suffix_1;
	message_out_3->ui_dyn_confidence_obj_suffix_1 = message_in->ui_dyn_confidence_obj_suffix_1;
	message_out_3->f_rcs_obj_suffix_0 = message_in->f_rcs_obj_suffix_0;
	message_out_3->e_maintenance_state_obj_suffix_1 = message_in->e_maintenance_state_obj_suffix_1;
	message_out_3->ui_life_cycles_obj_suffix_1 = message_in->ui_life_cycles_obj_suffix_1;
	message_out_3->f_orientation_obj_suffix_1 = message_in->f_orientation_obj_suffix_1;

	return TRUE;
}


void srr_canfd2can_route_by_signals(CANRxMsgDMA_t* RxMsg, CANHandle_t  hBusOut)
{
	bool ret = FALSE;
	uint32_t uCanid = RxMsg->id; // record original can id

	// find can id in the id list
	for (int i = 0; i < sizeof(srr_can_ids)/sizeof(srr_can_ids[0]); i++)
	{
		if (srr_can_ids[i] == RxMsg->id)
		{
			ret = TRUE;
			break;
		}
	}

	if (ret) // the can frame need to route
	{
		// unpack CANFD frame
		struct srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_t message_in;
		ret = srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_unpack(&message_in, RxMsg->data8, m_data_length_map[RxMsg->dlc]);
		if (ret)
		{
			// initialize sub classical CAN frames
			struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_t message_out_0;
			struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_t message_out_1;
			struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_t message_out_2;
			struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_t message_out_3;
			
			// use CANFD frame to set classical frmaes 
			ret = set_message(&message_in, &message_out_0, &message_out_1, &message_out_2, &message_out_3);

			if (ret)
			{
				// set common attribution of the message 
				// reset message type
				RxMsg->msgtype = MSGTYPE_STANDARD_CAN;
				// reset data length
				RxMsg->dlc = CAN_LEN8_DLC;
				uint8_t data[8] = {0};
			
				// send first frame
				RxMsg->id = uCanid + 0x100u;
				srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_pack(data, &message_out_0, m_data_length_map[CAN_LEN8_DLC]);
				for (int i = 0; i < 8; i++)
				{
					RxMsg->data8[i] = data[i];
				}
				// forward message to CAN1 -> standard CAN 
				CAN_Write ( hBusOut, RxMsg );

				// send second frame
				RxMsg->id = uCanid + 0x200u;
				srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_pack(data, &message_out_1, m_data_length_map[CAN_LEN8_DLC]);
				for (int i = 0; i < 8; i++)
				{
					RxMsg->data8[i] = data[i];
				}
				// forward message to CAN1 -> standard CAN 
				CAN_Write ( hBusOut, RxMsg );

				// send third frame
				RxMsg->id = uCanid + 0x300u;
				srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_pack(data, &message_out_2, m_data_length_map[CAN_LEN8_DLC]);
				for (int i = 0; i < 8; i++)
				{
					RxMsg->data8[i] = data[i];
				}
				// forward message to CAN1 -> standard CAN 
				CAN_Write ( hBusOut, RxMsg );

				// send fourth frame
				RxMsg->id = uCanid + 0x400u;
				srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_pack(data, &message_out_3, m_data_length_map[CAN_LEN8_DLC]);
				for (int i = 0; i < 8; i++)
				{
					RxMsg->data8[i] = data[i];
				}
				// forward message to CAN1 -> standard CAN 
				CAN_Write ( hBusOut, RxMsg );
			}
			else
			{
				// report error : set unpacked message failed
				RxMsg->id = 0x7FF;
				RxMsg->data8[0] = 0xFE;
				RxMsg->data8[1] = 0x01; // set unpacked message failed
				RxMsg->data8[2] = RxMsg->msgtype; // message type   0x0: Classic CAN  0x30: CANFD  
				RxMsg->data8[3] = m_data_length_map[RxMsg->dlc]; // DLC
				CAN_Write ( CAN_BUS1, RxMsg );
			}
		}
		else
		{
			// report error : unpack CANFD message failed
			RxMsg->id = 0x7FF;
			RxMsg->data8[0] = 0xFE;
			RxMsg->data8[1] = 0x02; // unpack CANFD message failed
			RxMsg->data8[2] = RxMsg->msgtype; // message type   0x0: Classic CAN  0x30: CANFD
			RxMsg->data8[3] = m_data_length_map[RxMsg->dlc]; // DLC
			
			CAN_Write ( hBusOut, RxMsg );
		}
	}
}
#endif