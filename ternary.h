#ifndef __ternary_h__
#define __ternary_h__

#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<errno.h>

//aliasing ternary types
#define trit8_t uint16_t
#define trit16_t uint32_t
#define trit32_t uint64_t


//UTILITY
uint64_t raised_to(uint64_t base, uint64_t exponent);

// CONVERSION

// BINARY TO UNBALANCED TERNARY
trit8_t binary_to_unbalanced_ternary_trit8_t(uint16_t num);
trit16_t binary_to_unbalanced_ternary_trit16_t(uint32_t num);
trit32_t binary_to_unbalanced_ternary_trit32_t(uint64_t num);

// BINARY TO BALANCED TERNARY
trit8_t binary_to_balanced_ternary_trit8_t(uint16_t num);
trit16_t binary_to_balanced_ternary_trit16_t(uint32_t num);
trit32_t binary_to_balanced_ternary_trit32_t(uint64_t num);

// UNBALANCED TERNARY TO BALANCED TERNARY
trit8_t unbalanced_ternary_to_balanced_ternary_trit8_t(trit8_t num);
trit16_t unbalanced_ternary_to_balanced_ternary_trit16_t(trit16_t num);
trit32_t unbalanced_ternary_to_balanced_ternary_trit32_t(trit32_t num);

// UNBALANCED TERNARY TO BINARY
uint16_t unbalanced_ternary_to_binary_uint16_t(trit8_t num);
uint32_t unbalanced_ternary_to_binary_uint32_t(trit16_t num);
uint64_t unbalanced_ternary_to_binary_uint64_t(trit32_t num);

// BALANCED TERNARY TO UNBALANCED TERNARY
trit8_t balanced_ternary_to_unbalanced_ternary_trit8_t(trit8_t num);
trit16_t balanced_ternary_to_unbalanced_ternary_trit16_t(trit16_t num);
trit32_t balanced_ternary_to_unbalanced_ternary_trit32_t(trit32_t num);

// BALANCED TERNARY TO BINARY
int16_t balanced_ternary_to_binary_int16_t(trit8_t num);
int32_t balanced_ternary_to_binary_int32_t(trit16_t num);
int64_t balanced_ternary_to_binary_int64_t(trit32_t num);

// ADDING FUNCTIONS
trit8_t trit_add_trit8_t(trit8_t a, trit8_t b);
trit16_t trit_add_trit16_t(trit16_t a, trit16_t b);
trit32_t trit_add_trit32_t(trit32_t a, trit32_t b);

// SUBTRACTING FUNCTIONS
trit8_t trit_sub_trit8_t(trit8_t a, trit8_t b);
trit16_t trit_sub_trit16_t(trit16_t a, trit16_t b);
trit32_t trit_sub_trit32_t(trit32_t a, trit32_t b);

// OR FUNCTIONS
trit8_t trit_or_trit8_t(trit8_t a, trit8_t b);
trit16_t trit_or_trit16_t(trit16_t a, trit16_t b);
trit32_t trit_or_trit32_t(trit32_t a, trit32_t b);

// XOR FUNCTIONS
trit8_t trit_xor_trit8_t(trit8_t a, trit8_t b);
trit16_t trit_xor_trit16_t(trit16_t a, trit16_t b);
trit32_t trit_xor_trit32_t(trit32_t a, trit32_t b);

// AND FUNCTIONS
trit8_t trit_and_trit8_t(trit8_t a, trit8_t b);
trit16_t trit_and_trit16_t(trit16_t a, trit16_t b);
trit32_t trit_and_trit32_t(trit32_t a, trit32_t b);

// SHIFT LEFT FUNCTIONS
trit8_t trit_sl_trit8_t(trit8_t a, uint8_t b);
trit16_t trit_sl_trit16_t(trit16_t a, uint8_t b);
trit32_t trit_sl_trit32_t(trit32_t a, uint8_t b);

// SHIFT RIGHT FUNCTIONS
trit8_t trit_sr_trit8_t(trit8_t a, uint8_t b);
trit16_t trit_sr_trit16_t(trit16_t a, uint8_t b);
trit32_t trit_sr_trit32_t(trit32_t a, uint8_t b);

// NOT FUNCTIONS
trit8_t trit_not_trit8_t(trit8_t num);
trit16_t trit_not_trit16_t(trit16_t num);
trit32_t trit_not_trit32_t(trit32_t num);

#endif // __ternary_h__