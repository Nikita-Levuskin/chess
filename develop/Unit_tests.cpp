#include <cassert>
#include "App.h"
#include "lib.h"

void Test_check_rook() {
	assert(check_rook(1, 1, 2, 2) == 1);
	assert(check_rook(1, 1, 3, 2) == 1);
	assert(check_rook(1, 2, 4, 3) == 1);
	assert(check_rook(4, 2, 4, 3) == 0);
	assert(check_rook(1, 1, 2, 1) == 0);
	assert(check_rook(1, 1, 1, 2) == 0);
}

void Test_check_elephant() {
	assert(check_elephant(1, 1, 1, 2) == 1);
	assert(check_elephant(1, 1, 2, 1) == 1);
	assert(check_elephant(1, 1, 4, 6) == 1);
	assert(check_elephant(1, 1, 2, 2) == 0);
	assert(check_elephant(2, 2, 1, 1) == 0);
	assert(check_elephant(5, 5, 6, 4) == 0);
}