#pragma once

#include "Cards.h"
#include <string>

class PlayerStrategies {
	public:
		virtual char selectCardFromHand(Hand* hand, string name, int coins) = 0;
};

class HumanStrategy : public PlayerStrategies {
	public:
		HumanStrategy();
		~HumanStrategy();
		char selectCardFromHand(Hand* hand, string name, int coins);
};

class GreedyStrategy : public PlayerStrategies {
	public:
		GreedyStrategy();
		~GreedyStrategy();
		char selectCardFromHand(Hand* hand, string name, int coins);
	//if card.actions.contains build or destroy
};

class ModerateStrategy : public PlayerStrategies {
	public:
		ModerateStrategy();
		~ModerateStrategy();
		char selectCardFromHand(Hand* hand, string name, int coins);
	//if card.actions.contains move armies or place armies
};

char getBestMove(vector<int> possibleMoves, int coins);