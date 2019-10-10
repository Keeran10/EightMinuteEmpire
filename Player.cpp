#include "Player.h"

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

void Player::PayCoin()
{
}

void Player::PlaceNewArmies()
{
}

void Player::MoveArmies()
{
}

void Player::MoveOverLand()
{
}

void Player::BuildCity()
{
}

void Player::DestroyArmy()
{
}

