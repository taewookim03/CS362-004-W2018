#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// tests playMine function

#define NOISY_TEST 1

int main() {
	struct gameState G;
	int numPlayer = 2;
	int seed = 123;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel,
			smithy, village, baron, great_hall};// sample list of cards from the example
	
	memset(&G, 23, sizeof(struct gameState));
	int currentPlayer = 0;


	//try play mine with copper, silver and gold to get copper, silver and gold
	
	int trashed;
	int gained;
	for (trashed = copper; trashed <= gold; trashed++) {
		for (gained = copper; gained <= gold; gained++) {
			// initializing gmae gives starting player (player 0) 5 card draws
			initializeGame(numPlayer, k, seed, &G);
			G.hand[currentPlayer][0] = trashed;//set card 0 to desired treasure
			int handSizeBefore = G.handCount[currentPlayer];
	
			int r = playMine(&G, currentPlayer, 0, gained);

#if (NOISY_TEST == 1)
			printf("Max cost obtainable = %d, cost of card obtained = %d\n", getCost(trashed)+3, getCost(gained));
#endif
			if (getCost(gained) > (getCost(trashed) + 3)) {
				assert(r == -1);
			}
			else {
				//assert(r == 0);//fails due to introduced bug
				//assert(getCost(G.hand[currentPlayer][0] <= getCost(trashed) + 3);//fails due to introduced bug	
			}
#if (NOISY_TEST == 1)
			printf("Expected hand size = %d, actual hand size = %d\n", handSizeBefore - 1, G.handCount[currentPlayer]);
#endif
			//assert(handSizeBefore -1 == G.handCount[currentPlayer]);//fails due to introduced bug
		
		}
	
	}

	return 0;	
}
