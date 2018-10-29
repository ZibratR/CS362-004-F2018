/*******************************************************************************
** Program: HW 3 - Unit Test isGameOver
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for the function 'isGameOver' in dominion.c.
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
	struct gameState* state;

	// Want to test that:
	// provinces == 0 => returns 1
	// if 3 supply piles are empty returns 1
	// otherwise return 0

	// Set all the supply counts to 5
	int i;
	for (i = 0; i < treasure_map; i++)
	{
		state->supplyCount[i] = 5 ;
	}

	// Check that we get back 0 when we have cards in each supply
	int returnedValue = isGameOver(state);
	assert(returnedValue == 0);

#if (NOISY_TEST == 1)
	printf("Supply counts are not empty. The game is not over. \n");
#endif

	//Clear out three piles and check that we get 1 back
	state->supplyCount[baron] = 0;
	state->supplyCount[adventurer] = 0;
	state->supplyCount[mine] = 0;
	int returnedValue = isGameOver(state);
	assert(returnedValue == 1);

#if (NOISY_TEST == 1)
	printf("3 card stacks are empty. The game is over. \n");
#endif

	//Reset the barons and make sure that we get back a 0 again.
	state->supplyCount[baron] = 5;
	int returnedValue = isGameOver(state);
	assert(returnedValue == 0);

#if (NOISY_TEST == 1)
	printf("Only 2 card stacks are empty. The game is not over. \n");
#endif

	//Remove all the provinces and check that we get back 1
	state->supplyCount[province] = 0;
	int returnedValue = isGameOver(state);
	assert(returnedValue == 1);

#if (NOISY_TEST == 1)
	printf("Province stack is empty. The game is over. \n");
#endif

	//Return the provinces to 5 and check that we still get 0
	state->supplyCount[province] = 5;
	int returnedValue = isGameOver(state);
	assert(returnedValue == 0);

#if (NOISY_TEST == 1)
	printf("Province stack is not empty. The game is not over. \n");
#endif


	printf("All tests passed!\n");

	return 0;
}