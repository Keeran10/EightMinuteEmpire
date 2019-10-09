#pragma once
#include "BiddingFacility.h"
#include <string>

using namespace std;

class Player {
	BiddingFacility* biddingFacility;
	int coins, age, cubes, discs;
	string name;
	string countries[10];

	public:
		Player();
		~Player();
		Player(string name, int age);

		int GetCoins() { return coins; }
		void SetCoins(int coins) { this->coins = coins; }
		int GetAge() { return age; }
		void SetAge(int age) { this->age = age; }
		string GetName() { return name; }
		void SetName(string name) { this->name = name; }
		BiddingFacility* GetBiddingFacility() { return biddingFacility; }

		void PayCoin();
		void PlaceNewArmies();
		void MoveArmies();
		void MoveOverLand();
		void BuildCity();
		void DestroyArmy();
};