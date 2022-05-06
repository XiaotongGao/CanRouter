
#ifndef SRR520_YG11_V05_IN_H
#define SRR520_YG11_V05_IN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils.h"

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define SRR520_YG11_V05_IN_SRR_OBJ_00_01_FRAME_ID (0x2c6u)
#define SRR520_YG11_V05_IN_SRR_OBJ_02_03_FRAME_ID (0x2c7u)
#define SRR520_YG11_V05_IN_SRR_OBJ_04_05_FRAME_ID (0x2c8u)
#define SRR520_YG11_V05_IN_SRR_OBJ_06_07_FRAME_ID (0x2c9u)
#define SRR520_YG11_V05_IN_SRR_OBJ_08_09_FRAME_ID (0x2cau)
#define SRR520_YG11_V05_IN_SRR_OBJ_10_11_FRAME_ID (0x2cbu)
#define SRR520_YG11_V05_IN_SRR_OBJ_12_13_FRAME_ID (0x2ccu)
#define SRR520_YG11_V05_IN_SRR_OBJ_14_15_FRAME_ID (0x2cdu)
#define SRR520_YG11_V05_IN_SRR_OBJ_16_17_FRAME_ID (0x2ceu)
#define SRR520_YG11_V05_IN_SRR_OBJ_18_19_FRAME_ID (0x2cfu)
#define SRR520_YG11_V05_IN_SRR_OBJ_20_21_FRAME_ID (0x2d0u)
#define SRR520_YG11_V05_IN_SRR_OBJ_22_23_FRAME_ID (0x2d1u)
#define SRR520_YG11_V05_IN_SRR_OBJ_24_25_FRAME_ID (0x2d2u)
#define SRR520_YG11_V05_IN_SRR_OBJ_26_27_FRAME_ID (0x2d3u)
#define SRR520_YG11_V05_IN_SRR_OBJ_28_29_FRAME_ID (0x2d4u)
#define SRR520_YG11_V05_IN_SRR_OBJ_30_31_FRAME_ID (0x2d5u)
#define SRR520_YG11_V05_IN_SRR_OBJ_32_33_FRAME_ID (0x2d6u)
#define SRR520_YG11_V05_IN_SRR_OBJ_34_35_FRAME_ID (0x2d7u)
#define SRR520_YG11_V05_IN_SRR_OBJ_36_37_FRAME_ID (0x2d8u)
#define SRR520_YG11_V05_IN_SRR_OBJ_38_39_FRAME_ID (0x2d9u)

/* Frame lengths in bytes. */
#define SRR520_YG11_V05_IN_SRR_OBJ_00_01_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_02_03_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_04_05_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_06_07_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_08_09_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_10_11_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_12_13_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_14_15_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_16_17_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_18_19_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_20_21_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_22_23_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_24_25_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_26_27_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_28_29_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_30_31_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_32_33_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_34_35_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_36_37_LENGTH (64u)
#define SRR520_YG11_V05_IN_SRR_OBJ_38_39_LENGTH (64u)


/**
 * Signals in message SRR_OBJ_suffix_0_suffix_1.
 *
 * All signal values are as on the CAN bus.
 */
struct srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_t {
    /**
     * Range: 0..62 (0..62 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_id_obj_suffix_0;

    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_maintenance_state_obj_suffix_0;

    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_y_obj_suffix_0;

    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_x_obj_suffix_0;

    /**
     * Range: 0..8190 (-255.9375..255.9375 m)
     * Scale: 0.0625
     * Offset: -255.9375
     */
    uint16_t f_dist_y_obj_suffix_0;

    /**
     * Range: 0..8190 (-255.9375..255.9375 m)
     * Scale: 0.0625
     * Offset: -255.9375
     */
    uint16_t f_dist_x_obj_suffix_0;

    /**
     * Range: 0..630 (-3.15..3.15 rad)
     * Scale: 0.01
     * Offset: -3.15
     */
    uint16_t f_orientation_obj_suffix_0;

    /**
     * Range: 0..75 (0..15 m)
     * Scale: 0.2
     * Offset: 0
     */
    uint8_t f_width_obj_suffix_0;

    /**
     * Range: 0..150 (0..30 m)
     * Scale: 0.2
     * Offset: 0
     */
    uint8_t f_length_obj_suffix_0;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_probability_of_existence_obj_suffix_0;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_dyn_confidence_obj_suffix_0;

    /**
     * Range: 0..2000 (-100..100 dBm)
     * Scale: 0.1
     * Offset: -100
     */
    uint16_t f_rcs_obj_suffix_0;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_classification_obj_suffix_0;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_class_confidence_obj_suffix_0;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ref_point_pos_obj_suffix_0;

    /**
     * Range: 0..127 (0..127 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_life_cycles_obj_suffix_0;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_dynamic_property_obj_suffix_0;

    /**
     * Range: 0..62 (0..62 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_id_obj_suffix_1;

    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_maintenance_state_obj_suffix_1;

    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_y_obj_suffix_1;

    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_x_obj_suffix_1;

    /**
     * Range: 0..8190 (-255.9375..255.9375 m)
     * Scale: 0.0625
     * Offset: -255.9375
     */
    uint16_t f_dist_y_obj_suffix_1;

    /**
     * Range: 0..8190 (-255.9375..255.9375 m)
     * Scale: 0.0625
     * Offset: -255.9375
     */
    uint16_t f_dist_x_obj_suffix_1;

    /**
     * Range: 0..630 (-3.15..3.15 rad)
     * Scale: 0.01
     * Offset: -3.15
     */
    uint16_t f_orientation_obj_suffix_1;

    /**
     * Range: 0..75 (0..15 m)
     * Scale: 0.2
     * Offset: 0
     */
    uint8_t f_width_obj_suffix_1;

    /**
     * Range: 0..150 (0..30 m)
     * Scale: 0.2
     * Offset: 0
     */
    uint8_t f_length_obj_suffix_1;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_probability_of_existence_obj_suffix_1;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_dyn_confidence_obj_suffix_1;

    /**
     * Range: 0..2000 (-100..100 dBm)
     * Scale: 0.1
     * Offset: -100
     */
    uint16_t f_rcs_obj_suffix_1;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_classification_obj_suffix_1;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_class_confidence_obj_suffix_1;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ref_point_pos_obj_suffix_1;

    /**
     * Range: 0..127 (0..127 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_life_cycles_obj_suffix_1;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_dynamic_property_obj_suffix_1;
};

/**
 * Unpack message SRR_OBJ_suffix_0_suffix_1.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_unpack(
    struct srr520_yg11_v05_in_srr_obj_suffix_0_suffix_1_t *dst_p,
    const uint8_t *src_p,
    size_t size);


#ifdef __cplusplus
}
#endif

#endif
