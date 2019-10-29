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

Card::Card(string resource, string action, int move = 0, int add = 0, bool destroy = false, 
	bool build = false, bool five = false, bool by_ship = false, bool OR = false, bool AND = false) 
	: move(move), add(add), destroy(destroy), build(build), isFivePlayer(five), by_ship(by_ship), OR(OR), AND(AND)
{
	this->resource = new string(resource);
	this->action = new string(action);
}

//Destructor for Cards class 
Card::~Card() 
{
}

/*
Default constructor for Deck Class
Initalized all 42 cards of the deck and pushes them into the vector. 
*/
Deck::Deck(int num_players) 
{
	Card card3;
	Card card16;
	Card card26;
	Card card30;
	Card card39;
	//8 FORREST Cards
	Card card1 = Card("FOREST", "move 3 armies", 3);
	Card card2 = Card("FOREST", "add 3 armies", 0, 3);
	if(num_players == 5)
		card3 = Card("FOREST", "move 6 armies", 6, 0, false, false, true); //** means add this card in a five player game.
	Card card4 = Card("FOREST", "destroy 1 army OR build city", 0, 0, true, true, false, false, true, false);
	Card card5 = Card("FOREST", "add 2 armies OR move 3 armies", 3, 2, false, false, false, false, true, false);
	Card card6 = Card("FOREST", "move 4 armies via ship", 4, 0, false, false, false, true);
	Card card7 = Card("FOREST", "build city", 0, 0, false, true);
	Card card8 = Card("FOREST", "move 3 armies via ship", 3, 0, false, false, false, true);
	//10 CARROT Card
	Card card9 = Card("CARROT", "build city", 0, 0, false, true);
	Card card10 = Card("CARROT", "destroy 1 army AND add 1 army", 0, 1, true, false, false, false, false, true);
	Card card11 = Card("CARROT", "add 3 armies", 0, 3);
	Card card12 = Card("CARROT", "move 4 armies", 4);
	Card card13 = Card("CARROT", "move 5 armies", 5);
	Card card14 = Card("2CARROT", "add 3 armies", 0, 3); //double CARROT card
	Card card15 = Card("CARROT", "move 3 armies via ship", 3, 0, false, false, false, true);
	if (num_players == 5)
		card16 = Card("CARROT", "add 4 armies OR move 2 armies", 2, 4, false, false, true, false, true, false); //** means add this card in a five player game.
	Card card17 = Card("CARROT", "move 4 armies", 4);
	Card card18 = Card("CARROT", "build city", 0, 0, false, true);
	//9 ANVIL Card
	Card card19 = Card("ANVIL", "move 4 armies", 4);
	Card card20 = Card("ANVIL", "add 3 armies OR move 4 armies", 4, 3, false, false, false, false, true, false);
	Card card21 = Card("ANVIL", "move 5 armies", 5);
	Card card22 = Card("ANVIL", "add 3 armies", 0, 3);
	Card card23 = Card("ANVIL", "add 3 armies", 0, 3);
	Card card24 = Card("ANVIL", "move 3 armies via ship", 3, 0, false, false, false, true);
	Card card25 = Card("ANVIL", "build city", 0, 0, false, true);
	if (num_players == 5)
		card26 = Card("2ANVIL", "move 4 armies", 4, 0, false, false, true); //**double ANVIL card. Add this card in five player game.
	Card card27 = Card("ANVIL", "add 3 armies OR move 3 armies", 3, 3, false, false, false, false, true, false);
	//7 ORE Card
	Card card28 = Card("ORE", "move 2 armies", 2);
	Card card29 = Card("ORE", "move 3 armies via ship", 3, 0, false, false, false, true);
	if (num_players == 5)
		card30 = Card("ORE", "move 2 armies via ship", 2, 0, false, false, true, true); //** means add this card in a five player game.
	Card card31 = Card("ORE", "move 2 armies via ship", 2, 0, false, false, false, true);
	Card card32 = Card("ORE", "add 3 armies", 0, 3);
	Card card33 = Card("ORE", "add 3 armies", 0, 3);
	Card card34 = Card("ORE", "add 2 armies", 0, 2);
	//5 CRYSTAL Card
	Card card35 = Card("CRYSTAL", "add 2 armies", 0, 2);
	Card card36 = Card("CRYSTAL", "add 2 armies", 0, 2);
	Card card37 = Card("CRYSTAL", "move 2 armies", 2, 0);
	Card card38 = Card("CRYSTAL", "add 1 army", 0, 1);
	if (num_players == 5)
		card39 = Card("CRYSTAL", "add 2 armies", 0, 2, false, false, true, false); //** means add this card in a five player game.
   //3 WILD Card
	Card card40 = Card("WILD", "move 2 armies", 2);
	Card card41 = Card("WILD", "move 2 armies", 2);
	Card card42 = Card("WILD", "add 2 armies", 0, 2);
	//TOTAL OF: 42 Cards. 

	cards = new vector<Card>();
	/**/
	cards->push_back(card1);
	cards->push_back(card2);
	if (num_players == 5)
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
	if (num_players == 5)
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
	if (num_players == 5)
		cards->push_back(card26);
	cards->push_back(card27);
	cards->push_back(card28);
	cards->push_back(card29);
	if (num_players == 5)
		cards->push_back(card30);
	cards->push_back(card31);
	cards->push_back(card32);
	cards->push_back(card33);
	cards->push_back(card34);
	cards->push_back(card35);
	cards->push_back(card36);
	cards->push_back(card37);
	cards->push_back(card38);
	if (num_players == 5)
		cards->push_back(card39);
	cards->push_back(card40);
	cards->push_back(card41);
	cards->push_back(card42);
	/**/
}

pair<string, int> Card::ReadCardAction()
{
	pair<string, int> read = { "default", 0 };

	if (this->AND) return this->ReadCardActionOR();
	if (this->OR) return this->ReadCardActionOR();
	
	// this means I move over water
	if (this->move != 0 && this->by_ship)
	{
		read.first = "move_by_sea";
		read.second = this->move;
		return read;
	}
	// this means I move over land 
	if (this->move != 0 && !this->by_ship)
	{
		read.first = "move_by_land";
		read.second = this->move;
		return read;
	}
	// this means I add armies
	if (this->add != 0)
	{
		read.first = "add";
		read.second = this->add;
		return read;
	}
	// this means I destroy an army
	if (this->destroy)
	{
		read.first = "destroy";
		read.second = 0;
		return read;
	}
	// this means I build a city
	if (this->build)
	{
		read.first = "build";
		read.second = 0;
		return read;
	}

	return read;
}

// OR action cards handled differently. Read stores two integers together. 
// example: move=3 OR add=4. To return two data into an int, we can do 3*10 + 4 = 34.
// knowing that no card value is greater than 10, we can retrieve move and add from 34 like this:
// add = 34%10 = 4; move = (34-add)/10;
pair<string, int> Card::ReadCardActionOR()
{
	pair<string, int> read = {"default", 0};

	if (this->move != 0 && this->add != 0)
	{
		read.first = "move_or_add";
		read.second = this->move * 10 + this->add; 
		return read;
	}

	if (this->destroy && this->build)
	{
		read.first = "build_or_destroy";
		read.second = 0;
		return read;
	}
	
	return read;
}

// AND action cards handled differently. Check OR comments for clarifications. 
pair<string, int> Card::ReadCardActionAND()
{
	pair<string, int> read = { "default", 0 };

	if (this->destroy && this->add != 0)
	{
		read.first = "add_and_destroy";
		read.second = this->add;
		return read;
	}

	return read;
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
	cout << "\n-----------------------------------------" << endl;
	cout << "*DECK* " << endl;
	cout << "-----------------------------------------" << endl;
	for (auto& card : *cards)
	{
		cout << ++ctr << ": " << card.GetResource() << " & " << card.GetAction() << endl;
	}
	cout << endl;
}

Hand::Hand() {}

// takes 6 cards from deck for initial hand on board
Hand::Hand(Deck* deck)
{
	hand = new vector<Card>();

	for (int i = 0; i < 6; i++)
	{
		hand->push_back(deck->draw());
	}
}

Hand::~Hand() 
{
}

// Player exchange coins for hand card. Once card is chosen, everything shifts to the left.
Card* Hand::Exchange(int index, int coins, Deck* deck) 
{
	int cost;

	if (index == 0) cost = 0;
	else if (index == 1 || index == 2) cost = 1;
	else if (index == 3 || index == 4) cost = 2;
	else if (index == 5) cost = 3;
	else 
	{
		cout << "Failed to provide a card position." << endl;
		return NULL;
	}
	
	if (coins != cost)
	{
		cout << "Failed to provide payment." << endl;
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

	cout << "Bought card: { " << card->GetResource() << " | " << card->GetAction() << " }" << endl;
	return card;
}

void Hand::PrintHand()
{
	if (!hand) return;

	cout << "\n-----------------------------------------" << endl;
	cout << "*HAND* " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "cost = 0 card: " << hand->at(0).GetResource() << " & " << hand->at(0).GetAction() << endl;
	cout << "cost = 1 card: " << hand->at(1).GetResource() << " & " << hand->at(1).GetAction() << endl;
	cout << "cost = 1 card: " << hand->at(2).GetResource() << " & " << hand->at(2).GetAction() << endl;
	cout << "cost = 2 card: " << hand->at(3).GetResource() << " & " << hand->at(3).GetAction() << endl;
	cout << "cost = 2 card: " << hand->at(4).GetResource() << " & " << hand->at(4).GetAction() << endl;
	cout << "cost = 3 card: " << hand->at(5).GetResource() << " & " << hand->at(5).GetAction() << endl;
	cout << endl;
}

void CardsDriver() {

	Deck* deck = new Deck(5);
	deck->PrintDeck();

	Hand* hand = new Hand(deck);
	cout << "deck size: " << deck->GetDeck()->size() << endl;
	hand->PrintHand();

	hand->Exchange(0, 0, deck);
	hand->PrintHand();
	cout << "deck size: " << deck->GetDeck()->size() << endl;
}