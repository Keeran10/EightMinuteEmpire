#include <vector>
#include "BiddingDriver.h"

// Default Constructor
BiddingDriver::BiddingDriver()
{
}

// Default Destructor
BiddingDriver::~BiddingDriver()
{
}

// Compare list of players bids and age to find starting player
Player* BiddingDriver::CalculateWinner(vector<Player*> players)
{
	// Save first player for 1 less loop
	Player* winningPlayer = players[0];
	Player* runnerUp;
	for (unsigned int i = 1; i < players.size(); i++) 
	{
		// Get player to compare to current winner
		runnerUp = players[i];
		// Replace winner with runner up if the winner's bid is lower
		if (winningPlayer->GetBiddingFacility()->GetBid() < runnerUp->GetBiddingFacility()->GetBid()) {
			winningPlayer = runnerUp;
		}
		// If the winner and runner up bid the same value, the younger player wins
		else if (winningPlayer->GetBiddingFacility()->GetBid() == runnerUp->GetBiddingFacility()->GetBid()) {
			if (winningPlayer->GetAge() > runnerUp->GetAge()) {
				winningPlayer = runnerUp;
			}
		}
	}
	return winningPlayer;
}
