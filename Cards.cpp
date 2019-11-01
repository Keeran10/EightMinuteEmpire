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
	: resource(resource), action(action), move(move), add(add), destroy(destroy), build(build), isFivePlayer(five), by_ship(by_ship), OR(OR), AND(AND)
{
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
	Card* card3;
	Card* card16;
	Card* card26;
	Card* card30;
	Card* card39;
	//8 FORREST Cards
	Card* card1 = new Card("FOREST", "move 3 armies", 3);
	Card* card2 = new Card("FOREST", "add 3 armies", 0, 3);
	if(num_players == 5)
		card3 = new Card("FOREST", "move 6 armies", 6, 0, false, false, true); //** means add this card in a five player game.
	Card* card4 = new Card("FOREST", "destroy 1 army OR build city", 0, 0, true, true, false, false, true, false);
	Card* card5 = new Card("FOREST", "add 2 armies OR move 3 armies", 3, 2, false, false, false, false, true, false);
	Card* card6 = new Card("FOREST", "move 4 armies via ship", 4, 0, false, false, false, true);
	Card* card7 = new Card("FOREST", "build city", 0, 0, false, true);
	Card* card8 = new Card("FOREST", "move 3 armies via ship", 3, 0, false, false, false, true);
	//10 CARROT Card
	Card* card9 = new Card("CARROT", "build city", 0, 0, false, true);
	Card* card10 = new Card("CARROT", "destroy 1 army AND add 1 army", 0, 1, true, false, false, false, false, true);
	Card* card11 = new Card("CARROT", "add 3 armies", 0, 3);
	Card* card12 = new Card("CARROT", "move 4 armies", 4);
	Card* card13 = new Card("CARROT", "move 5 armies", 5);
	Card* card14 = new Card("2CARROT", "add 3 armies", 0, 3); //double CARROT card
	Card* card15 = new Card("CARROT", "move 3 armies via ship", 3, 0, false, false, false, true);
	if (num_players == 5)
		card16 = new Card("CARROT", "add 4 armies OR move 2 armies", 2, 4, false, false, true, false, true, false); //** means add this card in a five player game.
	Card* card17 = new Card("CARROT", "move 4 armies", 4);
	Card* card18 = new Card("CARROT", "build city", 0, 0, false, true);
	//9 ANVIL Card
	Card* card19 = new Card("ANVIL", "move 4 armies", 4);
	Card* card20 = new Card("ANVIL", "add 3 armies OR move 4 armies", 4, 3, false, false, false, false, true, false);
	Card* card21 = new Card("ANVIL", "move 5 armies", 5);
	Card* card22 = new Card("ANVIL", "add 3 armies", 0, 3);
	Card* card23 = new Card("ANVIL", "add 3 armies", 0, 3);
	Card* card24 = new Card("ANVIL", "move 3 armies via ship", 3, 0, false, false, false, true);
	Card* card25 = new Card("ANVIL", "build city", 0, 0, false, true);
	if (num_players == 5)
		card26 = new Card("2ANVIL", "move 4 armies", 4, 0, false, false, true); //**double ANVIL card. Add this card in five player game.
	Card* card27 = new Card("ANVIL", "add 3 armies OR move 3 armies", 3, 3, false, false, false, false, true, false);
	//7 ORE Card
	Card* card28 = new Card("ORE", "move 2 armies", 2);
	Card* card29 = new Card("ORE", "move 3 armies via ship", 3, 0, false, false, false, true);
	if (num_players == 5)
		card30 = new Card("ORE", "move 2 armies via ship", 2, 0, false, false, true, true); //** means add this card in a five player game.
	Card* card31 = new Card("ORE", "move 2 armies via ship", 2, 0, false, false, false, true);
	Card* card32 = new Card("ORE", "add 3 armies", 0, 3);
	Card* card33 = new Card("ORE", "add 3 armies", 0, 3);
	Card* card34 = new Card("ORE", "add 2 armies", 0, 2);
	//5 CRYSTAL Card
	Card* card35 = new Card("CRYSTAL", "add 2 armies", 0, 2);
	Card* card36 = new Card("CRYSTAL", "add 2 armies", 0, 2);
	Card* card37 = new Card("CRYSTAL", "move 2 armies", 2, 0);
	Card* card38 = new Card("CRYSTAL", "add 1 army", 0, 1);
	if (num_players == 5)
		card39 = new Card("CRYSTAL", "add 2 armies", 0, 2, false, false, true, false); //** means add this card in a five player game.
   //3 WILD Card
	Card* card40 = new Card("WILD", "move 2 armies", 2);
	Card* card41 = new Card("WILD", "move 2 armies", 2);
	Card* card42 = new Card("WILD", "add 2 armies", 0, 2);
	//TOTAL OF: 42 Cards. 

	cards = new vector<Card*>();
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

	if (this->AND) return this->ReadCardActionAND();
	if (this->OR) return this->ReadCardActionOR();
	
	// move over water
	if (this->move != 0 && this->by_ship)
	{
		read.first = "move_by_sea";
		read.second = this->move;
		return read;
	}
	// move over land 
	if (this->move != 0 && !this->by_ship)
	{
		read.first = "move_by_land";
		read.second = this->move;
		return read;
	}
	// add armies
	if (this->add != 0)
	{
		read.first = "add";
		read.second = this->add;
		return read;
	}
	// destroy an army
	if (this->destroy)
	{
		read.first = "destroy";
		read.second = 1;
		return read;
	}
	// build a city
	if (this->build)
	{
		read.first = "build";
		read.second = 1;
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
		read.second = 1;
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
Card* Deck::draw()
{
	int size = cards->size();

	int index = rand() % size;

	Card* card = cards->at(index);

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
		cout << ++ctr << ": " << card->GetResource() << " & " << card->GetAction() << endl;
	}
	cout << endl;
}

Hand::Hand() {}

// takes 6 cards from deck for initial hand on board
Hand::Hand(Deck* deck)
{
	hand = new vector<Card*>();

	for (int i = 0; i < 6; i++)
	{
		hand->push_back(deck->draw());
	}
}

Hand::~Hand() 
{
}

// Player exchange coins for hand card. Once card is chosen, everything shifts to the left.
pair<Card*, int> Hand::Exchange(char index, int coins, Deck* deck) 
{
	int cost;
	int position = -1;
	pair<Card*, int> card_cost = { nullptr, -1 };

	if (index == '1') cost = 0;
	else if (index == '2' || index == '3') cost = 1;
	else if (index == '4' || index == '5') cost = 2;
	else if (index == '6') cost = 3;
	else 
	{
		cout << "Failed to provide a card position from 1 to 6." << endl;
		return card_cost;
	}
	
	position = index - '0';
	position--;

	if (position > 5)
	{
		cout << "conversion fail from char to int." << endl;
		return card_cost;
	}
	
	if (coins < cost)
	{
		cout << "Failed to provide sufficient funding. Player has " << coins << " coins while cost is "<< cost << "." << endl;
		return card_cost;
	}

	Card* card = hand->at(position);

	// Shift everything left
	for (int i = position; i < 6; i++)
	{
		if (i == 5)
		{
			hand->erase(hand->begin() + 5);
			break;
		}
		hand->at(i) = hand->at(i + 1);
	}

	hand->push_back(deck->draw()); 

	cout << "\nBought card: { " << card->GetResource() << " & " << card->GetAction() << " } for " << cost << " cost." << endl;
	
	card_cost.first = card;
	card_cost.second = cost;

	return card_cost;
}

void Hand::PrintHand()
{
	if (!hand) return;

	cout << "\n-----------------------------------------" << endl;
	cout << "*BOARD CARDS* " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1 - cost = 0 card: " << hand->at(0)->GetResource() << " & " << hand->at(0)->GetAction() << endl;
	cout << "2 - cost = 1 card: " << hand->at(1)->GetResource() << " & " << hand->at(1)->GetAction() << endl;
	cout << "3 - cost = 1 card: " << hand->at(2)->GetResource() << " & " << hand->at(2)->GetAction() << endl;
	cout << "4 - cost = 2 card: " << hand->at(3)->GetResource() << " & " << hand->at(3)->GetAction() << endl;
	cout << "5 - cost = 2 card: " << hand->at(4)->GetResource() << " & " << hand->at(4)->GetAction() << endl;
	cout << "6 - cost = 3 card: " << hand->at(5)->GetResource() << " & " << hand->at(5)->GetAction() << endl;
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