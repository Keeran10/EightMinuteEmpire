

#include "Cards.h"
#include "Cards.cpp"
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[]){
    cout << "HELLO COMP345 PROJECT PART 1" << endl;

    Deck myDeck;
    myDeck.draw();

    Hand h;
    h.exchange();
    
    return 0;
}