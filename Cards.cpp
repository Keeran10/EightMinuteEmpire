#include "Cards.h"
#include <iostream>
#include <algorithm>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctime>
#include <cstdlib>

/*
Default constructor for Cards class
*/
Card::Card() 
{
}

//Two parameter constructor for Cards class
Card::Card(std::string resource, std::string action) 
{
	this->resource = new std::string(resource);
	this->action = new std::string(action);
}

//Destructor for Cards class 
Card::~Card() 
{
}

/*
Default constructor for Deck Class
Initalized all 42 cards of the deck and pushes them into the vector. 
*/
Deck::Deck() 
{
	//8 FORREST Cards
	Card card1 = Card("FOREST", "move 3 armies");
	Card card2 = Card("FOREST", "add 3 armies");
	Card card3 = Card("FOREST", "move 6 armies**"); //** means add this card in a five player game.
	Card card4 = Card("FOREST", "destroy 1 army OR build city");
	Card card5 = Card("FOREST", "add 2 armies OR move 3 armies");
	Card card6 = Card("FOREST", "move 4 armies via ship");
	Card card7 = Card("FOREST", "build city");
	Card card8 = Card("FOREST", "move 3 armies via ship");
	//10 CARROT Card
	Card card9 = Card("CARROT", "build city");
	Card card10 = Card("CARROT", "destroy 1 army AND add 1 army");
	Card card11 = Card("CARROT", "add 3 armies");
	Card card12 = Card("CARROT", "move 4 armies");
	Card card13 = Card("CARROT", "move 5 armies");
	Card card14 = Card("CARROT", "add 3 armies"); //double CARROT card
	Card card15 = Card("CARROT", "move 3 armies via ship");
	Card card16 = Card("CARROT", "add 4 armies OR move 2 armies**"); //** means add this card in a five player game.
	Card card17 = Card("CARROT", "move 4 armies");
	Card card18 = Card("CARROT", "build city");
	//9 ANVIL Card
	Card card19 = Card("ANVIL", "move 4 armies");
	Card card20 = Card("ANVIL", "add 3 armies OR move 4 armies");
	Card card21 = Card("ANVIL", "move 5 armies");
	Card card22 = Card("ANVIL", "add 3 armies");
	Card card23 = Card("ANVIL", "add 3 armies");
	Card card24 = Card("ANVIL", "move 3 armies via ship");
	Card card25 = Card("ANVIL", "build city");
	Card card26 = Card("ANVIL", "move 4 armies (double)**"); //double ANVIL card. Add this card in five player game.
	Card card27 = Card("ANVIL", "add 3 armies OR move 3 armies");
	//7 ORE Card
	Card card28 = Card("ORE", "move 2 armies");
	Card card29 = Card("ORE", "move 3 armies via ship");
	Card card30 = Card("ORE", "move 2 armies via ship**"); //** means add this card in a five player game.
	Card card31 = Card("ORE", "move 2 armies via ship");
	Card card32 = Card("ORE", "add 3 armies");
	Card card33 = Card("ORE", "add 3 armies");
	Card card34 = Card("ORE", "add 2 armies");
	//5 CRYSTAL Card
	Card card35 = Card("CRYSTAL", "add 2 armies");
	Card card36 = Card("CRYSTAL", "add 2 armies");
	Card card37 = Card("CRYSTAL", "move 2 armies");
	Card card38 = Card("CRYSTAL", "add 1 army");
	Card card39 = Card("CRYSTAL", "add 2 armies **"); //** means add this card in a five player game.
   //3 WILD Card
	Card card40 = Card("WILD", "move 2 armies");
	Card card41 = Card("WILD", "move 2 armies");
	Card card42 = Card("WILD", "add 2 armies");
	//TOTAL OF: 42 Cards. 

	cards = new std::vector<Card>();
	/**/
	cards->push_back(card1);
	cards->push_back(card2);
	cards->push_back(card3);
	cards->push_back(card4);
	cards->push_back(card5);
	cards->push_back(card6);
	cards->push_back(card7);
	cards->push_back(card8);
	cards->push_back(card9);
	cards->push_back(card10);
	cards->push_back(card11);
	cards->push_back(card12);
	cards->push_back(card13);
	cards->push_back(card14);
	cards->push_back(card15);
	cards->push_back(card16);
	cards->push_back(card17);
	cards->push_back(card18);
	cards->push_back(card19);
	cards->push_back(card20);
	cards->push_back(card21);
	cards->push_back(card22);
	cards->push_back(card23);
	cards->push_back(card24);
	cards->push_back(card25);
	cards->push_back(card26);
	cards->push_back(card27);
	cards->push_back(card28);
	cards->push_back(card29);
	cards->push_back(card30);
	cards->push_back(card31);
	cards->push_back(card32);
	cards->push_back(card33);
	cards->push_back(card34);
	cards->push_back(card35);
	cards->push_back(card36);
	cards->push_back(card37);
	cards->push_back(card38);
	cards->push_back(card39);
	cards->push_back(card40);
	cards->push_back(card41);
	cards->push_back(card42);
	/**/
}

/*
Destructor for Deck class
*/
Deck::~Deck() 
{

}

/*
Implementation of draw method for Deck class. 
*/
Card Deck::draw()
{
	int size = cards->size();

	int index = rand() % size;

	Card card = cards->at(index);

	cards->erase(cards->begin() + index);

	return card;
}

void Deck::PrintDeck() 
{
	if (!cards) return;
	int ctr = 0;
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "*DECK* " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	for (auto& card : *cards)
	{
		std::cout << ++ctr << ": " << card.GetResource() << " & " << card.GetAction() << std::endl;
	}
	std::cout << std::endl;
}

Hand::Hand() {}

Hand::Hand(Deck* deck)
{
	hand = new std::vector<Card>();

	for (int i = 0; i < 6; i++)
	{
		hand->push_back(deck->draw());
	}
}

Hand::~Hand() 
{
}

Card* Hand::Exchange(int index, int coins, Deck* deck) 
{
	int cost;

	if (index == 0) cost = 0;
	else if (index == 1 || index == 2) cost = 1;
	else if (index == 3 || index == 4) cost = 2;
	else if (index == 5) cost = 3;
	else 
	{
		std::cout << "Failed to provide a card position." << std::endl;
		return NULL;
	}
	
	if (coins != cost)
	{
		std::cout << "Failed to provide payment." << std::endl;
		return NULL;
	}

	Card* card = &hand->at(index);

	// Shift everything left
	for (int i = index; i < 6; i++)
	{
		if (i == 5)
		{
			hand->erase(hand->begin() + 5);
			break;
		}
		hand->at(i) = hand->at(i + 1);
	}

	hand->push_back(deck->draw()); 

	std::cout << "Bought card: { " << card->GetResource() << " | " << card->GetAction() << " }" << std::endl;
	return card;
}

void Hand::PrintHand()
{
	if (!hand) return;

	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "*HAND* " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "cost = 0 card: " << hand->at(0).GetResource() << " & " << hand->at(0).GetAction() << std::endl;
	std::cout << "cost = 1 card: " << hand->at(1).GetResource() << " & " << hand->at(1).GetAction() << std::endl;
	std::cout << "cost = 1 card: " << hand->at(2).GetResource() << " & " << hand->at(2).GetAction() << std::endl;
	std::cout << "cost = 2 card: " << hand->at(3).GetResource() << " & " << hand->at(3).GetAction() << std::endl;
	std::cout << "cost = 2 card: " << hand->at(4).GetResource() << " & " << hand->at(4).GetAction() << std::endl;
	std::cout << "cost = 3 card: " << hand->at(5).GetResource() << " & " << hand->at(5).GetAction() << std::endl;
	std::cout << std::endl;
}

void CardsDriver() {

	Deck* deck = new Deck();
	deck->PrintDeck();

	Hand* hand = new Hand(deck);
	std::cout << "deck size: " << deck->GetDeck()->size() << std::endl;
	hand->PrintHand();

	hand->Exchange(0, 0, deck);
	hand->PrintHand();
	std::cout << "deck size: " << deck->GetDeck()->size() << std::endl;
}