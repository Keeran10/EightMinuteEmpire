#pragma once

#include "Cards.h"
#include <string>

class PlayerStrategies {
	public:
		virtual string getName() = 0;
		virtual char selectCardFromHand(Hand* hand, string name, int coins) = 0;
		virtual void ExecuteGameplay() = 0;
};

class HumanStrategy : public PlayerStrategies {

string name = "human";

public:
	HumanStrategy();
	~HumanStrategy();
	char selectCardFromHand(Hand* hand, string name, int coins);
	string getName() { return name; }
	void ExecuteGameplay();
};

class GreedyStrategy : public PlayerStrategies {

string name = "greedy";

public:
	GreedyStrategy();
	~GreedyStrategy();
	char selectCardFromHand(Hand* hand, string name, int coins);
	string getName() { return name; }
	void ExecuteGameplay();
	//if card.actions.contains build or destroy
};

class ModerateStrategy : public PlayerStrategies {

string name = "moderate";	

public:
	ModerateStrategy();
	~ModerateStrategy();
	char selectCardFromHand(Hand* hand, string name, int coins);
	string getName() { return name; }
	void ExecuteGameplay();
	//if card.actions.contains move armies or place armies
};

char getBestMove(vector<int> possibleMoves, int coins);