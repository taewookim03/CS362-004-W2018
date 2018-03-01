#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests playVillage function

#define NOISY_TEST 1

int main() {
	return 0;

	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example
	
	memset(&G, 23, sizeof(struct gameState));
	int currentPlayer = 0;

	// initializing gmae gives starting player (player 0) 5 card draws
	initializeGame(numPlayer, k, seed, &G);
	
	int handSizeBefore = numHandCards(&G);
	int numActionsBefore = G.numActions;
	
	int r = cardEffect(village, 0, 0, 0, &G, 0, NULL);
	assert(r == 0);	
#if (NOISY_TEST == 1)
	printf("Expected hand size = %d, actual hand size = %d\n", handSizeBefore, G.handCount[currentPlayer]);
	printf("Expected action size = %d, actual action size = %d\n", numActionsBefore+2, G.numActions);
#endif
	assert(handSizeBefore == G.handCount[currentPlayer]);
	assert(numActionsBefore + 2 == G.numActions);

	return 0;	
}
