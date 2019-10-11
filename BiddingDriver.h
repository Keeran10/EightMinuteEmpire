#pragma once
#include "Player.h"

class BiddingDriver {
	public:
		// Constructors & Destructor
		BiddingDriver();
		~BiddingDriver();

		// Functions
		Player* CalculateWinner(vector<Player*> players);

		static void BiddingDriverGameLoop();
};