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

		inline int GetCoins() { return coins; }
		inline void SetCoins(int coins) { this->coins = coins; }
		inline int GetAge() { return age; }
		inline void SetAge(int age) { this->age = age; }
		inline string GetName() { return name; }
		inline void SetName(string name) { this->name = name; }
		inline BiddingFacility* GetBiddingFacility() { return biddingFacility; }

		void PayCoin();
		void PlaceNewArmies();
		void MoveArmies();
		void MoveOverLand();
		void BuildCity();
		void DestroyArmy();
};