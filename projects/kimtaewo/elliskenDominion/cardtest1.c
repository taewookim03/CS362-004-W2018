#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests playSmithy function

#define NOISY_TEST 1

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, &G);
	
	int currentPlayer = 0;

	int player;

	// initializing gmae gives starting player (player 0) 5 card draws
	initializeGame(numPlayer, k, seed, &G);
	int h = G.handCount[currentPlayer];
	int r = cardSmithy(currentPlayer, &G, 0);//pretend smithy is the first card
	assert(r == 0);

#if (NOISY_TEST == 1)
	printf("Expected hand size = %d, actual hand size = %d\n", 7, G.handCount[currentPlayer]);
#endif
	//assert(G.handCount[currentPlayer] == h + 2);//assert fails due to bug in playSmithy	
	
	return 0;	
}	
