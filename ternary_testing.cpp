#include <deepstate/DeepState.hpp>
using namespace deepstate;

extern "C"{

  #include "ternary.h"
}



TEST(TernaryLibrary, AddTest){

  uint32_t binary_num1 = DeepState_UIntInRange(0, UINT32_MAX);
  uint32_t binary_num2 = DeepState_UIntInRange(0, UINT32_MAX);

  trit32_t ternary_num1 = binary_to_balanced_ternary_trit32_t(binary_num1);
  trit32_t ternary_num2 = binary_to_balanced_ternary_trit32_t(binary_num2);

  uint32_t binary_add = binary_num1 + binary_num2;

  trit32_t ternary_add = trit_add_trit32_t(ternary_num1, ternary_num2);

  uint64_t transformed_add = balanced_ternary_to_binary_trit32_t(ternary_add);

  assert(binary_add == transformed_add);
  
}

Test(TernaryLibrary, SubtractTest){

}

Test(TernaryLibrary, NotTest){

}
