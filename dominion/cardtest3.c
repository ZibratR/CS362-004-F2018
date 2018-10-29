/*******************************************************************************
** Program: HW 3 - Card Test 3
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for village in dominion.c.
*******************************************************************************/

#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Village"

int main() {

	struct gameState* state;
	int numPlayers = 2;
	int kingdomCards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
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
	state->hand[currentPlayer][0] = village;

	int actions = state->numActions;

	// Run function.
	int returnValue = cardEffect(village, 0, 0, 0, state, 0, 0);
/*******************************************************************************
* TEST 1 - Check that 1 new card was drawn into hand (village discarded).
*******************************************************************************/

	// Check that hand count is now 1. 
	assert(state->handCount[currentPlayer] == 1);
	printf("1 card drawn. \n");

/*******************************************************************************
* TEST 2 - Check that new cards are not village.
*******************************************************************************/
	// Each new card is not a village.  
	assert(state->hand[currentPlayer][0] != village);
	printf("That 1 card is not the village - it was discarded. \n");

/*******************************************************************************
* TEST 3 - Check that 2 actions were added.
*******************************************************************************/
	// The current player should now have 2 additional actions.  
	assert(state->numActions == actions + 2);
	printf("Player has 2 additional actions. \n");

/*******************************************************************************
* TEST 4 - Check return value.
*******************************************************************************/
	// The value should be 0.  
	assert(returnValue == 0);
	printf("Return value is 0 (supposed to be 0). \n");


	printf("\n **All tests passed for the %s card.** \n\n", TESTCARD);


	return 0;
}


