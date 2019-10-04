#ifndef DeckOfCards_H
#define DeckOfCards_H
#include "Cards.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std; 

const int CARDS_PER_DECK = 42;

class DeckOfCards
{
    public:
        DeckOfCards();
        void printDeck() const;
        void shuffle();
        Card draw();

    private:
        Card *deck;
        int currentCard;
};

/*
void DeckOfCards::printDeck() const
{
    cout<<left;
        cout <<deck->print(); //prints out cards in the deck
        cout <<endl; //Will print one card per line. 
}
*/

DeckOfCards::DeckOfCards()
{
    string resources[] = {"Forrest", "Carrot", "Anvil", "Ore", "Crystal"
        , "Wild"};
    /*
    string actions[] = {"Move 3 armies", "Add 3 armies", "Move 6 armies", 
        "Destroy 1 army OR Build City", "Add 2 armies OR Move 3 armies", 
        "Move 4 armies Via Ship", "Build City", "Move 3 armies Via Ship",
        "Destroy 1 army AND Add 1 army", "Move 4 armies", "Move 5 armies", 
        "Add 4 armies OR Move 2 armies", "Add 3 armies OR Move 4 armies", 
        "Add 3 armies OR Move 3 armies", "Move 2 armies", "Move 2 armies Via ship",
        "Add 2 armies", "Add 1 army", "Add 3 armies(Double Carrot)"};
    */
    string actionsW[]= {"Move 2 armies", "Add 2 armies"};

    string actionsCr[]= {"Add 2 armies","Add 2 armies","Move 2 armies",
    "Add 1 army", "Add 2 armies**"};
    
    string actionsO[] = {"Move 2 armies","Move 3 armies Via Ship",
     "Move 2 armies Via ship", "Move 2 armies Via ship**",
     "Add 3 armies","Add 3 armies","Add 2 armies"};
    
    string actionsF[]= {"Move 3 armies", "Add 3 armies", "Move 6 armies**",
      "Destroy 1 army OR Build City", "Add 2 armies OR Move 3 armies", 
      "Destroy 1 army AND Add 1 army", "Move 4 armies", "Move 5 armies"};

    string actionsC[]= {"Build City", "Destroy 1 army AND Add 1 army",
    "Add 3 armies", "Move 4 armies", "Move 5 armies", "Build City",
    "Add 3 armies(Double Carrot)", "Move 3 armies Via Ship", "Move 4 armies",
    "Add 4 armies OR Move 2 armies"};

    string actionsA[]= {"Move 4 armies","Add 3 armies OR Move 4 armies",
    "Move 5 armies","Add 3 armies", "Add 3 armies", "Move 3 armies Via Ship",
     "Build City","Move 4 armies(double Anvil)**",
     "Add 3 armies OR Move 3 armies"};
    
    deck = new Card[CARDS_PER_DECK];
    currentCard=0;
    for (int count=0; count<7; count++){
        deck[count]= Card(resources[0], actionsF[count%7]);
        cout <<deck[count].print()<<endl;
    }
    for (int count=0; count<10; count++){
        deck[count]= Card(resources[1], actionsC[count%10]);
        cout<<deck[count].print()<<endl;
     }
    for (int count=0; count<9; count++){
        deck[count]= Card(resources[2], actionsA[count%9]);
        cout<<deck[count].print()<<endl;
    }
    for (int count=0; count<7; count++){
        deck[count]= Card(resources[3], actionsO[count%7]);
        cout<<deck[count].print()<<endl;
    }
    for (int count=0; count<5; count++){
        deck[count]= Card(resources[4], actionsO[count%5]);
        cout<<deck[count].print()<<endl;
    }
    for (int count=0; count<2; count++){
        deck[count]= Card(resources[5], actionsW[count%2]);
        cout<<deck[count].print()<<endl;
    }

    
    //for (int count=0; count<CARDS_PER_DECK; count++){
      //  deck[count]= Card(resources[count%6], actions[count/6]);
    //}
}


Card DeckOfCards:: draw()
{
    if (currentCard<CARDS_PER_DECK){
        return (deck[currentCard++]);
    }
    return (deck[0]);
}
#endif