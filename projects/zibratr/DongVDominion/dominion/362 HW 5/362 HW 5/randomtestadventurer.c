/*******************************************************************************
** Program: HW 4 - Random Test: Adventurer
** Author: Rozalija Zibrat
** Date: 14 November 2018
** Description: Random tester for the card Adventurer.
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

	int runThisManyTimes = 500;
	
	int k;
	for (k = 0; k <runThisManyTimes; k++)
	{
		printf("\n\n\nTEST # %d\n", k);

		struct gameState state;
		int numPlayers = 2;
		int kingdomCards[10] = { adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room };
		int randomSeed = 1000;

		//Initialize a test game.  Players are given 7 copper cards and 3 estates.
		// Players do not draw 5 cards at start however. Code is commented out.
		initializeGame(numPlayers, kingdomCards, randomSeed, &state);

		int treasureBefore = 0,
			treasureAfter = 0;
	
		int currentPlayer = 1;
		state.whoseTurn = currentPlayer;

		state.handCount[currentPlayer] = 0;

		// I considered removing the player's inital cards and giving them an entirely random deck, 
		// however each player WILL be given an initial deck during setup.

		// Add between 0 and 20 new cards to the player's deck.
		int numNewCards = rand() % 21;
		int deckIndex = 10;

		for (int i = 0; i < numNewCards; i++)
		{
			// adding random card - 10 allowed cards + plus 3 treasure
			int randomCard = rand() % 13;

			if (randomCard == 10)
			{
				state.deck[currentPlayer][deckIndex] = copper;
			}
			else if (randomCard == 11)
			{
				state.deck[currentPlayer][deckIndex] = silver;
			}
			else if (randomCard == 12)
			{
				state.deck[currentPlayer][deckIndex] = gold;
			}
			else
			{
				state.deck[currentPlayer][deckIndex] = kingdomCards[randomCard];
			}

			state.deckCount[currentPlayer]++;
		}

		// Shuffle the cards before drawing.
		shuffle(currentPlayer, &state);

		// Give player between 1 and 5 cards.  (The adventurer could be the first or last card played)
		int randomHandCount = rand() % 5 + 1;
		// Draw cards.
		for (int i = 0; i < randomHandCount; i++)
		{
			drawCard(currentPlayer, &state);
		}

		// Force player to have at least one adventurer.
		state.hand[currentPlayer][0] = adventurer;

		// Count treasure before playing adventurer.
		for (int i = 0; i < randomHandCount; i++)
		{
			if (state.hand[currentPlayer][i] == copper ||
				state.hand[currentPlayer][i] == silver ||
				state.hand[currentPlayer][i] == gold)
			{
				treasureBefore++;
			}
		}



		int deckBefore = state.deckCount[currentPlayer];
		int handBefore = state.handCount[currentPlayer];

		// Run function.
		int returnValue = cardEffect(adventurer, 0, 0, 0, &state, 0, 0);
		/*******************************************************************************
		* OPTIONAL TEST 1 - Shuffle the deck.
		*******************************************************************************/

		// Check that deck is shuffled if deck count is 0.
		//if (deckBefore <= 1)
		//assert(state.deckCount[currentPlayer] > 1);
		//printf("Deck was shuffled. \n");

		/*******************************************************************************
		* TEST 2 - Get two cards.
		*******************************************************************************/
		//Check that the current players hand now has two (should be treasure) cards.  
		assert(state.handCount[currentPlayer] == handBefore + 2);
		printf("3 cards added to hand. (This is a bug introduced in assignment 1. Should be 2 cards) \n");

		/*******************************************************************************
		* TEST 3 - Make sure those cards are treasure.
		*******************************************************************************/
		for (int i = 0; i < (randomHandCount + 3); i++)
		{
			if (state.hand[currentPlayer][i] == copper ||
				state.hand[currentPlayer][i] == silver ||
				state.hand[currentPlayer][i] == gold)
			{
				treasureAfter++;
			}
		}
	
		//printf("\nTreasure BEFORE %d\n", treasureBefore);
		//printf("\nTreasure AFTER %d\n", treasureAfter);

		assert(treasureAfter == treasureBefore + 2);
		printf("3 treasures added to hand. (This is a bug introduced in assignment 1. Should be 2) \n");
		/*******************************************************************************
		* TEST 4 - Check return value.
		*******************************************************************************/
		// The value should be 0.  
		assert(returnValue == 0);
		printf("Return value is 0 (supposed to be 0). \n");
	}

	printf("\n **All tests passed for the %s card.** \n\n", TESTCARD);


	return 0;
}
