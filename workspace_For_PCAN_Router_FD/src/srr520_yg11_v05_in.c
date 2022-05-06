
#include "srr520_yg11_v05_in.h"


int srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_unpack(
    struct srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 64u) {
        return FALSE;
    }

    dst_p->ui_id_obj_suffix_0 = unpack_right_shift_u8(src_p[5], 2u, 0xfcu);
    dst_p->e_maintenance_state_obj_suffix_0 = unpack_right_shift_u8(src_p[6], 5u, 0xe0u);
    dst_p->f_vrel_y_obj_suffix_0 = unpack_left_shift_u16(src_p[10], 10u, 0x01u);
    dst_p->f_vrel_y_obj_suffix_0 |= unpack_left_shift_u16(src_p[11], 2u, 0xffu);
    dst_p->f_vrel_y_obj_suffix_0 |= unpack_right_shift_u16(src_p[12], 6u, 0xc0u);
    dst_p->f_vrel_x_obj_suffix_0 = unpack_left_shift_u16(src_p[13], 3u, 0xffu);
    dst_p->f_vrel_x_obj_suffix_0 |= unpack_right_shift_u16(src_p[14], 5u, 0xe0u);
    dst_p->f_dist_y_obj_suffix_0 = unpack_left_shift_u16(src_p[15], 8u, 0x1fu);
    dst_p->f_dist_y_obj_suffix_0 |= unpack_right_shift_u16(src_p[16], 0u, 0xffu);
    dst_p->f_dist_x_obj_suffix_0 = unpack_left_shift_u16(src_p[18], 5u, 0xffu);
    dst_p->f_dist_x_obj_suffix_0 |= unpack_right_shift_u16(src_p[19], 3u, 0xf8u);
    dst_p->f_orientation_obj_suffix_0 = unpack_left_shift_u16(src_p[19], 7u, 0x07u);
    dst_p->f_orientation_obj_suffix_0 |= unpack_right_shift_u16(src_p[20], 1u, 0xfeu);
    dst_p->f_width_obj_suffix_0 = unpack_left_shift_u8(src_p[20], 6u, 0x01u);
    dst_p->f_width_obj_suffix_0 |= unpack_right_shift_u8(src_p[21], 2u, 0xfcu);
    dst_p->f_length_obj_suffix_0 = unpack_left_shift_u8(src_p[21], 6u, 0x03u);
    dst_p->f_length_obj_suffix_0 |= unpack_right_shift_u8(src_p[22], 2u, 0xfcu);
    dst_p->ui_probability_of_existence_obj_suffix_0 = unpack_left_shift_u8(src_p[22], 1u, 0x03u);
    dst_p->ui_probability_of_existence_obj_suffix_0 |= unpack_right_shift_u8(src_p[23], 7u, 0x80u);
    dst_p->ui_dyn_confidence_obj_suffix_0 = unpack_right_shift_u8(src_p[23], 4u, 0x70u);
    dst_p->f_rcs_obj_suffix_0 = unpack_left_shift_u16(src_p[23], 10u, 0x01u);
    dst_p->f_rcs_obj_suffix_0 |= unpack_left_shift_u16(src_p[24], 2u, 0xffu);
    dst_p->f_rcs_obj_suffix_0 |= unpack_right_shift_u16(src_p[25], 6u, 0xc0u);
    dst_p->e_classification_obj_suffix_0 = unpack_left_shift_u8(src_p[26], 2u, 0x03u);
    dst_p->e_classification_obj_suffix_0 |= unpack_right_shift_u8(src_p[27], 6u, 0xc0u);
    dst_p->ui_class_confidence_obj_suffix_0 = unpack_right_shift_u8(src_p[27], 3u, 0x38u);
    dst_p->ref_point_pos_obj_suffix_0 = unpack_left_shift_u8(src_p[30], 1u, 0x01u);
    dst_p->ref_point_pos_obj_suffix_0 |= unpack_right_shift_u8(src_p[31], 7u, 0x80u);
    dst_p->ui_life_cycles_obj_suffix_0 = unpack_right_shift_u8(src_p[31], 0u, 0x7fu);
    dst_p->e_dynamic_property_obj_suffix_0 = unpack_right_shift_u8(src_p[33], 1u, 0x1eu);
    dst_p->ui_id_obj_suffix_1 = unpack_right_shift_u8(src_p[34], 2u, 0xfcu);
    dst_p->e_maintenance_state_obj_suffix_1 = unpack_right_shift_u8(src_p[35], 5u, 0xe0u);
    dst_p->f_vrel_y_obj_suffix_1 = unpack_left_shift_u16(src_p[39], 10u, 0x01u);
    dst_p->f_vrel_y_obj_suffix_1 |= unpack_left_shift_u16(src_p[40], 2u, 0xffu);
    dst_p->f_vrel_y_obj_suffix_1 |= unpack_right_shift_u16(src_p[41], 6u, 0xc0u);
    dst_p->f_vrel_x_obj_suffix_1 = unpack_left_shift_u16(src_p[42], 3u, 0xffu);
    dst_p->f_vrel_x_obj_suffix_1 |= unpack_right_shift_u16(src_p[43], 5u, 0xe0u);
    dst_p->f_dist_y_obj_suffix_1 = unpack_left_shift_u16(src_p[44], 8u, 0x1fu);
    dst_p->f_dist_y_obj_suffix_1 |= unpack_right_shift_u16(src_p[45], 0u, 0xffu);
    dst_p->f_dist_x_obj_suffix_1 = unpack_left_shift_u16(src_p[47], 5u, 0xffu);
    dst_p->f_dist_x_obj_suffix_1 |= unpack_right_shift_u16(src_p[48], 3u, 0xf8u);
    dst_p->f_orientation_obj_suffix_1 = unpack_left_shift_u16(src_p[48], 7u, 0x07u);
    dst_p->f_orientation_obj_suffix_1 |= unpack_right_shift_u16(src_p[49], 1u, 0xfeu);
    dst_p->f_width_obj_suffix_1 = unpack_left_shift_u8(src_p[49], 6u, 0x01u);
    dst_p->f_width_obj_suffix_1 |= unpack_right_shift_u8(src_p[50], 2u, 0xfcu);
    dst_p->f_length_obj_suffix_1 = unpack_left_shift_u8(src_p[50], 6u, 0x03u);
    dst_p->f_length_obj_suffix_1 |= unpack_right_shift_u8(src_p[51], 2u, 0xfcu);
    dst_p->ui_probability_of_existence_obj_suffix_1 = unpack_left_shift_u8(src_p[51], 1u, 0x03u);
    dst_p->ui_probability_of_existence_obj_suffix_1 |= unpack_right_shift_u8(src_p[52], 7u, 0x80u);
    dst_p->ui_dyn_confidence_obj_suffix_1 = unpack_right_shift_u8(src_p[52], 4u, 0x70u);
    dst_p->f_rcs_obj_suffix_1 = unpack_left_shift_u16(src_p[52], 10u, 0x01u);
    dst_p->f_rcs_obj_suffix_1 |= unpack_left_shift_u16(src_p[53], 2u, 0xffu);
    dst_p->f_rcs_obj_suffix_1 |= unpack_right_shift_u16(src_p[54], 6u, 0xc0u);
    dst_p->e_classification_obj_suffix_1 = unpack_left_shift_u8(src_p[55], 2u, 0x03u);
    dst_p->e_classification_obj_suffix_1 |= unpack_right_shift_u8(src_p[56], 6u, 0xc0u);
    dst_p->ui_class_confidence_obj_suffix_1 = unpack_right_shift_u8(src_p[56], 3u, 0x38u);
    dst_p->ref_point_pos_obj_suffix_1 = unpack_left_shift_u8(src_p[59], 1u, 0x01u);
    dst_p->ref_point_pos_obj_suffix_1 |= unpack_right_shift_u8(src_p[60], 7u, 0x80u);
    dst_p->ui_life_cycles_obj_suffix_1 = unpack_right_shift_u8(src_p[60], 0u, 0x7fu);
    dst_p->e_dynamic_property_obj_suffix_1 = unpack_right_shift_u8(src_p[62], 1u, 0x1eu);

    return TRUE;
}

