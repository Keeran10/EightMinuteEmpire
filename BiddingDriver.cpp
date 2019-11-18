#include <vector>
#include "BiddingDriver.h"
#include "DriverHelper.h"

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
	winningPlayer->SetCoins(winningPlayer->GetCoins() - winningPlayer->GetBiddingFacility()->GetBid());
	cout << winningPlayer->GetName() << " has payed " << winningPlayer->GetBiddingFacility()->GetBid() << " to become the starting player." << endl;
	return winningPlayer;
}

void BiddingDriver::BiddingDriverGameLoop()
{
	// Create players
	vector<Player*> cpus = {
		new Player("CPU1", 15, "red", new HumanStrategy()),
		new Player("CPU2", 25, "orange", new HumanStrategy()),
		new Player("CPU3", 20, "brown", new HumanStrategy()),
		new Player("CPU4", 30, "green", new HumanStrategy())
	};

	PrintPlayers(cpus);
	cout << "\n";

	// Set player bids according to assignment specs
	cpus[0]->GetBiddingFacility()->SetBid(1);
	cpus[1]->GetBiddingFacility()->SetBid(2);
	cpus[2]->GetBiddingFacility()->SetBid(3);
	cpus[3]->GetBiddingFacility()->SetBid(4);

	PrintBids(cpus);

	// Calculate winner
	Player* startingPlayer = GetStartingPlayer(cpus);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n\n";

	// Set player bids according to assignment specs
	cpus[0]->GetBiddingFacility()->SetBid(3);
	cpus[1]->GetBiddingFacility()->SetBid(7);
	cpus[2]->GetBiddingFacility()->SetBid(7);
	cpus[3]->GetBiddingFacility()->SetBid(1);

	PrintBids(cpus);

	// Calculate winner
	startingPlayer = GetStartingPlayer(cpus);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n\n";

	// Set player bids according to assignment specs
	cpus[0]->GetBiddingFacility()->SetBid(0);
	cpus[1]->GetBiddingFacility()->SetBid(0);
	cpus[2]->GetBiddingFacility()->SetBid(0);
	cpus[3]->GetBiddingFacility()->SetBid(0);

	PrintBids(cpus);

	// Calculate winner
	startingPlayer = GetStartingPlayer(cpus);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n\n";

	// Free up memory
	for (unsigned int i = 0; i < cpus.size(); i++) {
		delete cpus[i];
		cpus[i] = NULL;
	}

	cpus.clear();
	cpus.shrink_to_fit();
}
