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

