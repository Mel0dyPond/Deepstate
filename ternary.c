/**
 * @file ternary.c
 * @author Brooke Caldwell
 * @date 14 Oct 2020
 *
 * @breif File contains ternary manipulation methods.
 *
 * This file contains methods which can contvert 
 * numbers between binary, balanced ternary and 
 * unbalanced ternary. Also, contains balanced ternary 
 * manipulation functions for or, and, xor, not, add, as
 * well as subtract.
 */


#include"ternary.h"

uint64_t ZERO_64 = 0; /**< Defines a global variable for 0 that is an @c unint64_t */
uint64_t ONE_64 = 1; /**< Defines a global variable for 1 that is an @c unint64_t */
uint64_t TWO_64 = 2; /**< Defines a global variable for 2 that is an @c unint64_t */
uint64_t BAL_64 = 3; /**< Defines a global variable to represent -1 that is an @c unint64_t */

trit8_t ZERO_trit8 = 0; /**< Defines a global variable for 0 that is a @c trit8_t */
trit8_t ONE_trit8 = 1; /**< Defines a global variable for 1 that is a @c trit8_t */
trit8_t TWO_trit8 = 2; /**< Defines a global variable for 2 that is a @c trit8_t */
trit8_t BAL_trit8 = 3; /**< Defines a global variable to represent -1 that is a @c trit8_t */

trit16_t ZERO_trit16 = 0; /**< Defines a global variable for 0 that is a @c trit16_t */
trit16_t ONE_trit16 = 1; /**< Defines a global variable for 1 that is a @c trit16_t */
trit16_t TWO_trit16 = 2; /**< Defines a global variable for 2 that is a @c trit16_t */
trit16_t BAL_trit16 = 3; /**< Defines a global variable to represent -1 that is a @c trit16_t */

trit32_t ZERO_trit32 = 0; /**< Defines a global variable for 0 that is a @c trit32_t */
trit32_t ONE_trit32 = 1; /**< Defines a global variable for 1 that is a @c trit32_t */
trit32_t TWO_trit32 = 2; /**< Defines a global variable for 2 that is a @c trit32_t */
trit32_t BAL_trit32 = 3; /**< Defines a global variable to represent -1 that is a @c trit32_t */


/**
 * @brief Finds what @p base raised to @p exponent
 * 
 * This function will return the @p base multiplied by itself
 * the number of times @p exponent says.
 *
 * @param[in] base the number to be multiplied
 *
 * @param[in] exponent how many times base will be multiplied
 *
 * @return the result of base multiplied by the recursive call 
 * passed with base and exponent - 1
 */
uint64_t raised_to(uint64_t base, uint64_t exponent){
        
    if(exponent == 0){
           
        return 1;
    }
    return base * raised_to(base, exponent - 1);
}

 
/**
 * @brief Converts binary to unbalanced ternary for @c trit8_t.
 * 
 * Takes a @c uint16_t number and converts to @c trit8_t with an 
 * unbalaned ternary encoding.
 *
 * @warning This method asserts that the passed in binary 
 * number will fit into 8 trits.
 *
 * @param[in] num The binary number to 
 * be turned into unbalanced ternary.
 *
 * @return The final result of turning the binary 
 * number to unbalanced ternary.
 */
trit8_t binary_to_unbalanced_ternary_trit8_t(uint16_t num){
    
    int index = 0;
    trit8_t result = 0;
    int remainder_array[8] = {};       
  
    // store ternary encoding into array
    while(num > 0 && index < 8){
    
        remainder_array[index] = num % 3;
        num /= 3;
    
        index++;
    
    } 
    
    // Make sure num fit into 8 trits
    assert(num <= 0);
  
    // from array store encoding into result
    // starting at  last index to first
    for(index = 7; index >= 0; index--){
    
        if(remainder_array[index] == 2){
        
            result = result | TWO_trit8;
        }        
        else if(remainder_array[index] == 1){
        
            result = result | ONE_trit8;
        }
        else{
        
            result = result | ZERO_trit8;
        }
    
        if(index != 0){
        
            result = result << 2;
        }
    }
  
    return result;
}

/**
 * @brief Converts binary to unbalanced ternary for @c trit16_t.
 * 
 * Takes a @c uint32_t number and converts to @c trit16_t with an 
 * unbalaned ternary encoding.
 *
 * @warning This method asserts that the passed in binary 
 * number will fit into 16 trits.
 *
 * @param[in] num The binary number to 
 * be turned into unbalanced ternary.
 *
 * @return The final result of turning the binary 
 * number to unbalanced ternary.
 */
trit16_t binary_to_unbalanced_ternary_trit16_t(uint32_t num){
    
    int index = 0;
    trit16_t result = 0;
    int remainder_array[16] = {};       
  
    // store ternary encoding into array
    while(num > 0 && index < 16){
    
        remainder_array[index] = num % 3;
        num /= 3;
    
        index++;
    
    } 
    
    // Make sure num fit into 16 trits
    assert(num <= 0);
  
    // from array store encoding into result
    // starting at  last index to first
    for(index = 15; index >= 0; index--){
    
        if(remainder_array[index] == 2){
        
            result = result | TWO_trit16;
        }        
        else if(remainder_array[index] == 1){
        
            result = result | ONE_trit16;
        }
        else{
        
            result = result | ZERO_trit16;
        }
    
        if(index != 0){
        
            result = result << 2;
        }
    }
  
    return result;
}

/**
 * @brief Converts binary to unbalanced ternary for @c trit32_t.
 * 
 * Takes a @c uint64_t number and converts to @c trit32_t with an 
 * unbalaned ternary encoding.
 *
 * @warning This method asserts that the passed in binary 
 * number will fit into 32 trits.
 *
 * @param[in] num The binary number to 
 * be turned into unbalanced ternary.
 *
 * @return The final result of turning the binary 
 * number to unbalanced ternary.
 */
trit32_t binary_to_unbalanced_ternary_trit32_t( uint64_t num ){

    int index = 0;
    trit32_t result = 0;
    int remainder_array[32] = {};       
  
    // store ternary encoding into array
    while(num > 0 && index < 32){
    
        remainder_array[index] = num % 3;
        num /= 3;
    
        index++;
    
    } 
    
    // Make sure num fit into 32 trits 
    assert(num <= 0);
  
    // from array store encoding into result
    // starting at  last index to first
    for(index = 31; index >= 0; index--){
    
        if(remainder_array[index] == 2){
        
            result = result | TWO_trit32;
        }        
        else if(remainder_array[index] == 1){
        
            result = result | ONE_trit32;
        }
        else{
        
            result = result | ZERO_trit32;
        }
    
        if(index != 0){
        
            result = result << 2;
        }
    }
  
    return result;
}

/**
 * @brief Converts binary to balanced ternary for @c trit8_t.
 * 
 * Takes a @c uint16_t number and converts to @c trit8_t with an 
 * balaned ternary encoding.
 *
 * @warning This method asserts that the passed in binary 
 * number will fit into 8 trits.
 *
 * @param[in] num The binary number to 
 * be turned into balanced ternary.
 *
 * @return The final result of turning the binary 
 * number to balanced ternary.
 */
trit8_t binary_to_balanced_ternary_trit8_t(uint16_t num){
    
    int index = 0;
    int carry = 0;
    bool overflow = false; 
    int array[8] = {};
        
    trit8_t result = 0;
    
    while(num > 0 && index < 8){
    
        array[index] = num % 3;
        num /=3;
        index++;
    }
            
    assert(num <= 0 && "Passed in num is too big");
            
    for(index = 0; index < 8; index ++){
    
        if(array[index] == 3){
        
            carry = 1;
            array[index] = 0;
        }
        else if(array[index] == 2){
        
            carry = 1;
            array[index] = -1;
        }
        else{
        
            carry = 0;
        }
                    
        if(index + 1 < 8){
        
            array[index + 1] += carry;
            carry = 0;
        }
        
        else if(carry == 1){
        
            overflow = true;
        }
                
    }
            
    assert(overflow == false && "Number too big for ternary");
                
    for(index = 7; index >= 0; index--){
    
        if(array[index] == -1){
        
            result = result | BAL_trit8;
        }
        else if(array[index] == 1){
        
            result = result | ONE_trit8;
        }
        else{
        
            result = result | ZERO_trit8;
        }
    
        if(index != 0){   
        
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Converts binary to balanced ternary for @c trit16_t.
 * 
 * Takes a @c uint32_t number and converts to @c trit16_t with an 
 * balaned ternary encoding.
 *
 * @warning This method asserts that the passed in binary 
 * number will fit into 16 trits.
 *
 * @param[in] num The binary number to 
 * be turned into balanced ternary.
 *
 * @return The final result of turning the binary 
 * number to balanced ternary.
 */
trit16_t binary_to_balanced_ternary_trit16_t(uint32_t num){
    
    int index = 0;
    int carry = 0;
    bool overflow = false; 
    int array[16] = {};
        
    trit16_t result = 0;
    
    while(num > 0 && index < 16){
    
        array[index] = num % 3;
        num /=3;
        index++;
    }
            
    assert(num <= 0 && "Passed in num is too big");
            
    for(index = 0; index < 16; index ++){
    
        if(array[index] == 3){
        
            carry = 1;
            array[index] = 0;
        }
        else if(array[index] == 2){
        
            carry = 1;
            array[index] = -1;
        }
        else{
        
            carry = 0;
        }
                    
        if(index + 1 < 16){
        
            array[index + 1] += carry;
            carry = 0;
        }
        
        else if(carry == 1){
        
            overflow = true;
        }
                
    }
            
    assert(overflow == false && "Number too big for ternary");
                
    for(index = 15; index >= 0; index--){
    
        if(array[index] == -1){
        
            result = result | BAL_trit16;
        }
        else if(array[index] == 1){
        
            result = result | ONE_trit16;
        }
        else{
        
            result = result | ZERO_trit16;
        }
    
        if(index != 0){   
        
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Converts binary to balanced ternary for @c trit32_t.
 * 
 * Takes a @c uint64_t number and converts to @c trit32_t with an 
 * balaned ternary encoding.
 *
 * @warning This method asserts that the passed in binary 
 * number will fit into 32 trits.
 *
 * @param[in] num The binary number to 
 * be turned into balanced ternary.
 *
 * @return The final result of turning the binary 
 * number to balanced ternary.
 */
trit32_t binary_to_balanced_ternary_trit32_t( uint64_t num ){

    int index = 0;
    int carry = 0;
    bool overflow = false; 
    int array[32] = {};
        
    trit32_t result = 0;
    
    while(num > 0 && index < 32){
    
        array[index] = num % 3;
        num /=3;
        index++;
    }
            
    assert(num <= 0 && "Passed in num is too big");
            
    for(index = 0; index < 32; index ++){
    
        if(array[index] == 3){
        
            carry = 1;
            array[index] = 0;
        }
        else if(array[index] == 2){
        
            carry = 1;
            array[index] = -1;
        }
        else{
        
            carry = 0;
        }
                    
        if(index + 1 < 32){
        
            array[index + 1] += carry;
            carry = 0;
        }
        
        else if(carry == 1){
        
            overflow = true;
        }
                
    }
            
    assert(overflow == false && "Number too big for ternary");
                
    for(index = 31; index >= 0; index--){
    
        if(array[index] == -1){
        
            result = result | BAL_trit32;
        }
        else if(array[index] == 1){
        
            result = result | ONE_trit32;
        }
        else{
        
            result = result | ZERO_trit32;
        }
    
        if(index != 0){   
        
            result = result << 2;
        }
    }

    return result;
  
}

/**
 * @brief Converts unbalanced ternary to balanced ternary for @c trit8_t.
 * 
 * Takes a @c trit8_t number and converts to @c trit8_t with an 
 * balaned ternary encoding.
 *
 * @warning This method asserts that the passed in  
 * number will fit into 8 trits.
 *
 * @warning This method asserts that the passed in
 * number is encoded in unbalanced ternary.
 *
 * @param[in] num The unbalanced ternary number to 
 * be turned into balanced ternary.
 *
 * @return The final result of turning the unbalanced
 * ternary number to balanced ternary.
 */
trit8_t unbalanced_ternary_to_balanced_ternary_trit8_t(trit8_t num){
    
    trit8_t result = 0;
    uint8_t grab = 0;
    int array[8] = {};
    int index = 0;
    int carry = 0;
    bool overflow = false;
        
    for(index = 0; index < 8; index++){
    
        grab = num & 0b11;
                
        assert(grab != 0b11 && "Number already balanced");
                
        array[index] = grab;
                
        num = num >> 2;
    }
         
    for(index = 0; index < 8; index ++){
    
        if(array[index] == 3){
        
            carry = 1;
            array[index] = 0;
        }
        else if(array[index] == 2){
        
            carry = 1;
            array[index] = -1;
        }
        else{
        
            carry = 0;
        }
                    
        if(index + 1 < 8){
        
            array[index + 1] += carry;
        }
        
        else if(carry == 1){
        
            overflow = true;
        }
                
    }
            
    assert(overflow == false && "Number too big for ternary");
            
    for(index = 7; index >= 0; index--){
    
        if(array[index] == -1){
        
            result = result | BAL_trit8;
        }
        else if(array[index] == 1){
    
            result = result | ONE_trit8;
        }
        else{
    
            result = result | ZERO_trit8;
        }

        if(index != 0){
           
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Converts unbalanced ternary to balanced ternary for @c trit16_t.
 * 
 * Takes a @c trit16_t number and converts to @c trit16_t with an 
 * balaned ternary encoding.
 *
 * @warning This method asserts that the passed in  
 * number will fit into 16 trits.
 *
 * @warning This method asserts that the passed in
 * number is encoded in unbalanced ternary.
 *
 * @param[in] num The unbalanced ternary number to 
 * be turned into balanced ternary.
 *
 * @return The final result of turning the unbalanced
 * ternary number to balanced ternary.
 */
trit16_t unbalanced_ternary_to_balanced_ternary_trit16_t(trit16_t num){
    
    trit16_t result = 0;
    uint8_t grab = 0;
    int array[16] = {};
    int index = 0;
    int carry = 0;
    bool overflow = false;
        
    for(index = 0; index < 16; index++){
    
        grab = num & 0b11;
                
        assert(grab != 0b11 && "Number already balanced");
                
        array[index] = grab;
                
        num = num >> 2;
    }
         
    for(index = 0; index < 16; index ++){
    
        if(array[index] == 3){
        
            carry = 1;
            array[index] = 0;
        }
        else if(array[index] == 2){
        
            carry = 1;
            array[index] = -1;
        }
        else{
        
            carry = 0;
        }
                    
        if(index + 1 < 16){
        
            array[index + 1] += carry;
        }
        
        else if(carry == 1){
        
            overflow = true;
        }
                
    }
            
    assert(overflow == false && "Number too big for ternary");
            
    for(index = 15; index >= 0; index--){
    
        if(array[index] == -1){
        
            result = result | BAL_trit16;
        }
        else if(array[index] == 1){
    
            result = result | ONE_trit16;
        }
        else{
    
            result = result | ZERO_trit16;
        }

        if(index != 0){
           
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Converts unbalanced ternary to balanced ternary for @c trit32_t.
 * 
 * Takes a @c trit32_t number and converts to @c trit32_t with an 
 * balaned ternary encoding.
 *
 * @warning This method asserts that the passed in  
 * number will fit into 32 trits.
 *
 * @warning This method asserts that the passed in
 * number is encoded in unbalanced ternary.
 *
 * @param[in] num The unbalanced ternary number to 
 * be turned into balanced ternary.
 *
 * @return The final result of turning the unbalanced
 * ternary number to balanced ternary.
 */  
trit32_t unbalanced_ternary_to_balanced_ternary_trit32_t( trit32_t num ){

    trit32_t result = 0;
    uint8_t grab = 0;
    int array[32] = {};
    int index = 0;
    int carry = 0;
    bool overflow = false;
        
    for(index = 0; index < 32; index++){
    
        grab = num & 0b11;
                
        assert(grab != 0b11 && "Number already balanced");
                
        array[index] = grab;
                
        num = num >> 2;
    }
         
    for(index = 0; index < 32; index ++){
    
        if(array[index] == 3){
        
            carry = 1;
            array[index] = 0;
        }
        else if(array[index] == 2){
        
            carry = 1;
            array[index] = -1;
        }
        else{
        
            carry = 0;
        }
                    
        if(index + 1 < 32){
        
            array[index + 1] += carry;
        }
        
        else if(carry == 1){
        
            overflow = true;
        }
                
    }
            
    assert(overflow == false && "Number too big for ternary");
            
    for(index = 31; index >= 0; index--){
    
        if(array[index] == -1){
        
            result = result | BAL_trit32;
        }
        else if(array[index] == 1){
    
            result = result | ONE_trit32;
        }
        else{
    
            result = result | ZERO_trit32;
        }

        if(index != 0){
           
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Converts unbalanced ternary to binary for @c uint16_t.
 * 
 * Takes a @c trit8_t number with a unbalanced ternary 
 * encoding and converts to @c uint16_t number.
 *
 * @warning This method asserts that the passed in
 * number is encoded in unbalanced ternary.
 *
 * @param[in] num The unbalanced ternary number to 
 * be turned into binary.
 *
 * @return The final result of turning the unbalanced
 * ternary number to binary.
 */
uint16_t unbalanced_ternary_to_binary_uint16_t(trit8_t num){
    
    uint16_t result = 0;
    uint8_t grab = 0;
    uint16_t index = 0;
    
    for(index = 0; index < 8; index++){
    
        grab = num & 0b11;
        
        assert(grab != 0b11 && "Number passed in is Balanced\n");
        
        result += grab * raised_to(3, index);
        
        num = num >> 2;
    }
    
    return result;
}

/**
 * @brief Converts unbalanced ternary to binary for @c uint32_t.
 * 
 * Takes a @c trit16_t number with a unbalanced ternary 
 * encoding and converts to @c uint32_t number.
 *
 * @warning This method asserts that the passed in
 * number is encoded in unbalanced ternary.
 *
 * @param[in] num The unbalanced ternary number to 
 * be turned into binary.
 *
 * @return The final result of turning the unbalanced
 * ternary number to binary.
 */
uint32_t unbalanced_ternary_to_binary_uint32_t(trit16_t num){
    
    uint32_t result = 0;
    uint8_t grab = 0;
    uint32_t index = 0;
    
    for(index = 0; index < 16; index++){
    
        grab = num & 0b11;
        
        assert(grab != 0b11 && "Number passed in is Balanced\n");
        
        result += grab * raised_to(3, index);
        
        num = num >> 2;
    }
    
    return result;
}
 
/**
 * @brief Converts unbalanced ternary to binary for @c uint64_t.
 * 
 * Takes a @c trit32_t number with a unbalanced ternary 
 * encoding and converts to @c uint64_t number.
 *
 * @warning This method asserts that the passed in
 * number is encoded in unbalanced ternary.
 *
 * @param[in] num The unbalanced ternary number to 
 * be turned into binary.
 *
 * @return The final result of turning the unbalanced
 * ternary number to binary.
 */   
uint64_t unbalanced_ternary_to_binary_uint64_t(trit32_t num){

    uint64_t result = 0;
    uint8_t grab = 0;
    uint64_t index = 0;
    
    for(index = 0; index < 32; index++){
    
        grab = num & 0b11;
        
        assert(grab != 0b11 && "Number passed in is Balanced\n");
        
        result += grab * raised_to(3, index);
        
        num = num >> 2;
    }
    
    return result;
}

/**
 * @brief Converts balanced ternary to unbalanced ternary for @c trit8_t.
 * 
 * Takes a @c trit8_t number and converts to @c trit8_t with an 
 * unbalaned ternary encoding.
 *
 * @see balanced_ternary_to_binary_int16_t
 * @see binary_to_unbalanced_ternary_trit8_t
 *
 * @param[in] num The balanced ternary number to 
 * be turned into unbalanced ternary.
 *
 * @return The final result of turning the balanced
 * ternary number to unbalanced ternary.
 */ 
trit8_t balanced_ternary_to_unbalanced_ternary_trit8_t(trit8_t num){
    
    uint16_t binary_result = balanced_ternary_to_binary_int16_t(num);
    return binary_to_unbalanced_ternary_trit8_t(binary_result);
}

/**
 * @brief Converts balanced ternary to unbalanced ternary for @c trit16_t.
 * 
 * Takes a @c trit16_t number and converts to @c trit16_t with an 
 * unbalaned ternary encoding.
 *
 * @see balanced_ternary_to_binary_int32_t
 * @see binary_to_unbalanced_ternary_trit16_t
 *
 * @param[in] num The balanced ternary number to 
 * be turned into unbalanced ternary.
 *
 * @return The final result of turning the balanced
 * ternary number to unbalanced ternary.
 */ 
trit16_t balanced_ternary_to_unbalanced_ternary_trit16_t(trit16_t num){
    
    uint32_t binary_result = balanced_ternary_to_binary_int32_t(num);
    return binary_to_unbalanced_ternary_trit16_t(binary_result);
} 

/**
 * @brief Converts balanced ternary to unbalanced ternary for @c trit32_t.
 * 
 * Takes a @c trit32_t number and converts to @c trit32_t with an 
 * unbalaned ternary encoding.
 *
 * @see balanced_ternary_to_binary_int64_t
 * @see binary_to_unbalanced_ternary_trit32_t
 *
 * @param[in] num The balanced ternary number to 
 * be turned into unbalanced ternary.
 *
 * @return The final result of turning the balanced
 * ternary number to unbalanced ternary.
 */    
trit32_t balanced_ternary_to_unbalanced_ternary_trit32_t(trit32_t num){

    uint64_t binary_result = balanced_ternary_to_binary_int64_t(num);
    return binary_to_unbalanced_ternary_trit32_t(binary_result);
}

/**
 * @brief Converts balanced ternary to binary for @c int16_t.
 * 
 * Takes a @c trit8_t number with a balanced ternary 
 * encoding and converts to @c int16_t number.
 *
 * @warning This method asserts that the passed in
 * number is encoded in balanced ternary.
 *
 * @param[in] num The balanced ternary number to 
 * be turned into binary.
 *
 * @return The final result of turning the balanced
 * ternary number to binary.
 */
int16_t balanced_ternary_to_binary_int16_t(trit8_t num){
    
    int16_t result = 0;
    uint8_t grab = 0;
    uint16_t index = 0;
    int multi = 0;
    
    for(index = 0; index < 8; index++){
    
        grab = num & 0b11;
        
        assert(grab != 0b10 && "Value passed in is unbalanced\n");
        
        if(grab == BAL_trit8){
        
            multi = -1;
        }
        else if(grab == ONE_trit8){
        
            multi = 1;
        }
        else{
        
            multi = 0;
        }
            
        result += multi * raised_to(3, index);
        
        num = num >> 2;
    }
        
    
    return result;
} 

/**
 * @brief Converts balanced ternary to binary for @c int32_t.
 * 
 * Takes a @c trit16_t number with a balanced ternary 
 * encoding and converts to @c int32_t number.
 *
 * @warning This method asserts that the passed in
 * number is encoded in balanced ternary.
 *
 * @param[in] num The balanced ternary number to 
 * be turned into binary.
 *
 * @return The final result of turning the balanced
 * ternary number to binary.
 */ 
int32_t balanced_ternary_to_binary_int32_t(trit16_t num){
    
    int32_t result = 0;
    uint8_t grab = 0;
    uint32_t index = 0;
    int multi = 0;
    
    for(index = 0; index < 16; index++){
    
        grab = num & 0b11;
        
        assert(grab != 0b10 && "Value passed in is unbalanced\n");
        
        if(grab == BAL_trit8){
        
            multi = -1;
        }
        else if(grab == ONE_trit8){
        
            multi = 1;
        }
        else{
        
            multi = 0;
        }
            
        result += multi * raised_to(3, index);
        
        num = num >> 2;
    }
        
    
    return result;
} 

/**
 * @brief Converts balanced ternary to binary for @c int64_t.
 * 
 * Takes a @c trit32_t number with a balanced ternary 
 * encoding and converts to @c int64_t number.
 *
 * @warning This method asserts that the passed in
 * number is encoded in balanced ternary.
 *
 * @param[in] num The balanced ternary number to 
 * be turned into binary.
 *
 * @return The final result of turning the balanced
 * ternary number to binary.
 */
int64_t balanced_ternary_to_binary_int64_t( trit32_t num ){

    int64_t result = 0;
    uint8_t grab = 0;
    uint64_t index = 0;
    int multi = 0;
    
    for(index = 0; index < 32; index++){
    
        grab = num & 0b11;
        
        assert(grab != 0b10 && "Value passed in is unbalanced\n");
        
        if(grab == BAL_trit8){
        
            multi = -1;
        }
        else if(grab == ONE_trit8){
        
            multi = 1;
        }
        else{
        
            multi = 0;
        }
            
        result += multi * raised_to(3, index);
        
        num = num >> 2;
    }
        
    
    return result;
}
    


/** 
 * @brief Adds together two @c trit8_t numbers.
 *
 * This method adds together @p a and @p b 
 * to create a @c trit8_t balanced ternary number.
 *
 * @warning This method asserts that @p a and 
 * @p b are in balanced ternary.
 *
 * @note If an overflow error occurs errno variable
 * is set to EOVERFLOW
 *
 * @param[in] a The first 8 trit balanced 
 * ternary value to be added
 *
 * @param[in] b The second 8 trit balanced 
 * ternary value to be added
 *
 * @return An 8 trit balanced ternary number 
 * resulting of adding together @p a and @p b
 */
trit8_t trit_add_trit8_t(trit8_t a, trit8_t b){

    trit8_t add_result = 0;
    trit8_t result = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;
    int carry = 0;
    int counter_n1 = 0;
    int counter_p1= 0;
    int counter_0 = 0;
    int prev_carry = 0;
    
    for(index = 0; index < 8; index++){
        
        grab_a = a & 0b11;
        grab_b = b & 0b11;
        
        a = a >> 2;
        b = b >> 2;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        carry = 0;
        add_result = 0;
        
        // all cases adding results in 1
        if( (grab_a == BAL_trit8 && grab_b == BAL_trit8) 
            || (grab_a == ZERO_trit8 && grab_b == ONE_trit8) 
            || (grab_a == ONE_trit8 && grab_b == ZERO_trit8)){
        
            add_result = ONE_trit8;
        }
        // all cases adding results in 0
        else if( (grab_a == ZERO_trit8 && grab_b == ZERO_trit8) 
                || (grab_a == ONE_trit8 && grab_b == BAL_trit8) 
                || (grab_a == BAL_trit8 && grab_b == ONE_trit8)){
        
            add_result = ZERO_trit8;
        }
        // rest of the cases results in -1
        else{
            
            add_result = BAL_trit8;
        }
        
        // add in carry and start counting
        if(prev_carry == 1){
            
            counter_p1++;
            // 1 -> -1
            if(add_result == ONE_trit8){
            
                add_result = BAL_trit8;
            }
            // 0 -> 1
            else if(add_result == ZERO_trit8){
            
                add_result = ONE_trit8;
            }
            // -1 -> 0
            else{
            
                add_result = ZERO_trit8;
            }
        }
        else if(prev_carry == -1){
        
            counter_n1++;
            // 1 -> 0
            if(add_result == ONE_trit8){
            
                add_result = ZERO_trit8;
            }
            // 0 -> -1
            else if(add_result == ZERO_trit8){
            
                add_result = BAL_trit8;
            }
            // -1 -> 1
            else{
            
                add_result = ONE_trit8;
            }
        }
        else{
        
            counter_0++;
        }
        
        // counting 
        if(grab_a == ONE_trit8){
            
            counter_p1++;   
        }
        else if(grab_a == ZERO_trit8){
        
            counter_0++;
        }
        else{
        
            counter_n1++;
        }
        
        if(grab_b == ONE_trit8){
            
            counter_p1++;   
        }
        else if(grab_b == ZERO_trit8){
        
            counter_0++;
        }
        else{
        
            counter_n1++;
        }
        
        // Assigning what the carry is through the counter
        if(counter_p1 > 1 && counter_n1 == 0){
        
            carry = 1;
        }
        else if(counter_0 > 1){
        
            carry = 0;
        }
        else if(counter_p1 >= 1){
        
            carry = 0;
        }
        else{
        
            carry = -1;
        }
        
        // reset for the next iteration
        prev_carry = carry;
        counter_p1 = 0;
        counter_n1 = 0;
        counter_0 = 0;
        
        // add in the new result
        add_result = add_result << (index * 2);
        result = result | add_result;
        
    }
    
    if(prev_carry != 0){
    
        errno = EOVERFLOW;
    }

    return result;
}

/** 
 * @brief Adds together two @c trit16_t numbers.
 *
 * This method adds together @p a and @p b 
 * to create a @c trit16_t balanced ternary number.
 *
 * @warning This method asserts that @p a and 
 * @p b are in balanced ternary.
 *
 * @note If an overflow error occurs errno variable
 * is set to EOVERFLOW
 *
 * @param[in] a The first 16 trit balanced 
 * ternary value to be added
 *
 * @param[in] b The second 16 trit balanced 
 * ternary value to be added
 *
 * @return A 16 trit balanced ternary number 
 * resulting of adding together @p a and @p b
 */
trit16_t trit_add_trit16_t(trit16_t a, trit16_t b){

    trit16_t add_result = 0;
    trit16_t result = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;
    int carry = 0;
    int counter_n1 = 0;
    int counter_p1= 0;
    int counter_0 = 0;
    int prev_carry = 0;
    
    for(index = 0; index < 16; index++){
        
        grab_a = a & 0b11;
        grab_b = b & 0b11;
        
        a = a >> 2;
        b = b >> 2;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        carry = 0;
        add_result = 0;
        
        // all cases adding results in 1
        if( (grab_a == BAL_trit8 && grab_b == BAL_trit8) 
            || (grab_a == ZERO_trit8 && grab_b == ONE_trit8) 
            || (grab_a == ONE_trit8 && grab_b == ZERO_trit8)){
        
            add_result = ONE_trit16;
        }
        // all cases adding results in 0
        else if( (grab_a == ZERO_trit8 && grab_b == ZERO_trit8) 
                || (grab_a == ONE_trit8 && grab_b == BAL_trit8) 
                || (grab_a == BAL_trit8 && grab_b == ONE_trit8)){
        
            add_result = ZERO_trit16;
        }
        // rest of the cases results in -1
        else{
            
            add_result = BAL_trit16;
        }
        
        // add in carry and start counting
        if(prev_carry == 1){
            
            counter_p1++;
            // 1 -> -1
            if(add_result == ONE_trit16){
            
                add_result = BAL_trit16;
            }
            // 0 -> 1
            else if(add_result == ZERO_trit16){
            
                add_result = ONE_trit16;
            }
            // -1 -> 0
            else{
            
                add_result = ZERO_trit16;
            }
        }
        else if(prev_carry == -1){
        
            counter_n1++;
            // 1 -> 0
            if(add_result == ONE_trit16){
            
                add_result = ZERO_trit16;
            }
            // 0 -> -1
            else if(add_result == ZERO_trit16){
            
                add_result = BAL_trit16;
            }
            // -1 -> 1
            else{
            
                add_result = ONE_trit16;
            }
        }
        else{
        
            counter_0++;
        }
        
        // counting 
        if(grab_a == ONE_trit8){
            
            counter_p1++;   
        }
        else if(grab_a == ZERO_trit8){
        
            counter_0++;
        }
        else{
        
            counter_n1++;
        }
        
        if(grab_b == ONE_trit8){
            
            counter_p1++;   
        }
        else if(grab_b == ZERO_trit8){
        
            counter_0++;
        }
        else{
        
            counter_n1++;
        }
        
        // Assigning what the carry is through the counter
        if(counter_p1 > 1 && counter_n1 == 0){
        
            carry = 1;
        }
        else if(counter_0 > 1){
        
            carry = 0;
        }
        else if(counter_p1 >= 1){
        
            carry = 0;
        }
        else{
        
            carry = -1;
        }
        
        // reset for the next iteration
        prev_carry = carry;
        counter_p1 = 0;
        counter_n1 = 0;
        counter_0 = 0;
        
        // add in the new result
        add_result = add_result << (index * 2);
        result = result | add_result;
        
        }
    
    if(prev_carry != 0){
    
        errno = EOVERFLOW;
    }

    return result;
}

/** 
 * @brief Adds together two @c trit32_t numbers.
 *
 * This method adds together @p a and @p b 
 * to create a @c trit32_t balanced ternary number.
 *
 * @warning This method asserts that @p a and 
 * @p b are in balanced ternary.
 *
 * @note If an overflow error occurs errno variable
 * is set to EOVERFLOW
 *
 * @param[in] a The first 32 trit balanced 
 * ternary value to be added
 *
 * @param[in] b The second 32 trit balanced 
 * ternary value to be added
 *
 * @return A 32 trit balanced ternary number 
 * resulting of adding together @p a and @p b
 */
trit32_t trit_add_trit32_t(trit32_t a, trit32_t b){

    trit32_t add_result = 0;
    trit32_t result = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;
    int carry = 0;
    int counter_n1 = 0;
    int counter_p1= 0;
    int counter_0 = 0;
    int prev_carry = 0;
    
    for(index = 0; index < 32; index++){
        
        grab_a = a & 0b11;
        grab_b = b & 0b11;
        
        a = a >> 2;
        b = b >> 2;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        carry = 0;
        add_result = 0;
        
        // all cases adding results in 1
        if( (grab_a == BAL_trit8 && grab_b == BAL_trit8) 
            || (grab_a == ZERO_trit8 && grab_b == ONE_trit8) 
            || (grab_a == ONE_trit8 && grab_b == ZERO_trit8)){
        
            add_result = ONE_trit32;
        }
        // all cases adding results in 0
        else if( (grab_a == ZERO_trit8 && grab_b == ZERO_trit8) 
                || (grab_a == ONE_trit8 && grab_b == BAL_trit8) 
                || (grab_a == BAL_trit8 && grab_b == ONE_trit8)){
        
            add_result = ZERO_trit32;
        }
        // rest of the cases results in -1
        else{
            
            add_result = BAL_trit32;
        }
        
        // add in carry and start counting
        if(prev_carry == 1){
            
            counter_p1++;
            // 1 -> -1
            if(add_result == ONE_trit32){
            
                add_result = BAL_trit32;
            }
            // 0 -> 1
            else if(add_result == ZERO_trit32){
            
                add_result = ONE_trit32;
            }
            // -1 -> 0
            else{
            
                add_result = ZERO_trit32;
            }
        }
        else if(prev_carry == -1){
        
            counter_n1++;
            // 1 -> 0
            if(add_result == ONE_trit32){
            
                add_result = ZERO_trit32;
            }
            // 0 -> -1
            else if(add_result == ZERO_trit32){
            
                add_result = BAL_trit32;
            }
            // -1 -> 1
            else{
            
                add_result = ONE_trit32;
            }
        }
        else{
        
            counter_0++;
        }
        
        // counting 
        if(grab_a == ONE_trit8){
            
            counter_p1++;   
        }
        else if(grab_a == ZERO_trit8){
        
            counter_0++;
        }
        else{
        
            counter_n1++;
        }
        
        if(grab_b == ONE_trit8){
            
            counter_p1++;   
        }
        else if(grab_b == ZERO_trit8){
        
            counter_0++;
        }
        else{
        
            counter_n1++;
        }
        
        // Assigning what the carry is through the counter
        if(counter_p1 > 1 && counter_n1 == 0){
        
            carry = 1;
        }
        else if(counter_0 > 1){
        
            carry = 0;
        }
        else if(counter_p1 >= 1){
        
            carry = 0;
        }
        else{
        
            carry = -1;
        }
        
        // reset for the next iteration
        prev_carry = carry;
        counter_p1 = 0;
        counter_n1 = 0;
        counter_0 = 0;
        
        // add in the new result
        add_result = add_result << (index * 2);
        result = result | add_result;
        
        }
    
    if(prev_carry != 0){
    
        errno = EOVERFLOW;
    }

    return result;
}

/** 
 * @brief Subtracts two @c trit8_t numbers.
 *
 * This method subtracts @p a and @p b 
 * to create a @c trit8_t balanced ternary number.
 *
 * @see trit_not_trit8_t
 * @see trit_add_trit8_t
 *
 * @param[in] a The 8 trit balanced 
 * ternary value to be subtracted from
 *
 * @param[in] b The 8 trit balanced 
 * ternary value to be subtracted
 *
 * @return An 8 trit balanced ternary number 
 * resulting of subtracting @p a and @p b
 */
trit8_t trit_sub_trit8_t(trit8_t a, trit8_t b){

  trit8_t not_b = trit_not_trit8_t(b);
  
  return trit_add_trit8_t(a, not_b);
}

/** 
 * @brief Subtracts two @c trit16_t numbers.
 *
 * This method subtracts @p a and @p b 
 * to create a @c trit16_t balanced ternary number.
 *
 * @see trit_not_trit16_t
 * @see trit_add_trit16_t
 *
 * @param[in] a The 16 trit balanced 
 * ternary value to be subtracted from
 *
 * @param[in] b The 16 trit balanced 
 * ternary value to be subtracted
 *
 * @return A 16 trit balanced ternary number 
 * resulting of subtracting @p a and @p b
 */
trit16_t trit_sub_trit16_t(trit16_t a, trit16_t b){

  trit16_t not_b = trit_not_trit16_t(b);
  
  return trit_add_trit16_t(a, not_b);
}

/** 
 * @brief Subtracts two @c trit32_t numbers.
 *
 * This method subtracts @p a and @p b 
 * to create a @c trit32_t balanced ternary number.
 *
 * @see trit_not_trit32_t
 * @see trit_add_trit32_t
 *
 * @param[in] a The 32 trit balanced 
 * ternary value to be subtracted from
 *
 * @param[in] b The 32 trit balanced 
 * ternary value to be subtracted
 *
 * @return An 32 trit balanced ternary number 
 * resulting of subtracting @p a and @p b
 */
trit32_t trit_sub_trit32_t(trit32_t a, trit32_t b){

  trit32_t not_b = trit_not_trit32_t(b);
  
  return trit_add_trit32_t(a, not_b);
}

/** 
 * This method OR's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 8 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 8 trit balanced
 * ternary number
 *
 * @return An 8 trit balanced ternary number 
 * resulting from the OR of @p a and @p b
 */
trit8_t trit_or_trit8_t(trit8_t a, trit8_t b){

    trit8_t result = 0;
    trit8_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;
  
    for(index = 14; index >= 0; index -= 2){
        
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        if(grab_a == ZERO_trit8 && grab_b == ZERO_trit8){
            
            result = result | ZERO_trit8;
        }
        else if(grab_a == ONE_trit8 || grab_b == ONE_trit8){
            
            result = result | ONE_trit8;
        }
        else{
            
            result = result | BAL_trit8;
        }
        
        if(index != 0){
            
            result = result << 2;
        }
    }
  
    return result;
}

/** 
 * This method OR's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 16 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 16 trit balanced
 * ternary number
 *
 * @return A 16 trit balanced ternary number 
 * resulting from the OR of @p a and @p b
 */
trit16_t trit_or_trit16_t(trit16_t a, trit16_t b){

    trit16_t result = 0;
    trit16_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;
  
    for(index = 30; index >= 0; index -= 2){
        
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        if(grab_a == ZERO_trit8 && grab_b == ZERO_trit8){
            
            result = result | ZERO_trit16;
        }
        else if(grab_a == ONE_trit8 || grab_b == ONE_trit8){
            
            result = result | ONE_trit16;
        }
        else{
            
            result = result | BAL_trit16;
        }
        
        if(index != 0){
            
            result = result << 2;
        }
    }
  
    return result;
}

/** 
 * This method OR's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 32 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 32 trit balanced
 * ternary number
 *
 * @return A 32 trit balanced ternary number 
 * resulting from the OR of @p a and @p b
 */
trit32_t trit_or_trit32_t(trit32_t a, trit32_t b){

    trit32_t result = 0;
    trit32_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;
  
    for(index = 62; index >= 0; index -= 2){
        
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        if(grab_a == ZERO_trit8 && grab_b == ZERO_trit8){
            
            result = result | ZERO_trit32;
        }
        else if(grab_a == ONE_trit8 || grab_b == ONE_trit8){
            
            result = result | ONE_trit32;
        }
        else{
            
            result = result | BAL_trit32;
        }
        
        if(index != 0){
            
            result = result << 2;
        }
    }
  
    return result;
}

/** 
 * This method XOR's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 8 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 8 trit balanced
 * ternary number
 *
 * @return An 8 trit balanced ternary number 
 * resulting from the XOR of @p a and @p b
 */
trit8_t trit_xor_trit8_t(trit8_t a, trit8_t b){

    trit8_t result = 0;
    trit8_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;

    for(index = 14; index >= 0; index -= 2){
    
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        if(grab_a == grab_b){
            
            result = result | BAL_trit8;
        }
        else if(grab_a == ZERO_trit8 || grab_b == ZERO_trit8){
            
            result = result | ZERO_trit8;
        }
        else{
        
            result = result | ONE_trit8;
        }
        
        if(index != 0){
            
            result = result << 2;
        }
    }

    return result;
}

/** 
 * This method XOR's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 16 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 16 trit balanced
 * ternary number
 *
 * @return A 16 trit balanced ternary number 
 * resulting from the XOR of @p a and @p b
 */
trit16_t trit_xor_trit16_t(trit16_t a, trit16_t b){

    trit16_t result = 0;
    trit16_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;

    for(index = 30; index >= 0; index -= 2){
    
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        if(grab_a == grab_b){
            
            result = result | BAL_trit16;
        }
        else if(grab_a == ZERO_trit8 || grab_b == ZERO_trit8){
            
            result = result | ZERO_trit16;
        }
        else{
        
            result = result | ONE_trit16;
        }
        
        if(index != 0){
            
            result = result << 2;
        }
    }

    return result;
}

/** 
 * This method XOR's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 32 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 32 trit balanced
 * ternary number
 *
 * @return A 32 trit balanced ternary number 
 * resulting from the XOR of @p a and @p b
 */
trit32_t trit_xor_trit32_t(trit32_t a, trit32_t b){

    trit32_t result = 0;
    trit32_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;

    for(index = 62; index >= 0; index -= 2){
    
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);
        
        if(grab_a == grab_b){
            
            result = result | BAL_trit32;
        }
        else if(grab_a == ZERO_trit8 || grab_b == ZERO_trit8){
            
            result = result | ZERO_trit32;
        }
        else{
        
            result = result | ONE_trit32;
        }
        
        if(index != 0){
            
            result = result << 2;
        }
    }

    return result;
}

/** 
 * This method AND's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 8 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 8 trit balanced
 * ternary number
 *
 * @return An 8 trit balanced ternary number 
 * resulting from the AND of @p a and @p b
 */
trit8_t trit_and_trit8_t(trit8_t a, trit8_t b){

    trit8_t result = 0;
    trit8_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;

    for(index = 14; index >= 0; index -= 2){
    
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);

        if(grab_a == ONE_trit8 && grab_b == ONE_trit8 ){
        
            result = result | ONE_trit8;
        }
        else if(grab_a == BAL_trit8 || grab_b == BAL_trit8){
        
            result = result | BAL_trit8;
        }
        else{
        
            result = result | ZERO_trit8;
        }

        if(index != 0){
        
            result = result << 2;
        }
    }

    return result;
}

/** 
 * This method AND's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 16 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 16 trit balanced
 * ternary number
 *
 * @return A 16 trit balanced ternary number 
 * resulting from the AND of @p a and @p b
 */
trit16_t trit_and_trit16_t(trit16_t a, trit16_t b){

    trit16_t result = 0;
    trit16_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;

    for(index = 30; index >= 0; index -= 2){
    
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);

        if(grab_a == ONE_trit8 && grab_b == ONE_trit8 ){
        
            result = result | ONE_trit16;
        }
        else if(grab_a == BAL_trit8 || grab_b == BAL_trit8){
        
            result = result | BAL_trit16;
        }
        else{
        
            result = result | ZERO_trit16;
        }
    
        if(index != 0){
        
            result = result << 2;
        }
    }

    return result;
}

/** 
 * This method AND's together @p a and @p b 
 *
 * @warning This method asserts that @p a 
 * and @p b are in balanced ternary.
 *
 * @param[in] a The first 32 trit balanced 
 * ternary number
 * 
 * @param[in] b The second 32 trit balanced
 * ternary number
 *
 * @return A 32 trit balanced ternary number 
 * resulting from the AND of @p a and @p b
 */
trit32_t trit_and_trit32_t(trit32_t a, trit32_t b){

    trit32_t result = 0;
    trit32_t temp = 0;
    trit8_t grab_a = 0;
    trit8_t grab_b = 0;
    int index = 0;

    for(index = 62; index >= 0; index -= 2){
    
        temp = a >> index;
        grab_a = temp & 0b11;
        temp = b >> index;
        grab_b = temp & 0b11;
        
        assert(grab_a != TWO_trit8 && grab_b != TWO_trit8);

        if(grab_a == ONE_trit8 && grab_b == ONE_trit8 ){
        
            result = result | ONE_trit32;
        }
        else if(grab_a == BAL_trit8 || grab_b == BAL_trit8){
        
            result = result | BAL_trit32;
        }
        else{
        
            result = result | ZERO_trit32;
        }

        if(index != 0){
        
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Shifts the trits of @p a to the left.
 *
 * This method shifts a @c trit8_t number some number 
 * of trits left indicated by @p b a @c uint8_t number. 
 *
 * @param[in] a Some 8 trit number to be shifted.
 *
 * @param[in] b Some @c uint8_t variable
 * to indicate how many trits @p a 
 * should be shifted
 *
 * @return The result of shifting @p a some
 * number of trits resulting in an @c trit8_t number.
 */
trit8_t trit_sl_trit8_t(trit8_t a, uint8_t b){

    if(b > 8){

        b = 8;
    }
    
    while(b > 0){
        
        a = a << 2;
        b--;
    }

    return a; 
}

/**
 * @brief Shifts the trits of @p a to the left.
 *
 * This method shifts a @c trit16_t number some number 
 * of trits left indicated by @p b a @c uint8_t number. 
 *
 * @param[in] a Some 16 trit number to be shifted.
 *
 * @param[in] b Some @c uint8_t variable
 * to indicate how many trits @p a 
 * should be shifted
 *
 * @return The result of shifting @p a some
 * number of trits resulting in an @c trit16_t number.
 */
trit16_t trit_sl_trit16_t(trit16_t a, uint8_t b){

    if(b > 16){

        b = 16;
    }
    
    while(b > 0){
        
        a = a << 2;
        b--;
    }

    return a; 
}

/**
 * @brief Shifts the trits of @p a to the left.
 *
 * This method shifts a @c trit32_t number some number 
 * of trits left indicated by @p b a @c uint8_t number. 
 *
 * @param[in] a Some 32 trit number to be shifted.
 *
 * @param[in] b Some @c uint8_t variable
 * to indicate how many trits @p a 
 * should be shifted
 *
 * @return The result of shifting @p a some
 * number of trits resulting in an @c trit32_t number.
 */
trit32_t trit_sl_trit32_t(trit32_t a, uint8_t b){

    if(b > 32){

        b = 32;
    }
    
    while(b > 0){
        
        a = a << 2;
        b--;
    }

    return a;
}

/**
 * @brief Shifts the trits of @p a to the right.
 *
 * This method shifts a @c trit8_t number some number 
 * of trits right indicated by @p b a @c uint8_t number. 
 *
 * @param[in] a Some 8 trit number to be shifted.
 *
 * @param[in] b Some @c uint8_t variable
 * to indicate how many trits @p a 
 * should be shifted
 *
 * @return The result of shifting @p a some
 * number of trits resulting in an @c trit8_t number.
 */
trit8_t trit_sr_trit8_t(trit8_t a, uint8_t b){

    if(b > 8){

        b = 8;
    }
    
    while(b > 0){
        
        a = a >> 2;
        b--;
    }

    return a;
}

/**
 * @brief Shifts the trits of @p a to the right.
 *
 * This method shifts a @c trit16_t number some number 
 * of trits right indicated by @p b a @c uint8_t number. 
 *
 * @param[in] a Some 16 trit number to be shifted.
 *
 * @param[in] b Some @c uint8_t variable
 * to indicate how many trits @p a 
 * should be shifted
 *
 * @return The result of shifting @p a some
 * number of trits resulting in an @c trit16_t number.
 */
trit16_t trit_sr_trit16_t(trit16_t a, uint8_t b){

    if(b > 16){

        b = 16;
    }
    
    while(b > 0){
        
        a = a >> 2;
        b--;
    }

    return a;
}

/**
 * @brief Shifts the trits of @p a to the right.
 *
 * This method shifts a @c trit32_t number some number 
 * of trits right indicated by @p b a @c uint8_t number. 
 *
 * @param[in] a Some 32 trit number to be shifted.
 *
 * @param[in] b Some @c uint8_t variable
 * to indicate how many trits @p a 
 * should be shifted
 *
 * @return The result of shifting @p a some
 * number of trits resulting in an @c trit32_t number.
 */
trit32_t trit_sr_trit32_t(trit32_t a, uint8_t b){

    if(b > 32){

        b = 32;
    }
    
    while(b > 0){
        
        a = a >> 2;
        b--;
    }

    return a;
}

/**
 * @brief Returns the negation of @p num
 *
 * This method takes in a @c trit8_t balanced
 * ternary number and returns the negation.
 *
 * @warning This method asserts that @p num
 *  is in balanced ternary. 
 *
 * @param[in] num The 8 trit balanced ternary
 * number to be negated.
 *
 * @return An 8 trit balanced ternary number
 * of the negation of @p num
 */
trit8_t trit_not_trit8_t(trit8_t num){
    
    trit8_t result = 0;
    trit8_t temp = 0;
    trit8_t grab = 0;
    int index = 0;

    for(index = 14; index >= 0; index -= 2){
    
        temp = num >> index;
        grab = temp & 0b11;
        
        assert(grab != TWO_trit8);

        if(grab == ONE_trit8){
        
            result = result | BAL_trit8;
        }
        else if(grab == BAL_trit8){
        
            result = result | ONE_trit8;
        }
        else{
        
            result = result | ZERO_trit8;
        }

        if(index != 0){
        
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Returns the negation of @p num
 *
 * This method takes in a @c trit16_t balanced
 * ternary number and returns the negation.
 *
 * @warning This method asserts that @p num
 *  is in balanced ternary. 
 *
 * @param[in] num The 16 trit balanced ternary
 * number to be negated.
 *
 * @return A 16 trit balanced ternary number
 * of the negation of @p num
 */
trit16_t trit_not_trit16_t(trit16_t num){

    trit16_t result = 0;
    trit16_t temp = 0;
    trit8_t grab = 0;
    int index = 0;

    for(index = 30; index >= 0; index -= 2){
    
        temp = num >> index;
        grab = temp & 0b11;
        
        assert(grab != TWO_trit8);

        if(grab== ONE_trit8){
        
            result = result | BAL_trit16;
        }
        else if(grab == BAL_trit8){
        
            result = result | ONE_trit16;
        }
        else{
        
            result = result | ZERO_trit16;
        }

        if(index != 0){
        
            result = result << 2;
        }
    }

    return result;
}

/**
 * @brief Returns the negation of @p num
 *
 * This method takes in a @c trit32_t balanced
 * ternary number and returns the negation.
 *
 * @warning This method asserts that @p num
 *  is in balanced ternary. 
 *
 * @param[in] num The 32 trit balanced ternary
 * number to be negated.
 *
 * @return A 32 trit balanced ternary number
 * of the negation of @p num
 */
trit32_t trit_not_trit32_t(trit32_t num){

    trit32_t result = 0;
    trit32_t temp = 0;
    trit8_t grab = 0;
    int index = 0;

    for(index = 62; index >= 0; index -= 2){
    
        temp = num >> index;
        grab = temp & 0b11;
        
        assert(grab != TWO_trit8);

        if(grab== ONE_trit8){
        
            result = result | BAL_trit32;
        }
        else if(grab == BAL_trit8){
        
            result = result | ONE_trit32;
        }
        else{
        
            result = result | ZERO_trit32;
        }

        if(index != 0){
        
            result = result << 2;
        }
    }

    return result;
}



