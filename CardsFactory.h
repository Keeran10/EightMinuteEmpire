#pragma once
#include "Cards.h"
#include <string>
using namespace std;

class CardOptions {
private:

public:
	int move;
	int add;
	bool destroy;
	bool build;
	bool five;
	bool by_ship;
	bool OR;
	bool AND;

	CardOptions();
	~CardOptions();
	void ResetOptions();


};

class CardsFactory {

public:
	CardsFactory();
	~CardsFactory();
	Card* GenerateCard(string type, string action, CardOptions* settings);
};
