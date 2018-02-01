#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests discardCard function

#define NOISY_TEST 1

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example
	int currentPlayer = 1;
	int handPos = 1;

	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, &G);
	// make player draw 5 cards for testing

	int c;
	for (c = 0; c < 5; c++) {
		drawCard(currentPlayer, &G);
	}	
	
	int h;
	int handCount = G.handCount[currentPlayer];
	for (h = 0; h < handCount; h++) {

#if (NOISY_TEST == 1)
		printf("Testing playing a card (trash flag 0).\n");
#endif
		struct gameState current;
		struct gameState before;
		memset(&current, 23, sizeof(struct gameState));
		memset(&before, 23, sizeof(struct gameState));
		memcpy(&current, &G, sizeof(struct gameState));
		memcpy(&before, &G, sizeof(struct gameState));	

		discardCard(h, currentPlayer, &current, 0);
#if (NOISY_TEST == 1)
		printf("played pile expected = %d, actual = %d\n", before.playedCardCount + 1, current.playedCardCount);
#endif
		assert(before.playedCardCount + 1 == current.playedCardCount);
#if (NOISY_TEST == 1)
		printf("number of cards in hand expected = %d, number of cards in hand actual = %d\n", 
			before.handCount[currentPlayer] - 1, current.handCount[currentPlayer]);
#endif
		assert(before.handCount[currentPlayer] - 1 == current.handCount[currentPlayer]);
	}

	for (h = 0; h < handCount; h++) {
#if (NOISY_TEST == 1)
		printf("Testing trashing card (trash flag 1).\n");
#endif
		struct gameState current;
		struct gameState before;
		memset(&current, 23, sizeof(struct gameState));
		memset(&before, 23, sizeof(struct gameState));
		memcpy(&current, &G, sizeof(struct gameState));
		memcpy(&before, &G, sizeof(struct gameState));	

		discardCard(h, currentPlayer, &current, 1);
#if (NOISY_TEST == 1)
		printf("played pile expected = %d, actual = %d\n", before.playedCardCount, current.playedCardCount);
#endif
		assert(before.playedCardCount == current.playedCardCount);
#if (NOISY_TEST == 1)
		printf("number of cards in hand expected = %d, number of cards in hand actual = %d\n",
			before.handCount[currentPlayer] - 1, current.handCount[currentPlayer]);
#endif
		assert(before.handCount[currentPlayer] - 1 == current.handCount[currentPlayer]);
	}

	return 0;
}
