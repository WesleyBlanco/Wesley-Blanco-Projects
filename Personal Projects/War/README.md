# War

This is the folder for the Card game war. 

## Current development notes

The card.h file is here as it is the only completed piece of the program. The program will have a .cpp file that runs the game entirely. At this time, that .cpp file exists but is not currently running properly. The .cpp file will be included when the code has been refactored.


#### What is War?

War is a very simple two player card game. In War, each player is dealt half of a deck of cards. Players shuffle their decks and then play. Players do not see their cards until they are flipped from the top of their own deck. Players flip the top card of their deck and compare them. Whichever player has the higher value card takes both cards and places them into a spoils deck. When a player runs out of cards in their primary deck they shuffle their spoils deck and it becomes their primary deck. Should the players both place down identical value cards, a war begins. Wars force both players to place down 3 cards face down and then a final card faced up. This final card flip acts like any other card flip, and whoever wins this card flip will win the cards that are facing downwards. Wars can occur ontop of other wars. Should a player be unable to place down 3 cards and reveal a fourth card, they lose by default.
