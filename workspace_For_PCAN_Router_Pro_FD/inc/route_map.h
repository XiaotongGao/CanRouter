#ifndef _ROUTE_MAP_
#define _ROUTE_MAP_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "can.h"
#include "can_user.h"
#include "project_switch.h"

#if (FOR_SRR_BIT == ON)
#include "srr520_yg11_v05_in.h"
#include "srr520_yg11_v05_out.h"
#endif

// Routing configuration
#define DIRECTION_STANDAR_TO_STANDAR   0
#define DIRECTION_STANDAR_TO_FD        1
#define DIRECTION_FD_TO_STANDARD       2
#define MSGTYPE_FD_CAN                 (CAN_MSGTYPE_FDF | CAN_MSGTYPE_BRS)
#define MSGTYPE_STANDARD_CAN           CAN_MSGTYPE_STANDARD
#define MSGTYPE_EXTENDED_CAN           CAN_MSGTYPE_EXTENDED
#define BYTE_IN                        0
#define BYTE_OUT                       1

typedef struct Route_Map_One2One {
    uint32_t  id_in; // CAN id in
    uint32_t  id_out; // CAN id out
    uint8_t   direction; // routing direction
    uint16_t  msg_type_out; // message type
    uint8_t   byte_count; // specific byte count of frame 
    uint8_t   byte_map[8][2]; // byte index mapping
    uint8_t   dlc_out; // data length of sent message
} Route_Map_One2One_t;

typedef struct Route_Map_One2Multi { // for CANFD
    uint32_t  id_in; // CAN id in
    uint8_t split_count;
    Route_Map_One2One_t sub_map[8];
} Route_Map_One2Multi_t;

typedef char Transfer_Direction_t;


extern uint8_t m_data_length_map[16];

const Route_Map_One2One_t map_table_one2one_CAN_2_CAN[3];

#if (FOR_MIFA_FVCM == ON)
extern const Route_Map_One2One_t map_table_one2one_CAN_2_CANFD[19];

extern const Route_Map_One2One_t map_table_one2one_CANFD_2_CAN[43];

extern const Route_Map_One2Multi_t map_table_one2multi[2];
#endif

#if (FOR_SRR_BYTE == ON)
extern const Route_Map_One2Multi_t map_table_one2multi[20];
#elif (FOR_SRR_BIT == ON)
extern const uint32_t srr_can_ids[20];
void srr_canfd2can_route_by_signals(CANRxMsgDMA_t* RxMsg, CANHandle_t  hBusOut);
bool set_message(struct srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_t *message_in, 
            struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_t *message_out_0, 
            struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_t *message_out_1,
			struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_t *message_out_2,
            struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_t *message_out_3);
#endif

#if (FOR_MIFA_FVCM | FOR_SRR_BYTE)
const Route_Map_One2Multi_t* IsOne2MultiMsg(uint32_t uCan_id);
#endif

const Route_Map_One2One_t* IndexToOutputMsg(uint32_t uCan_id, uint8_t uDirection);

void mapDataFromInToOutOne2One(CANRxMsgDMA_t* RxMsg, const Route_Map_One2One_t *map, Transfer_Direction_t direction);

#endif