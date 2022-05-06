
#ifndef SRR520_YG11_V05_OUT_H
#define SRR520_YG11_V05_OUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils.h"

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_0_FRAME_ID (0x3c6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_1_FRAME_ID (0x4c6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_2_FRAME_ID (0x5c6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_3_FRAME_ID (0x6c6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_0_FRAME_ID (0x3c7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_1_FRAME_ID (0x4c7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_2_FRAME_ID (0x5c7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_3_FRAME_ID (0x6c7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_0_FRAME_ID (0x3c8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_1_FRAME_ID (0x4c8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_2_FRAME_ID (0x5c8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_3_FRAME_ID (0x6c8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_0_FRAME_ID (0x3c9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_1_FRAME_ID (0x4c9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_2_FRAME_ID (0x5c9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_3_FRAME_ID (0x6c9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_0_FRAME_ID (0x3cau)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_1_FRAME_ID (0x4cau)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_2_FRAME_ID (0x5cau)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_3_FRAME_ID (0x6cau)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_0_FRAME_ID (0x3cbu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_1_FRAME_ID (0x4cbu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_2_FRAME_ID (0x5cbu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_3_FRAME_ID (0x6cbu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_0_FRAME_ID (0x3ccu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_1_FRAME_ID (0x4ccu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_2_FRAME_ID (0x5ccu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_3_FRAME_ID (0x6ccu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_0_FRAME_ID (0x3cdu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_1_FRAME_ID (0x4cdu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_2_FRAME_ID (0x5cdu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_3_FRAME_ID (0x6cdu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_0_FRAME_ID (0x3ceu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_1_FRAME_ID (0x4ceu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_2_FRAME_ID (0x5ceu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_3_FRAME_ID (0x6ceu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_0_FRAME_ID (0x3cfu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_1_FRAME_ID (0x4cfu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_2_FRAME_ID (0x5cfu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_3_FRAME_ID (0x6cfu)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_0_FRAME_ID (0x3d0u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_1_FRAME_ID (0x4d0u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_2_FRAME_ID (0x5d0u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_3_FRAME_ID (0x6d0u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_0_FRAME_ID (0x3d1u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_1_FRAME_ID (0x4d1u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_2_FRAME_ID (0x5d1u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_3_FRAME_ID (0x6d1u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_0_FRAME_ID (0x3d2u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_1_FRAME_ID (0x4d2u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_2_FRAME_ID (0x5d2u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_3_FRAME_ID (0x6d2u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_0_FRAME_ID (0x3d3u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_1_FRAME_ID (0x4d3u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_2_FRAME_ID (0x5d3u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_3_FRAME_ID (0x6d3u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_0_FRAME_ID (0x3d4u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_1_FRAME_ID (0x4d4u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_2_FRAME_ID (0x5d4u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_3_FRAME_ID (0x6d4u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_0_FRAME_ID (0x3d5u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_1_FRAME_ID (0x4d5u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_2_FRAME_ID (0x5d5u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_3_FRAME_ID (0x6d5u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_0_FRAME_ID (0x3d6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_1_FRAME_ID (0x4d6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_2_FRAME_ID (0x5d6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_3_FRAME_ID (0x6d6u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_0_FRAME_ID (0x3d7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_1_FRAME_ID (0x4d7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_2_FRAME_ID (0x5d7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_3_FRAME_ID (0x6d7u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_0_FRAME_ID (0x3d8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_1_FRAME_ID (0x4d8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_2_FRAME_ID (0x5d8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_3_FRAME_ID (0x6d8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_0_FRAME_ID (0x3d9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_1_FRAME_ID (0x4d9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_2_FRAME_ID (0x5d9u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_3_FRAME_ID (0x6d9u)

/* Frame lengths in bytes. */
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_00_01_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_02_03_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_04_05_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_06_07_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_08_09_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_10_11_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_12_13_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_14_15_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_16_17_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_18_19_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_20_21_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_22_23_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_24_25_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_26_27_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_28_29_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_30_31_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_32_33_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_34_35_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_36_37_3_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_0_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_1_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_2_LENGTH (8u)
#define SRR520_YG11_V05_OUT_SRR_OBJ_38_39_3_LENGTH (8u)


/**
 * Signals in message SRR_OBJ_suffix_0_suffix_1_0.
 *
 * All signal values are as on the CAN bus.
 */
struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_t {
    /**
     * Range: 0..62 (0..62 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_id_obj_suffix_0;

    /**
     * Range: 0..3 (0..3 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ref_point_pos_obj_suffix_0;

    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_maintenance_state_obj_suffix_0;

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
    uint8_t ref_point_pos_obj_suffix_1;

    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_y_obj_suffix_0;

    /**
     * Range: 0..8190 (-255.9375..255.9375 m)
     * Scale: 0.0625
     * Offset: -255.9375
     */
    uint16_t f_dist_y_obj_suffix_0;

    /**
     * Range: 0..127 (0..127 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_life_cycles_obj_suffix_0;

    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_x_obj_suffix_0;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_dynamic_property_obj_suffix_0;
};

/**
 * Signals in message SRR_OBJ_suffix_0_suffix_1_1.
 *
 * All signal values are as on the CAN bus.
 */
struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_t {
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
    uint8_t ui_probability_of_existence_obj_suffix_1;

    /**
     * Range: 0..62 (0..62 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_id_obj_suffix_1;
};

/**
 * Signals in message SRR_OBJ_suffix_0_suffix_1_2.
 *
 * All signal values are as on the CAN bus.
 */
struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_t {
    /**
     * Range: 0..2047 (-128..127.875 m/s)
     * Scale: 0.125
     * Offset: -128
     */
    uint16_t f_vrel_y_obj_suffix_1;

    /**
     * Range: 0..8190 (-255.9375..255.9375 m)
     * Scale: 0.0625
     * Offset: -255.9375
     */
    uint16_t f_dist_y_obj_suffix_1;

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
    uint16_t f_dist_x_obj_suffix_1;

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
};

/**
 * Signals in message SRR_OBJ_suffix_0_suffix_1_3.
 *
 * All signal values are as on the CAN bus.
 */
struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_t {
    /**
     * Range: 0..2000 (-100..100 dBm)
     * Scale: 0.1
     * Offset: -100
     */
    uint16_t f_rcs_obj_suffix_1;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_class_confidence_obj_suffix_1;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_classification_obj_suffix_1;

    /**
     * Range: 0..15 (0..15 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_dynamic_property_obj_suffix_1;

    /**
     * Range: 0..5 (0..5 %)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_dyn_confidence_obj_suffix_1;

    /**
     * Range: 0..7 (0..7 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t e_maintenance_state_obj_suffix_1;

    /**
     * Range: 0..630 (-3.15..3.15 rad)
     * Scale: 0.01
     * Offset: -3.15
     */
    uint16_t f_orientation_obj_suffix_1;

    /**
     * Range: 0..2000 (-100..100 dBm)
     * Scale: 0.1
     * Offset: -100
     */
    uint16_t f_rcs_obj_suffix_0;

    /**
     * Range: 0..127 (0..127 -)
     * Scale: 1
     * Offset: 0
     */
    uint8_t ui_life_cycles_obj_suffix_1;
};

/**
 * Pack message SRR_OBJ_suffix_0_suffix_1_0.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_0_t *src_p,
    size_t size);


/**
 * Pack message SRR_OBJ_suffix_0_suffix_1_1.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_1_t *src_p,
    size_t size);


/**
 * Pack message SRR_OBJ_suffix_0_suffix_1_2.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_2_t *src_p,
    size_t size);


/**
 * Pack message SRR_OBJ_suffix_0_suffix_1_3.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_pack(
    uint8_t *dst_p,
    const struct srr520_yg11_v05_out_srr_obj_suffix_0_suffix_1_3_t *src_p,
    size_t size);

#ifdef __cplusplus
}
#endif

#endif
