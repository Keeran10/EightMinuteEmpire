#include "Cards.h"
#include <iostream>
#include <string>

void CardDriver(){

	Deck* deck = new Deck(5);
	deck->PrintDeck();

    Hand* hand = new Hand(deck);
	std::cout << "deck size: " << deck->GetDeck()->size() << std::endl;
	hand->PrintHand();

    hand->Exchange(0, 0, deck);
	hand->PrintHand();
	std::cout << "deck size: " << deck->GetDeck()->size() << std::endl;
}
