#ifndef CARDS_H
#define CARDS_H
#ifndef DECK_H
#define DECK_H
#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

using std::string;


// Cards class 
class Cards 
{
private:
    string *resource;
    string *actions;
public:

    Cards(string *resource, string *actions);

    Cards(); //default constructor

    virtual ~Cards(); //virtual destructor 

    inline string *getResourceType() const //inline reduces function call overhead. Resource getter
     {
        return resource;
    }

    inline void setResourceType(string *resource) //inline reduces function call overhead. Resource setter. 
    {
        Cards::resource = resource;
    }

    inline string *getActionsType() const  //inline reduces function call overhead. Action getter. 
    {
        return actions;
    }

    inline void setActionsType(string *actions)  //inline reduces function call overhead. Action setter
    {
        Cards::actions = actions;
    }
    
    //the friend function has the right to access private and protected memebers of the Card class. 
    friend std::ostream &operator<<(std::ostream &os, const Cards &cards);

};

//Deck Class
class Deck {
private:
    vector<Cards> deck_Vector; //store cards in the deck in a vector 

public:
    Deck(); //default constructor 
    virtual ~Deck(); //virtual destructor. 
    void draw(); //draw method. Allows player to draw a card from remaining cards in the deck. 

    //Card objects (42 of them)
    const Cards card1;
    const Cards card2;
    const Cards card3;
    const Cards card4;
    const Cards card5;
    const Cards card6;
    const Cards card7;
    const Cards card8;
    const Cards card9;
    const Cards card10;
    const Cards card11;
    const Cards card12;
    const Cards card13;
    const Cards card14;
    const Cards card15;
    const Cards card16;
    const Cards card17;
    const Cards card18;
    const Cards card19;
    const Cards card20;
    const Cards card21;
    const Cards card22;
    const Cards card23;
    const Cards card24;
    const Cards card25;
    const Cards card26;
    const Cards card27;
    const Cards card28;
    const Cards card29;
    const Cards card30;
    const Cards card31;
    const Cards card32;
    const Cards card33;
    const Cards card34;
    const Cards card35;
    const Cards card36;
    const Cards card37;
    const Cards card38;
    const Cards card39;
    const Cards card40;
    const Cards card41;
    const Cards card42;

    // the friend function below has the right to access private and protected members of the Deck class. 
    friend std::ostream &operator<<(std::ostream &os, const Deck &my_deck); 

};

//Hand Class 
class Hand {
    private:
        Cards cards;
    public:
        Hand(); //Default contructor 
        virtual ~Hand(); //virtual destructor 
        void exchange(); //exchange method allows a player to select a card from the 6 cards in the row and 
                        // pay the associated coin cost for that card (0,1,1,2,2,3)
};

#endif //CARDS_H
#endif //DECK_H
#endif //HAND_H