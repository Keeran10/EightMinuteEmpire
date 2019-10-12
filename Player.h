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
		inline void SetCoins(int coins) { 
			delete this->coins;
			int* a = new int(coins);
			this->coins = a; 
		}
		inline int GetAge() { return *age; }
		inline void SetAge(int age) { 
			delete this->age;
			int* a = new int(age);
			this->age = a;
		}
		inline int GetCubes() { return *cubes; }
		inline void SetCubes(int cubes) {
			delete this->cubes;
			int* a = new int(cubes);
			this->cubes = a;
		}
		inline int GetDiscs() { return *discs; }
		inline void SetDiscs(int discs) {
			delete this->discs;
			int* a = new int(discs);
			this->discs = a;
		}
		inline string GetName() { return name; }
		inline void SetName(string name) { this->name = name; }
		inline vector<string> GetCountriesVector() { return countries; }
		inline void SetCountriesVector(vector<string> inputCountries) {
			countries.clear();
			countries = inputCountries;
		}
		inline BiddingFacility* GetBiddingFacility() { return biddingFacility; }

		// Functions
		string PayCoin();
		string PlaceNewArmies();
		string MoveArmies();
		string MoveOverLand();
		string BuildCity();
		string DestroyArmy();

		static void PlayerDriverGameLoop();
};