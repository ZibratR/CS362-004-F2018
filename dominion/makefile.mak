CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)	
	
playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	  
unittest2: unittest2.c dominion.o rngs.o
      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	  
unittest3: unittest3.c dominion.o rngs.o
      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	  
unittest4: unittest4.c dominion.o rngs.o
      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	  
cardtest1: cardtest1.c dominion.o rngs.o
      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	  
cardtest4: cardtest4.c dominion.o rngs.o
      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
	  
unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out