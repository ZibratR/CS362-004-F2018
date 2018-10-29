/*******************************************************************************
** Program: HW 3 - Unit Test getCost
** Author: Rozalija Zibrat
** Date: 28 October 2018
** Description: Unit test for the function 'getCost' in dominion.c.
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
	// a number lower and higher than treasure_map returns -1
	// each card returns the associated cost.

	assert(getCost(-1) == -1);

	assert(getCost(curse) == 0);

	assert(getCost(estate) == 2);

	assert(getCost(duchy) == 5);

	assert(getCost(province) == 8);

	assert(getCost(copper) == 0);

	assert(getCost(silver) == 3);

	assert(getCost(gold) == 6);

	assert(getCost(adventurer) == 6);

	assert(getCost(council_room) == 5);

	assert(getCost(feast) == 4);

	assert(getCost(gardens) == 4);

	assert(getCost(mine) == 5);

	assert(getCost(remodel) == 4);

	assert(getCost(smithy) == 4);

	assert(getCost(village) == 3);

	assert(getCost(baron) == 4);

	assert(getCost(great_hall) == 3);

	assert(getCost(minion) == 5);

	assert(getCost(steward) == 3);

	assert(getCost(tribute) == 5);

	assert(getCost(ambassador) == 3);

	assert(getCost(cutpurse) == 4);

	assert(getCost(embargo) == 2);

	assert(getCost(outpost) == 5);

	assert(getCost(salvager) == 4);

	assert(getCost(sea_hag) == 4);

	assert(getCost(treasure_map) == 4);

	assert(getCost(treasure_map + 1) == -1);
#if (NOISY_TEST == 1)
	printf("The cost of all cards are correct. \n");
#endif

	printf("All tests passed!\n");

	return 0;
}