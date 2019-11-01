#pragma once
#include "BiddingFacility.h"
#include "Cards.h"
#include "Map.h"
#include <string>
#include <vector>

using namespace std;

class Player {
	// Properties
	BiddingFacility* biddingFacility;
	int *coins, *age, *cubes, *discs;
	string name;
	string color;
	vector<Army*> armies;
	vector<City*> cities;
	vector<Card*> cards;
	public:
		// Constructors & Destructor
		Player();
		~Player();
		int AddArmies(Map* map, Region* region, int num_armies);
		Player(string name, int age, string color);

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
		inline BiddingFacility* GetBiddingFacility() { return biddingFacility; }

		// part 4
		inline void SetCards(Card* card) { cards.push_back(card); }
		inline vector<Card*> GetCards() { return cards; }
		inline vector<Army*> GetArmies() { return armies; }
		inline void SetArmy(Army* army) { armies.push_back(army); }
		inline void SetCity(City* city) { cities.push_back(city); }
		void PlaceNewArmies(Map* map, Region* region, int num_armies);
		int MoveArmies(Map* map, int source, int destination, int armies_to_move, string action);
		void MoveOverLand(Map* map, Region*, Region*);
		void MoveOverWater(Map* map, Region*, Region*);
		int BuildCity(Map* map, int region_id);
		void DestroyArmy(Map* map, int region_id, string enemy);
		inline string GetColor() { return color; }
		inline void SetColor(string color) { this->color = color; }
		// Functions
		string PayCoin();
		string PlaceNewArmies();
		string MoveArmies();
		string MoveOverLand();
		string BuildCity();
		string DestroyArmy();

		static void PlayerDriverGameLoop();
};