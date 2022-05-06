#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define TRUE    (1)
#define FALSE   (0)




#define  pack_left_shift_u8(value, shift, mask)   (uint8_t)((uint8_t)(value << shift) & mask)

#define  pack_left_shift_u16(value, shift, mask)  (uint8_t)((uint8_t)(value << shift) & mask)

#define  pack_right_shift_u8(value, shift, mask)  (uint8_t)((uint8_t)(value >> shift) & mask)

#define  pack_right_shift_u16(value, shift, mask) (uint8_t)((uint8_t)(value >> shift) & mask)

#define  unpack_left_shift_u8(value, shift, mask)  (uint8_t)((uint8_t)(value & mask) << shift)


#define  unpack_left_shift_u16(value, shift, mask)   (uint16_t)((uint16_t)(value & mask) << shift)


#define  unpack_right_shift_u8(value, shift, mask)    (uint8_t)((uint8_t)(value & mask) >> shift)


#define  unpack_right_shift_u16(value, shift, mask)  (uint16_t)((uint16_t)(value & mask) >> shift)

#endif