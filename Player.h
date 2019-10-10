#pragma once
#include "BiddingFacility.h"
#include <string>
#include <vector>

using namespace std;

class Player {
	// Properties
	BiddingFacility* biddingFacility;
	int *coins, *age, *cubes, *discs;
	string name;
	vector<string> countries;

	public:
		// Constructors & Destructor
		Player();
		~Player();
		Player(string name, int age);

		// Getters & Setters
		inline int GetCoins() { return *coins; }
		inline void SetCoins(int coins) { this->coins = &coins; }
		inline int GetAge() { return *age; }
		inline void SetAge(int age) { this->age = &age; }
		inline int GetCubes() { return *cubes; }
		inline void SetCubes(int cubes) { this->cubes = &cubes; }
		inline int GetDiscs() { return *discs; }
		inline void SetDiscs(int discs) { this->discs = &discs; }
		inline string GetName() { return name; }
		inline void SetName(string name) { this->name = name; }
		inline void GetCountriesVector() { this->countries; }
		inline BiddingFacility* GetBiddingFacility() { return biddingFacility; }

		// Functions
		void PayCoin();
		void PlaceNewArmies();
		void MoveArmies();
		void MoveOverLand();
		void BuildCity();
		void DestroyArmy();
};