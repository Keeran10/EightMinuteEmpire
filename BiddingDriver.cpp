#include <vector>
#include "BiddingDriver.h"

BiddingDriver::BiddingDriver()
{
}

BiddingDriver::~BiddingDriver()
{
}

Player* BiddingDriver::CalculateWinner(vector<Player*> players)
{
	Player* winningPlayer = players[0];
	Player* runnerUp;
	for (unsigned int i = 1; i < players.size(); i++) 
	{
		runnerUp = players[i];
		if (winningPlayer->GetBiddingFacility()->GetBid() < runnerUp->GetBiddingFacility()->GetBid()) {
			winningPlayer = runnerUp;
		}
		else if (winningPlayer->GetBiddingFacility()->GetBid() == runnerUp->GetBiddingFacility()->GetBid()) {
			if (winningPlayer->GetAge() > runnerUp->GetAge()) {
				winningPlayer = runnerUp;
			}
		}
	}
	return winningPlayer;
}
