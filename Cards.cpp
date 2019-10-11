#include "Cards.h"
#include <iostream>
#include <algorithm>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Default constructor for Cards class
*/
Cards::Cards() 
{
    *resource = nullptr;
    *actions = nullptr;
}

//Two parameter constructor for Cards class
Cards::Cards(string *resource, string *actions) : resource(resource), actions(actions) 
{

}

//Destructor for Cards class 
Cards::~Cards() 
{
    delete resource;
    delete actions;
}

std::ostream &operator<<(std::ostream &os, const Cards &cards) 
{
    os << "Resource is: " << cards.resource << " Action is: " << cards.actions;
    return os;
}

/*
Default constructor for Deck Class
Initalized all 42 cards of the deck and pushes them into the vector. 
*/
Deck::Deck() 
{
    //8 FORREST Cards
    const Cards card1 = Cards((string *) "FOREST", (string *) "move 3 armies");
    const Cards card2 = Cards((string *) "FOREST", (string *) "add 3 armies");
    const Cards card3 = Cards((string *) "FOREST", (string *) "move 6 armies**"); //** means add this card in a five player game.
    const Cards card4 = Cards((string *) "FOREST", (string *) "destroy 1 army OR build city");
    const Cards card5 = Cards((string *) "FOREST", (string *) "add 2 armies OR move 3 armies");
    const Cards card6 = Cards((string *) "FOREST", (string *) "move 4 armies via ship");
    const Cards card7 = Cards((string *) "FOREST", (string *) "build city");
    const Cards card8 = Cards((string *) "FOREST", (string *) "move 3 armies via ship");
    //10 CARROT Cards
    const Cards card9 = Cards((string *) "CARROT", (string *) "build city");
    const Cards card10 = Cards((string *) "CARROT", (string *) "destroy 1 army AND add 1 army");
    const Cards card11 = Cards((string *) "CARROT", (string *) "add 3 armies");
    const Cards card12 = Cards((string *) "CARROT", (string *) "move 4 armies");
    const Cards card13 = Cards((string *) "CARROT", (string *) "move 5 armies");
    const Cards card14 = Cards((string *) "CARROT", (string *) "add 3 armies"); //double CARROT card
    const Cards card15 = Cards((string *) "CARROT", (string *) "move 3 armies via ship");
    const Cards card16 = Cards((string *) "CARROT", (string *) "add 4 armies OR move 2 armies**"); //** means add this card in a five player game.
    const Cards card17 = Cards((string *) "CARROT", (string *) "move 4 armies");
    const Cards card18 = Cards((string *) "CARROT", (string *) "build city");
    //9 ANVIL Cards
    const Cards card19 = Cards((string *) "ANVIL", (string *) "move 4 armies");
    const Cards card20 = Cards((string *) "ANVIL", (string *) "add 3 armies OR move 4 armies");
    const Cards card21 = Cards((string *) "ANVIL", (string *) "move 5 armies");
    const Cards card22 = Cards((string *) "ANVIL", (string *) "add 3 armies");
    const Cards card23 = Cards((string *) "ANVIL", (string *) "add 3 armies");
    const Cards card24 = Cards((string *) "ANVIL", (string *) "move 3 armies via ship");
    const Cards card25 = Cards((string *) "ANVIL", (string *) "build city");
    const Cards card26 = Cards((string *) "ANVIL", (string *) "move 4 armies (double)**"); //double ANVIL card. Add this card in five player game.
    const Cards card27 = Cards((string *) "ANVIL", (string *) "add 3 armies OR move 3 armies");
    //7 ORE Cards
    const Cards card28 = Cards((string *) "ORE", (string *) "move 2 armies");
    const Cards card29 = Cards((string *) "ORE", (string *) "move 3 armies via ship");
    const Cards card30 = Cards((string *) "ORE", (string *) "move 2 armies via ship**"); //** means add this card in a five player game.
    const Cards card31 = Cards((string *) "ORE", (string *) "move 2 armies via ship");
    const Cards card32 = Cards((string *) "ORE", (string *) "add 3 armies");
    const Cards card33 = Cards((string *) "ORE", (string *) "add 3 armies");
    const Cards card34 = Cards((string *) "ORE", (string *) "add 2 armies");
    //5 CRYSTAL Cards
    const Cards card35 = Cards((string *) "CRYSTAL", (string *) "add 2 armies");
    const Cards card36 = Cards((string *) "CRYSTAL", (string *) "add 2 armies");
    const Cards card37 = Cards((string *) "CRYSTAL", (string *) "move 2 armies");
    const Cards card38 = Cards((string *) "CRYSTAL", (string *) "add 1 army");
    const Cards card39 = Cards((string *) "CRYSTAL", (string *) "add 2 armies **"); //** means add this card in a five player game.
    //3 WILD Cards
    const Cards card40 = Cards((string *) "WILD", (string *) "move 2 armies");
    const Cards card41 = Cards((string *) "WILD", (string *) "move 2 armies");
    const Cards card42 = Cards((string *) "WILD", (string *) "add 2 armies");
 //TOTAL OF: 42 Cards. 


    deck_Vector.push_back(card1);
    deck_Vector.push_back(card2);
    deck_Vector.push_back(card3);
    deck_Vector.push_back(card4);
    deck_Vector.push_back(card5);
    deck_Vector.push_back(card6);
    deck_Vector.push_back(card7);
    deck_Vector.push_back(card8);
    deck_Vector.push_back(card9);
    deck_Vector.push_back(card10);
    deck_Vector.push_back(card11);
    deck_Vector.push_back(card12);
    deck_Vector.push_back(card13);
    deck_Vector.push_back(card14);
    deck_Vector.push_back(card15);
    deck_Vector.push_back(card16);
    deck_Vector.push_back(card17);
    deck_Vector.push_back(card18);
    deck_Vector.push_back(card19);
    deck_Vector.push_back(card20);
    deck_Vector.push_back(card21);
    deck_Vector.push_back(card22);
    deck_Vector.push_back(card23);
    deck_Vector.push_back(card24);
    deck_Vector.push_back(card25);
    deck_Vector.push_back(card26);
    deck_Vector.push_back(card27);
    deck_Vector.push_back(card28);
    deck_Vector.push_back(card29);
    deck_Vector.push_back(card30);
    deck_Vector.push_back(card31);
    deck_Vector.push_back(card32);
    deck_Vector.push_back(card33);
    deck_Vector.push_back(card34);
    deck_Vector.push_back(card35);
    deck_Vector.push_back(card36);
    deck_Vector.push_back(card37);
    deck_Vector.push_back(card38);
    deck_Vector.push_back(card39);
    deck_Vector.push_back(card40);
    deck_Vector.push_back(card41);
    deck_Vector.push_back(card42);
}

/*
Destructor for Deck class
*/
Deck::~Deck() 
{

}

/*
Function that generates a random number. 
*/
int randomGenerator (int random) 
{ 
    return rand()%random;
}


/*
Implementation of draw method for Deck class. 
*/
void Deck::draw()
 {
    Deck deckOfCards; //instantion of a deck. 

    srand (unsigned (time(0)));
    std::random_shuffle(deck_Vector.begin(), deck_Vector.end(), randomGenerator);

    cout << "deck contains:";
    for (vector<Cards>::iterator itr=deck_Vector.begin(); itr!=deck_Vector.end(); ++itr)
        cout << ' ' << *itr;

    cout << '\n';
    
}

std::ostream &operator<<(std::ostream &os, const Deck &my_deck) {
    os << "Full Deck: " << " Card 1: " << my_deck.card1
        << " Card 2: " << my_deck.card2
        << " Card 3: " << my_deck.card3
        << " Card 4: " << my_deck.card4
        << " Card 5: " << my_deck.card5
        << " Card 6: " << my_deck.card6
        << " Card 7: " << my_deck.card7
        << " Card 8: " << my_deck.card8
        << " Card 9: " << my_deck.card9
        << " Card 10: " << my_deck.card10
        << " Card 11: " << my_deck.card11
        << " Card 12: " << my_deck.card12
        << " Card 13: " << my_deck.card13
        << " Card 14: " << my_deck.card14
        << " Card 15: " << my_deck.card15
        << " Card 16: " << my_deck.card16
        << " Card 17: " << my_deck.card17
        << " Card 18: " << my_deck.card18
        << " Card 19: " << my_deck.card19
        << " Card 20: " << my_deck.card20
        << " Card 21: " << my_deck.card21
        << " Card 22: " << my_deck.card22
        << " Card 23: " << my_deck.card23
        << " Card 24: " << my_deck.card24
        << " Card 25: " << my_deck.card25
        << " Card 26: " << my_deck.card26
        << " Card 27: " << my_deck.card27
        << " Card 28: " << my_deck.card28
        << " Card 29: " << my_deck.card29
        << " Card 30: " << my_deck.card30
        << " Card 31: " << my_deck.card31
        << " Card 32: " << my_deck.card32
        << " Card 33: " << my_deck.card33
        << " Card 34: " << my_deck.card34
        << " Card 35: " << my_deck.card35
        << " Card 36: " << my_deck.card36
        << " Card 37: " << my_deck.card37
        << " Card 38: " << my_deck.card38
        << " Card 39: " << my_deck.card39
        << " Card 40: " << my_deck.card40
        << " Card 41: " << my_deck.card41
        << " Card 42: " << my_deck.card42;

    return os;
        
}

Hand::Hand()
{

}

Hand::~Hand() 
{

}

void Hand::exchange() 
{

}

