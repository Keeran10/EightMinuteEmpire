#include "PlayerStrategies.h"
#include "Cards.h"

char PlayerStrategies::selectCardFromHand(Hand* hand, string name, int coins)
{
	return '0';
}

HumanStrategy::HumanStrategy()
{
}

HumanStrategy::~HumanStrategy()
{
}

char HumanStrategy::selectCardFromHand(Hand* hand, string name, int coins) {
	char input;
	cout << name << " select a card from the board from positions 1 to 6: ";

	cin >> input;

	return input;
}

GreedyStrategy::GreedyStrategy()
{
}

GreedyStrategy::~GreedyStrategy()
{
}

char GreedyStrategy::selectCardFromHand(Hand* hand, string name, int coins)
{
	vector<int> possibleMoves;

	vector<Card*> handCards = *hand->GetHand();

	for (int i = 0; i < handCards.size(); i++) {
		if (handCards[i]->GetAction().find("build") != string::npos || handCards[i]->GetAction().find("destroy") != string::npos) {
			possibleMoves.push_back(i);
		}
	}

	int input = getBestMove(possibleMoves, coins);

	return input;
}

ModerateStrategy::ModerateStrategy()
{
}

ModerateStrategy::~ModerateStrategy()
{
}

char ModerateStrategy::selectCardFromHand(Hand* hand, string name, int coins)
{
	vector<int> possibleMoves;

	vector<Card*> handCards = *hand->GetHand();

	for (int i = 0; i < handCards.size(); i++) {
		if (handCards[i]->GetAction().find("add") != string::npos || handCards[i]->GetAction().find("move") != string::npos) {
			possibleMoves.push_back(i);
		}
	}

	int input = getBestMove(possibleMoves, coins);

	return input;
}

char getBestMove(vector<int> possibleMoves, int coins) {
	char input = '0';
	if (possibleMoves.size() < 1) {
		input = '1';
	}
	else {
		for (int i = possibleMoves.size() - 1; i >= 0; i--) { //get least expensive card
			if (possibleMoves[i] <= coins / 2) {
				input = '0'+ possibleMoves[i];
			}
		}
		if (input == '0') {//take free card if moves are too expensive
			input = '1';
		}
	}

	return input;
}