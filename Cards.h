#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
    Card (string resources, string actions);
    Card();
    string print() const;
    
private:
    string resources;
    string actions;
};

Card:: Card(){

}

Card::Card(string cardResource, string CardAction)
{
    resources= cardResource;
    actions= CardAction;
}

string Card::print() const
{
    return (resources + " " + actions);
}
#endif 

