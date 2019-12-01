#pragma once
#include "Subject.h"
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Player;

// Card class 
class Card : public Subject
{
private:
    string resource;
    string action;
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
	string GetResource();
	string GetAction();
	// part 4
	pair<string, int> ReadCardAction();
	pair<string, int> ReadCardActionOR();
	pair<string, int> ReadCardActionAND();
	inline int GetMove() { return move; }
	inline int GetAdd() { return add; }
	inline bool GetByShip() { return by_ship; }
	inline bool GetBuild() { return build; }
	inline bool GetDestroy() { return destroy; }
	inline bool GetIsFivePlayer() { return isFivePlayer; }
	inline bool GetOR() { return OR; }
	inline bool GetAND() { return AND; }
};

class ForestCard : public Card {
public:
	ForestCard(string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
};

class CarrotCard : public Card {
public:
	CarrotCard(string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
};

class AnvilCard : public Card {
public:
	AnvilCard(string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
};

class OreCard : public Card {
public:
	OreCard(string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
};

class CrystalCard : public Card {
public:
	CrystalCard(string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
};

class WildCard : public Card {
public:
	WildCard(string action, int move, int add, bool build, bool destroy, bool isFivePlayer, bool by_ship, bool OR, bool AND);
};

//Deck Class
class Deck {
private:
    vector<Card*>* cards; 
public:
    Deck(int num_players);
	Deck();
	Deck(string driverTest);
    ~Deck(); 
	vector<Card*>* GetDeck();
    Card* draw(); 
	void PrintDeck();
};

//Hand Class 
class Hand : public Subject {
private:
	// pay the associated coin cost for that card (0,1,1,2,2,3)
	vector<Card*>* hand;
public:
	Hand();
	Hand(Deck* deck); 
	~Hand(); 
	vector<Card*>* GetHand();
	pair<Card*, int> Exchange(char index, int coins, Deck* deck);
	void PrintHand();
};

inline string Card::GetResource() { return resource; }
inline string Card::GetAction() { return action; }

inline vector<Card*>* Deck::GetDeck() { return cards; }

inline vector<Card*>* Hand::GetHand() { return hand; }

void CardsDriver();