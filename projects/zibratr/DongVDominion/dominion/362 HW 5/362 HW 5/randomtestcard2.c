/*******************************************************************************
** Program: HW 4 - Random Test: Smithy
** Author: Rozalija Zibrat
** Date: 14 November 2018
** Description: Random tester for the card Smithy.
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

		int currentPlayer = 1;
		state.whoseTurn = currentPlayer;

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

		state.handCount[currentPlayer] = 0;

		// Give player between 1 and 5 cards.  (The Smithy could be the first or last card played)
		int randomHandCount = rand() % 5 + 1;
		// Draw cards.
		for (int i = 0; i < randomHandCount; i++)
		{
			drawCard(currentPlayer, &state);
		}

		// Force player to have at least one Smithy.
		state.hand[currentPlayer][0] = smithy;

		int handBefore = state.handCount[currentPlayer];

		// Run function.
		int returnValue = cardEffect(smithy, 0, 0, 0, &state, 0, 0);
		/*******************************************************************************
		* TEST 1 - Check that 3 new cards were drawn into hand (smithy discarded).
		*******************************************************************************/
		// Check that hand has 3 new cards. (3 drawn and smithy removed.)
		assert(state.handCount[currentPlayer] == handBefore + 2);
		printf("4 (this is a bug from previous assignment - should be 3) cards drawn. \n");

		/*******************************************************************************
		* TEST 2 - Check that smithy was discarded
		*******************************************************************************/ 
		assert(state.playedCardCount == 1  && state.playedCards[0] == smithy);
		printf("Smithy was played (will be discarded). \n");

		/*******************************************************************************
		* TEST 3 - Check return value.
		*******************************************************************************/
		// The value should be 0.  
		assert(returnValue == 0);
		printf("Return value is 0 (supposed to be 0). \n");
	}

	printf("\n **All tests passed for the %s card.** \n\n", TESTCARD);


	return 0;
}