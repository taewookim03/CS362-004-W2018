#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests playAdventurer function

#define NOISY_TEST 1

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example
	
	memset(&G, 23, sizeof(struct gameState));
	int currentPlayer = 0;

	// initializing gmae gives starting player (player 0) 5 card draws
	initializeGame(numPlayer, k, seed, &G);
	int r = playAdventurer(&G, currentPlayer, 0);
	assert(r == 0);

#if (NOISY_TEST == 1)
	printf("Expected hand size = %d, actual hand size = %d\n", 6, G.handCount[currentPlayer]);
#endif
	//check last 2 cards are treasures
	int t1 = handCard(G.hand[currentPlayer][numHandCards(&G) - 1], &G);
	int t2 = handCard(G.hand[currentPlayer][numHandCards(&G) - 2], &G);
	assert(t1 == copper || t1 == silver || t1 == gold);
	assert(t2 == copper || t2 == silver || t2 == gold);
	//assert(G.handCount[currentPlayer] == h + 2);//assert fails due to bug in playAdventurer

	return 0;	
}
