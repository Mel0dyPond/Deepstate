basic: ternary.c ternary.h ternary_testing.cpp
	clang++ ternary.c ternary_testing.cpp -o basic -ldeepstate

test_afl: ternary.c ternary.h ternary_testing.cpp
	deepstate-afl --compile_test ternary.c ternary_testing.cpp --compile_args ternary.c --out_test_name test_afl

