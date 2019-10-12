#pragma once
#include <iostream>
#include <vector>
#include "Player.h"
#include "BiddingDriver.h"

// Print list of players
inline void PrintPlayers(vector<Player*> players) {
	for (unsigned int i = 0; i < players.size(); i++) {
		std::cout << players[i]->GetName() << " age: " << players[i]->GetAge() << "\n";
	}
}

// Print list of player bids
inline void PrintBids(vector<Player*> players) {
	for (unsigned int i = 0; i < players.size(); i++) {
		cout << players[i]->GetName() << " bid: " << players[i]->GetBiddingFacility()->GetBid() << "\n";
	}
}

// Calculate starting player using BiddingDriver
inline Player* GetStartingPlayer(vector<Player*> players) {
	BiddingDriver* biddingDriver = new BiddingDriver();
	Player* startingPlayer = biddingDriver->CalculateWinner(players);
	delete biddingDriver;
	return startingPlayer;
}