#pragma once
#include "Player.h"

class BiddingDriver {
	public:
		BiddingDriver();
		~BiddingDriver();

		Player* CalculateWinner(vector<Player*> players);
};