/*******************************************************************************
** Program: HW 3 - Unit Test supplyCount
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for the function 'supplyCount' in dominion.c.
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
	// the supplyCount function returns the correct number.
	// It is not necessary to test all cards in this case.

	state->supplyCount[curse] = 5;
	state->supplyCount[adventurer] = 2;
	state->supplyCount[smithy] = 3;
	state->supplyCount[outpost] = 6;

	assert(supplyCount(curse, state) == 5);
#if (NOISY_TEST == 1)
	printf("Supply count for the curse card is correct. \n");
#endif

	assert(supplyCount(adventurer, state) == 2);
#if (NOISY_TEST == 1)
	printf("Supply count for the adventurer card is correct. \n");
#endif

	assert(supplyCount(smithy, state) == 3);
#if (NOISY_TEST == 1)
	printf("Supply count for the smithy card is correct. \n");
#endif

	assert(supplyCount(outpost, state) == 6);
#if (NOISY_TEST == 1)
	printf("Supply count for the outpost card is correct. \n");
#endif

	printf("All tests passed!\n");

	return 0;
}