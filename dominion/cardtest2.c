/*******************************************************************************
** Program: HW 3 - Card Test 2
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for smithy in dominion.c.
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Smithy"

int main() {

	struct gameState* state;
	int numPlayers = 2;
	int kingdomCards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int randomSeed = 1000;

	//Initialize a test game.  Players are given 7 copper cards and 3 estates.
	initializeGame(numPlayers, kingdomCards, randomSeed, state);

	int currentPlayer = 0;

	// Set the hand to have one smithy card and nothing else.
	discardCard(4, currentPlayer, state, 0);
	discardCard(3, currentPlayer, state, 0);
	discardCard(2, currentPlayer, state, 0);
	discardCard(1, currentPlayer, state, 0);
	state->hand[currentPlayer][0] = smithy;
	
	// Run function.
	int returnValue = cardEffect(smithy, 0, 0, 0, state, 0, 0);
/*******************************************************************************
* TEST 1 - Check that 3 new cards were drawn into hand (smithy discarded).
*******************************************************************************/

	// Check that hand count is now 3. (3 drawn and smithy removed.)
	assert(state->handCount[currentPlayer] == 3);
	printf("3 cards drawn. \n");

/*******************************************************************************
* TEST 2 - Check that new cards are not smithy.
*******************************************************************************/
	// Each new card is not a smithy.  
	assert(state->hand[currentPlayer][0] != smithy);
	assert(state->hand[currentPlayer][1] != smithy);
	assert(state->hand[currentPlayer][2] != smithy);
	printf("Those 3 cards are not the smithy - it was discarded. \n");

/*******************************************************************************
* TEST 3 - Check return value.
*******************************************************************************/
	// The value should be 0.  
	assert(returnValue == 0);
	printf("Return value is 0 (supposed to be 0). \n");


	printf("\n **All tests passed for the %s card.** \n\n", TESTCARD);


	return 0;
}


