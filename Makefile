basic: ternary.c ternary.h ternary_testing.cpp
	clang++ ternary.c ternary_testing.cpp -o basic -ldeepstate

run_basic: basic
	./basic --fuzz

test_afl: ternary.c ternary.h ternary_testing.cpp
	deepstate-afl --compile_test ternary_testing.cpp --compiler_args ternary.c --out_test_name test_afl

run_afl: test_afl.afl
	deepstate-afl ./test_afl.afl -o aflTests --fuzzer_out
