
#include "srr520_yg11_v05_out.h"


int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->ui_id_obj_suffix_0, 2u, 0xfcu);
    dst_p[0] |= pack_left_shift_u8(src_p->ref_point_pos_obj_suffix_0, 0u, 0x03u);
    dst_p[1] |= pack_left_shift_u8(src_p->e_maintenance_state_obj_suffix_0, 5u, 0xe0u);
    dst_p[1] |= pack_left_shift_u8(src_p->ui_class_confidence_obj_suffix_0, 2u, 0x1cu);
    dst_p[1] |= pack_left_shift_u8(src_p->ref_point_pos_obj_suffix_1, 0u, 0x03u);
    dst_p[2] |= pack_right_shift_u16(src_p->f_vrel_y_obj_suffix_0, 3u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->f_vrel_y_obj_suffix_0, 5u, 0xe0u);
    dst_p[3] |= pack_right_shift_u16(src_p->f_dist_y_obj_suffix_0, 8u, 0x1fu);
    dst_p[4] |= pack_left_shift_u16(src_p->f_dist_y_obj_suffix_0, 0u, 0xffu);
    dst_p[5] |= pack_left_shift_u8(src_p->ui_life_cycles_obj_suffix_0, 1u, 0xfeu);
    dst_p[6] |= pack_right_shift_u16(src_p->f_vrel_x_obj_suffix_0, 3u, 0xffu);
    dst_p[7] |= pack_left_shift_u16(src_p->f_vrel_x_obj_suffix_0, 5u, 0xe0u);
    dst_p[7] |= pack_left_shift_u8(src_p->e_dynamic_property_obj_suffix_0, 1u, 0x1eu);

    return (8);
}


int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->f_dist_x_obj_suffix_0, 5u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->f_dist_x_obj_suffix_0, 3u, 0xf8u);
    dst_p[1] |= pack_right_shift_u16(src_p->f_orientation_obj_suffix_0, 7u, 0x07u);
    dst_p[2] |= pack_left_shift_u16(src_p->f_orientation_obj_suffix_0, 1u, 0xfeu);
    dst_p[3] |= pack_left_shift_u8(src_p->f_width_obj_suffix_0, 1u, 0xfeu);
    dst_p[4] |= pack_left_shift_u8(src_p->f_length_obj_suffix_0, 0u, 0xffu);
    dst_p[5] |= pack_left_shift_u8(src_p->ui_probability_of_existence_obj_suffix_0, 5u, 0xe0u);
    dst_p[5] |= pack_left_shift_u8(src_p->ui_dyn_confidence_obj_suffix_0, 2u, 0x1cu);
    dst_p[6] |= pack_left_shift_u8(src_p->e_classification_obj_suffix_0, 4u, 0xf0u);
    dst_p[6] |= pack_left_shift_u8(src_p->ui_probability_of_existence_obj_suffix_1, 1u, 0x0eu);
    dst_p[7] |= pack_left_shift_u8(src_p->ui_id_obj_suffix_1, 2u, 0xfcu);

    return (8);
}


int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->f_vrel_y_obj_suffix_1, 3u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->f_vrel_y_obj_suffix_1, 5u, 0xe0u);
    dst_p[1] |= pack_right_shift_u16(src_p->f_dist_y_obj_suffix_1, 8u, 0x1fu);
    dst_p[2] |= pack_left_shift_u16(src_p->f_dist_y_obj_suffix_1, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->f_vrel_x_obj_suffix_1, 3u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->f_vrel_x_obj_suffix_1, 5u, 0xe0u);
    dst_p[4] |= pack_right_shift_u16(src_p->f_dist_x_obj_suffix_1, 8u, 0x1fu);
    dst_p[5] |= pack_left_shift_u16(src_p->f_dist_x_obj_suffix_1, 0u, 0xffu);
    dst_p[6] |= pack_left_shift_u8(src_p->f_width_obj_suffix_1, 1u, 0xfeu);
    dst_p[7] |= pack_left_shift_u8(src_p->f_length_obj_suffix_1, 0u, 0xffu);

    return (8);
}

int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->f_rcs_obj_suffix_1, 3u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->f_rcs_obj_suffix_1, 5u, 0xe0u);
    dst_p[1] |= pack_left_shift_u8(src_p->ui_class_confidence_obj_suffix_1, 2u, 0x1cu);
    dst_p[2] |= pack_left_shift_u8(src_p->e_classification_obj_suffix_1, 4u, 0xf0u);
    dst_p[2] |= pack_left_shift_u8(src_p->e_dynamic_property_obj_suffix_1, 0u, 0x0fu);
    dst_p[3] |= pack_left_shift_u8(src_p->ui_dyn_confidence_obj_suffix_1, 5u, 0xe0u);
    dst_p[3] |= pack_left_shift_u8(src_p->e_maintenance_state_obj_suffix_1, 2u, 0x1cu);
    dst_p[4] |= pack_right_shift_u16(src_p->f_orientation_obj_suffix_1, 2u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->f_orientation_obj_suffix_1, 6u, 0xc0u);
    dst_p[5] |= pack_right_shift_u16(src_p->f_rcs_obj_suffix_0, 5u, 0x3fu);
    dst_p[6] |= pack_left_shift_u16(src_p->f_rcs_obj_suffix_0, 3u, 0xf8u);
    dst_p[6] |= pack_right_shift_u8(src_p->ui_life_cycles_obj_suffix_1, 4u, 0x07u);
    dst_p[7] |= pack_left_shift_u8(src_p->ui_life_cycles_obj_suffix_1, 4u, 0xf0u);

    return (8);
}