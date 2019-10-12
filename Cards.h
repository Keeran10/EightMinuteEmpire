#pragma once
#include <iostream>
#include <vector>

// Card class 
class Card 
{
private:
    std::string* resource;
    std::string* action;
public:
	Card();
    Card(std::string resource, std::string action);
    ~Card(); 
	std::string GetResource();
	std::string GetAction();
};

//Deck Class
class Deck {
private:
    std::vector<Card>* cards; 
public:
    Deck();
    ~Deck(); 
	std::vector<Card>* GetDeck();
    Card draw(); 
	void PrintDeck();
};

//Hand Class 
class Hand {
private:
	// pay the associated coin cost for that card (0,1,1,2,2,3)
	std::vector<Card>* hand;
public:
	Hand();
	Hand(Deck* deck); 
	~Hand(); 
	std::vector<Card>* GetHand();
	Card* Exchange(int index, int coins, Deck* deck);
	void PrintHand();
};

inline std::string Card::GetResource() { return *resource; }
inline std::string Card::GetAction() { return *action; }

inline std::vector<Card>* Deck::GetDeck() { return cards; }

inline std::vector<Card>* Hand::GetHand() { return hand; }

void CardsDriver();