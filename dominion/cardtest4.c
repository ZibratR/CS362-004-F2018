/*******************************************************************************
** Program: HW 3 - Card Test 4
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for gardens in dominion.c.
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Gardens"

int main() {

	struct gameState* state;
	int numPlayers = 2;
	int kingdomCards[10] = { adventurer, gardens, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int randomSeed = 1000;

	//Initialize a test game.  Players are given 7 copper cards and 3 estates.
	initializeGame(numPlayers, kingdomCards, randomSeed, state);

	int currentPlayer = 0;

	// Set the hand to have one village card and nothing else.
	discardCard(4, currentPlayer, state, 0);
	discardCard(3, currentPlayer, state, 0);
	discardCard(2, currentPlayer, state, 0);
	discardCard(1, currentPlayer, state, 0);
	state->hand[currentPlayer][0] = gardens;

	// Run function.
	int returnValue = cardEffect(gardens, 0, 0, 0, state, 0, 0);
	/*******************************************************************************
	* TEST 1 - Check return value.
	*******************************************************************************/
	// The value should be -1.  
	assert(returnValue == -1);
	printf("Return value is -1 (supposed to be -1). \n");


	printf("\n **All tests passed for the %s card.** \n\n", TESTCARD);


	return 0;
}


