#include "ternary.h"
#include <deepstate/DeepState.hpp>

using namespace deepstate;

TEST(TernaryLibrary, BalancedTransform){

  uint32_t binary_num = DeepState_UInt();

  trit32_t ternary_num = binary_to_balanced_ternary_trit32_t(binary_num);

  int64_t transformed = balanced_ternary_to_binary_int64_t(ternary_num);

  LOG(TRACE) << "Binary:      " << binary_num;
  LOG(TRACE) << "Transformed: " << transformed;
  
  ASSERT (binary_num == transformed);
}

TEST(TernaryLibrary, AddTest){

  uint32_t binary_num1 = DeepState_UInt();
  uint32_t binary_num2 = DeepState_UInt();

  trit32_t ternary_num1 = binary_to_balanced_ternary_trit32_t(binary_num1);
  trit32_t ternary_num2 = binary_to_balanced_ternary_trit32_t(binary_num2);
  
  uint32_t binary_add = binary_num1 + binary_num2;

  trit32_t ternary_add = trit_add_trit32_t(ternary_num1, ternary_num2);

  int64_t transformed_add = balanced_ternary_to_binary_int64_t(ternary_add);

  LOG(TRACE) << "Binary Add:      " << binary_add;
  LOG(TRACE) << "Transformed Add: " << transformed_add;
  
  ASSERT (binary_add == transformed_add);
  
}

TEST(TernaryLibrary, SubtractTest){

  uint32_t binary_num1 = DeepState_UInt();
  uint32_t binary_num2 = DeepState_UInt();

  trit32_t ternary_num1 = binary_to_balanced_ternary_trit32_t(binary_num1);
  trit32_t ternary_num2 = binary_to_balanced_ternary_trit32_t(binary_num2);

  int32_t binary_sub = binary_num1 - binary_num2;

  trit32_t ternary_sub = trit_sub_trit32_t(ternary_num1, ternary_num2);

  int64_t transformed_sub = balanced_ternary_to_binary_int64_t(ternary_sub);

  LOG(TRACE) << "Binary Subtract:      " << binary_sub;
  LOG(TRACE) << "Transformed Subtract: " << transformed_sub;
  
  ASSERT (binary_sub == transformed_sub);
}
