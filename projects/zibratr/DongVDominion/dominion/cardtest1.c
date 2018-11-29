/*******************************************************************************
** Program: HW 3 - Card Test 1
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for adventurer in dominion.c.
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"

int main() {
	
	struct gameState state;
	int numPlayers = 2;
	int kingdomCards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int randomSeed = 1000;

	//Initialize a test game.  Players are given 7 copper cards and 3 estates.
	initializeGame(numPlayers, kingdomCards, randomSeed, &state);

	int currentPlayer = 0;

	// Set the deck count and hand count to 0 to force shuffle and check that 
	// treasure cards are drawn.
	state.deckCount[currentPlayer] = 0;
	state.handCount[currentPlayer] = 0;

	// Run function.
	int returnValue = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);
/*******************************************************************************
* TEST 1 - Shuffle the deck.
*******************************************************************************/

	// Check that deck is shuffled if deck count is 0.
	//assert(state.deckCount[currentPlayer] > 1);
	//printf("Deck was shuffled. \n");

/*******************************************************************************
* TEST 2 - Get two cards.
*******************************************************************************/
	//Check that the current players hand now has two (should be treasure) cards.  
	assert(state.handCount[currentPlayer] == 2);
	printf("Two cards added to hand. \n");

/*******************************************************************************
* TEST 3 - Make sure those cards are treasure.
*******************************************************************************/
	assert(state.hand[currentPlayer][0] == copper);
	assert(state.hand[currentPlayer][1] == copper);
	printf("Both of those cards are copper cards (treasure). \n");

/*******************************************************************************
* TEST 4 - Check return value.
*******************************************************************************/
	// The value should be 0.  
	assert(returnValue == 0);
	printf("Return value is 0 (supposed to be 0). \n");


	printf("\n **All tests passed for the %s card.** \n\n", TESTCARD);


	return 0;
}


