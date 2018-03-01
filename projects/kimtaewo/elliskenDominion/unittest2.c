#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests isGameOver function

#define NOISY_TEST 1

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example

#if (NOISY_TEST == 1)
	printf("Testing isGameOver correctly recognizes game over when province cards stack is empty.\n");
#endif
	memset(&G, 23, sizeof(struct gameState)); //clear game state
	initializeGame(numPlayer, k, seed, &G);
	G.supplyCount[province] = 0;
#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", isGameOver(&G), 1);
#endif
	assert(isGameOver(&G) == 1);


#if (NOISY_TEST == 1)
	printf("Testing isGameOver correctly recognizes game over when exactly all supply piles are at 0.\n");
#endif
	int i;
	for (i = 0; i <= treasure_map; i++) {
		G.supplyCount[i] = 0;
	}
#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", isGameOver(&G), 1);
#endif
	assert(isGameOver(&G) == 1);

	
#if (NOISY_TEST == 1)
	printf("Testing isGameOver correctly recognizes not game over when exactly two supply piles other than province are at 0.\n");
#endif
	initializeGame(numPlayer, k, seed, &G);
	G.supplyCount[adventurer] = 0;
	G.supplyCount[estate] = 0;
#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", isGameOver(&G), 0);
#endif
	assert(isGameOver(&G) == 0);
	

#if (NOISY_TEST == 1)
	printf("Testing isGameOver correctly recognizes game over when exactly three supply piles other than province are at 0.\n");
#endif
	initializeGame(numPlayer, k, seed, &G);
	G.supplyCount[estate] = 0;
	G.supplyCount[silver] = 0;
	G.supplyCount[duchy] = 0;	
#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", isGameOver(&G), 1);
#endif
	assert(isGameOver(&G) == 1);

	initializeGame(numPlayer, k, seed, &G);
	G.supplyCount[gold] = 0;
	G.supplyCount[curse] = 0;
	G.supplyCount[treasure_map] = 0;
#if (NOISY_TEST == 1)
	printf("actual = %d, expected = %d\n", isGameOver(&G), 1);
#endif
	//assert(isGameOver(&G) == 1);// this one fails so commented out as professor mentioned on piazza

	return 0;
}
