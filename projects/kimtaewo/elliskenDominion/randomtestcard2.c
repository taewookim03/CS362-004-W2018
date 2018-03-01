#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define NUM_TESTS 1000

int checkPlayVillage(struct gameState *G, int p, int handPos) {
	int h = G->handCount[p];
	int numActionsBefore = G->numActions;
	int played = G->playedCardCount;
	
	int r = playVillage(G, p, handPos);
	assert(r == 0);
	assert(h == G->handCount[p]);
	assert(G->numActions == numActionsBefore + 2);
	assert(G->playedCardCount == played + 1);
	return 0;
}

int main() {
	SelectStream(2);
	PutSeed(time(NULL));	

	printf("Random Testing Village\n");

	struct gameState G;
	
	int i, n, p;
	for (n = 0; n < NUM_TESTS; n++) {
		memset(&G, 23, sizeof(struct gameState));

		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(Random() * 2);
		G.whoseTurn = p;
		G.deckCount[p] = floor(Random() * MAX_DECK);// at least 1 card in the deck
		G.discardCount[p] = floor(Random() * MAX_DECK);
		G.handCount[p] = floor(Random() * (MAX_HAND - 1)) + 1;// at least 1 card in hand
		G.playedCardCount = floor(Random() * MAX_DECK);
  	
		//make sure all cards in deck, discardpile and hand are valid cards
		int j;
		for (j = 0; j < G.handCount[p]; j++){
			G.hand[p][j] = floor(Random() * treasure_map);
		}
		for (j = 0; j < G.deckCount[p]; j++){
		G.deck[p][j] = floor(Random() * treasure_map);
		}
		for (j = 0; j < G.discardCount[p]; j++){
			G.discard[p][j] = floor(Random() * treasure_map);
		}
		//put a Village in hand
		int r = floor(Random() * G.handCount[p]);
		G.hand[p][r] = smithy;
		checkPlayVillage(&G, p, r);
	}
	
	printf("ALL TESTS OK\n");

	exit(0);

	return 0;
}
