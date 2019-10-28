#include "Player.h"
#include <iostream>

// Default Constructor for PCs
Player::Player() : name("player"), age(new int(0)), coins(new int(10)), cubes(new int(14)), discs(new int(3))
{
	biddingFacility = new BiddingFacility();
}

// Constructor for NPCs
Player::Player(string name, int age) : name(name), age(new int(age)), coins(new int(10)), cubes(new int(14)), discs(new int(3))
{
	biddingFacility = new BiddingFacility();
}

// Default Destructor
Player::~Player()
{
	delete age, coins, cubes, discs, biddingFacility;
}

// Place new armies on the map. Right now, I'm also adding to player's army vector. Should we limit this to 14?
void Player::PlaceNewArmies(Map* map, int region_id, int num_armies)
{
	Region* region = map->GetRegion(region_id);
	int ctr = num_armies;

	if (!region) {
		cout << "Non-existing region. Abort..." << endl;
		return;
	}

	while (ctr != 0)
	{
		Army* ptr = new Army(this->GetArmies().at(0)->GetColor(), this->name);
		this->SetArmy(ptr);
		region->SetArmy(ptr);
		ctr--;
	}

	cout << "Added " << num_armies << " to region " << region_id << "." << endl;
}

// Move a player's armies from one region to another. NEED TO BE REFACTORED ! 
void Player::MoveArmies(Map* map, int source, int destination, int armies_to_move)
{
	Region* src = map->GetRegion(source);
	Region* des = map->GetRegion(destination);

	if (!src || !des) {
		cout << "Non-existing region(s). Abort..." << endl;
		return; 
	}

	int moving_cost = src->IsAdjacent(*des);

	if (moving_cost == 0) {
		cout << "Regions are not adjacents. Abort..." << endl;
		return;
	}

	if (moving_cost == 1)
		MoveOverLand(map, src, des);
	else
		MoveOverWater(map, src, des);
}

// Move one army at a time for a given source and destination over land
void Player::MoveOverLand(Map* map, Region* src, Region* des)
{
	vector<Army*> armies = *src->GetArmies();

	for (int i = 0; i < armies.size(); i++)
	{
		if (armies[i]->GetOwner() == this->name) {
			des->SetArmy(armies[i]);
			src->GetArmies()->erase(armies.begin() + i);
			break;
		}
	}
	cout << "Successfully moved an army from region " << src->GetId() << " to region " << des->GetId() << " by land." << endl;
}

// Move one army at a time for a given source and destination over water
void Player::MoveOverWater(Map* map, Region* src, Region* des)
{
	vector<Army*> armies = *src->GetArmies();

	for (int i = 0; i < armies.size(); i++)
	{
		if (armies[i]->GetOwner() == this->name) {
			des->SetArmy(armies[i]);
			src->GetArmies()->erase(armies.begin() + i);
			break;
		}
	}
	cout << "Successfully moved an army from region " << src->GetId() << " to region " << des->GetId() << " by water." << endl;
}

// Build a city on region with existing personal army. Building a city will remove one from your city vector
void Player::BuildCity(Map* map, int region_id)
{
	Region* region = map->GetRegion(region_id);

	if (!region)
	{
		cout << "region does not exist. Abort..." << endl;
		return;
	}

	vector<Army*> armies = *region->GetArmies();

	bool isBuilt = false;

	for (int i = 0; i < armies.size(); i++)
	{
		if (armies[i]->GetOwner() == this->name) {
			region->SetCity(this->cities.at(0));
			this->cities.pop_back();
			isBuilt = true;
			break;
		}
	}

	if (!isBuilt)
	{
		cout << "You don't have an army on region " << region_id << " to build a city. Abort..." << endl;
		return;
	}
	cout << "Successfully built a city on region " << region_id << endl;
}

// destroys one army on a space the player occupies
void Player::DestroyArmy(Map* map, int region_id, string enemy)
{
	Region* region = map->GetRegion(region_id);

	if (!region)
	{
		cout << "region does not exist. Abort..." << endl;
		return;
	}

	bool occupies = false;
	bool isDestroyed = false;
	vector<Army*> armies = *region->GetArmies();

	for (int i = 0; i < armies.size(); i++)
	{
		if (armies[i]->GetOwner() == this->name) {
			occupies = true;
			break;
		}
	}

	if (!occupies)
	{
		cout << " You do not occupy region " << region_id << ". Abort..." << endl;
		return;
	}

	for (int i = 0; i < armies.size(); i++)
	{
		if (armies[i]->GetOwner() == enemy) {
			region->GetArmies()->erase(armies.begin() + i);
			isDestroyed = true;
			break;
		}
	}

	if (!isDestroyed)
	{
		cout << enemy << " does not have an army on region " << region_id << ". Abort..." << endl;
		return;
	}

	cout << "Successfully destroyed army belonging to " << enemy << " on region " << region_id << endl;
}



string Player::PayCoin()
{
	return "PayCoin() implementation";
}

string Player::PlaceNewArmies()
{
	return "PlaceNewArmies() implementation";
}

string Player::MoveArmies()
{
	return "MoveArmies() implementation";
}

string Player::MoveOverLand()
{
	return "MoveOverLand() implementation";
}

string Player::BuildCity()
{
	return "BuildCity() implementation";
}

string Player::DestroyArmy()
{
	return "DestroyArmy() implementation";
}

void Player::PlayerDriverGameLoop()
{
	Player* player = new Player();

	std::cout << player->PayCoin() << "\n";
	std::cout << player->PlaceNewArmies() << "\n";
	std::cout << player->MoveArmies() << "\n";
	std::cout << player->MoveOverLand() << "\n";
	std::cout << player->BuildCity() << "\n";
	std::cout << player->DestroyArmy() << "\n";

	vector<string> playerCountries0 = player->GetCountriesVector();
	playerCountries0.push_back("country1");
	playerCountries0.push_back("country2");
	playerCountries0.push_back("country3");

	vector<string> playerCountries = player->GetCountriesVector();
	for (unsigned int i = 0; i < playerCountries.size(); i++) {
		cout << "Player country " << i << ": " << playerCountries[i] << "\n";
	}
}