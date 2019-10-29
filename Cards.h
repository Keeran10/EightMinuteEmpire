#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Card class 
class Card 
{
private:
    string* resource;
    string* action;
	// part 4
	int move;
	int add;
	bool by_ship;
	bool build;
	bool destroy;
	bool isFivePlayer;
	bool OR;
	bool AND;
public:
	Card();
	Card(string resource, string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
    ~Card();
	pair<string, int> ReadCardAction();
	pair<string, int> ReadCardActionOR();
	pair<string, int> ReadCardActionAND();
	string GetResource();
	string GetAction();
	// part 4 
	inline int GetMove() { return move; }
	inline int GetAdd() { return add; }
	inline bool GetByShip() { return by_ship; }
	inline bool GetBuild() { return build; }
	inline bool GetDestroy() { return destroy; }
	inline bool GetIsFivePlayer() { return isFivePlayer; }
	inline bool GetOR() { return OR; }
	inline bool GetAND() { return AND; }
};

//Deck Class
class Deck {
private:
    vector<Card>* cards; 
public:
    Deck(int num_players);
	Deck();
    ~Deck(); 
	vector<Card>* GetDeck();
    Card draw(); 
	void PrintDeck();
};

//Hand Class 
class Hand {
private:
	// pay the associated coin cost for that card (0,1,1,2,2,3)
	vector<Card>* hand;
public:
	Hand();
	Hand(Deck* deck); 
	~Hand(); 
	vector<Card>* GetHand();
	Card* Exchange(int index, int coins, Deck* deck);
	void PrintHand();
};

inline string Card::GetResource() { return *resource; }
inline string Card::GetAction() { return *action; }

inline vector<Card>* Deck::GetDeck() { return cards; }

inline vector<Card>* Hand::GetHand() { return hand; }

void CardsDriver();