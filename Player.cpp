#include "Player.h"

Player::Player() : name("player"), age(0), coins(10), cubes(14), discs(3)
{
	biddingFacility = new BiddingFacility();
}

Player::~Player()
{
	delete biddingFacility;
	biddingFacility = NULL;
}

Player::Player(string name, int age) : name(name), age(age), coins(10), cubes(14), discs(3)
{
	biddingFacility = new BiddingFacility();
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

