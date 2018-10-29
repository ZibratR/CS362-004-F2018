/*******************************************************************************
** Program: HW 3 - Unit Test numHandCards
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for the function 'numHandCards' in dominion.c.
*******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>


// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	// Set up variables
	struct gameState state;

	state.handCount[0] = 3;
	state.handCount[1] = 5;
	state.handCount[2] = 2;
	state.handCount[3] = 4;

	// Want to test that:
	// the numHandCards returns the correct number for each player.

	state.whoseTurn = 0;
	assert(numHandCards(&state) == 3);
#if (NOISY_TEST == 1)
	printf("Player 1's number of cards is correct. \n");
#endif

	state.whoseTurn = 1;
	assert(numHandCards(&state) == 5);
#if (NOISY_TEST == 1)
	printf("Player 2's number of cards is correct. \n");
#endif

	state.whoseTurn = 2;
	assert(numHandCards(&state) == 2);
#if (NOISY_TEST == 1)
	printf("Player 3's number of cards is correct. \n");
#endif

	state.whoseTurn = 3;
	assert(numHandCards(&state) == 4);
#if (NOISY_TEST == 1)
	printf("Player 4's number of cards is correct. \n");
#endif

	printf("All tests passed!\n");

	return 0;
}