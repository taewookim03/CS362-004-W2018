#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests handCard function

#define NOISY_TEST 1

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example
	
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, &G);
	
	// draw 5 cards
	int c;
	for (c = 0; c < 5; c++) {
		drawCard(G.whoseTurn, &G);
	}

#if (NOISY_TEST == 1)
	printf("Testing handCard returns the correct card in hand.\n");
#endif	
	int h;
	for (h = 0; h < 5; h++) {
#if (NOISY_TEST == 1)
		printf("actual = %d, expected = %d\n", handCard(h, &G), G.hand[G.whoseTurn][h]);
#endif
		assert(handCard(h, &G) == G.hand[G.whoseTurn][h]);
	}

	return 0;
}	
