#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

int main() {

#if (NOISY_TEST == 1)
	printf("Testing invalid card.\n");
#endif
	int actual = getCost(1234);
	int expected = -1;
#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", actual, expected);
#endif
	assert(getCost(12345) == -1);

#if (NOISY_TEST == 1)
	printf("Testing some of the actual cards.\n");
	printf("actual = %d, expected = %d\n", getCost(curse), 0);
#endif
	assert(getCost(curse) == 0);

#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", getCost(outpost), 5);
#endif
	assert(getCost(outpost) == 5);

#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", getCost(smithy), 4);
#endif
	assert(getCost(smithy) == 4);

#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", getCost(great_hall), 3);
#endif
	assert(getCost(great_hall) == 3);

#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", getCost(adventurer), 6);
#endif
	assert(getCost(adventurer) == 6);

#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", getCost(estate), 2);
#endif
	assert(getCost(estate) == 2);

	return 0;
}
