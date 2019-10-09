#include "Player.h"

// Default Constructor for PCs
Player::Player() : name("player"), age(0), coins(10), cubes(14), discs(3)
{
	biddingFacility = new BiddingFacility();
}

// Constructor for NPCs
Player::Player(string name, int age) : name(name), age(age), coins(10), cubes(14), discs(3)
{
	biddingFacility = new BiddingFacility();
}

// Default Destructor
Player::~Player()
{
	delete biddingFacility;
	biddingFacility = NULL;
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

