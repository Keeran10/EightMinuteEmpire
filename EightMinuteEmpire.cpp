#include <iostream>
#include <vector>
#include "Player.h"
#include "BiddingDriver.h"

void UserPlaysDriver();
void AutoDriver();
void PrintBids(vector<Player*> players);
void PrintPlayers(vector<Player*> players);
Player* GetStartingPlayer(vector<Player*> players);

int main()
{
	char input = 'a';

	//Game loop
	while (input != 'q') {
		std::cout << "Enter one of the following characters:\n"
			<< "p to play with 2 CPUs\n"
			<< "d for driver test\n"
			<< "q to quit\n\n";

		std::cin >> input;

		if (input == 'p') {
			UserPlaysDriver();
		}
		else if (input == 'd') {
			AutoDriver();
		}

	}

	return 0;
}

// Function for normal gameplay
void UserPlaysDriver() {

	// Create players
	Player* cpu1 = new Player("CPU1", 15);
	Player* cpu2 = new Player("CPU2", 20);
	Player* player = new Player();
	string name;
	int age, bid;

	std::cout << "\n\nPlease enter the player name\n";
	std::cin >> name;
	player->SetName(name);
	std::cout << "Please enter the player age\n";
	std::cin >> age;
	player->SetAge(age);
	std::cout << "\n";

	vector<Player*> players = { player, cpu1, cpu2 };

	PrintPlayers(players);

	// Get bids from players
	std::cout << "Please enter your bid (0-10)";
	std::cin >> bid;

	player->GetBiddingFacility()->SetBid(bid);
	cpu1->GetBiddingFacility()->RandomizeBid();
	cpu2->GetBiddingFacility()->RandomizeBid();

	PrintBids(players);

	// Calculate the starting player
	Player* startingPlayer = GetStartingPlayer(players);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n";

	// Free up memory
	delete cpu1, cpu2, player;
	cpu1 = cpu2 = player = NULL;
	players.clear();
	players.shrink_to_fit();
}

// Function for test driver according to assignment specs
void AutoDriver() {
	// Create players
	vector<Player*> cpus = { 
		new Player("CPU1", 15),
		new Player("CPU2", 25),
		new Player("CPU3", 20),
		new Player("CPU4", 30) 
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

// Print list of players
void PrintPlayers(vector<Player*> players) {
	for (unsigned int i = 0; i < players.size(); i++) {
		cout << players[i]->GetName() << " age: " << players[i]->GetAge() << "\n";
	}
}

// Print list of player bids
void PrintBids(vector<Player*> players) {
	for (unsigned int i = 0; i < players.size(); i++) {
		cout << players[i]->GetName() << " bid: " << players[i]->GetBiddingFacility()->GetBid() << "\n";
	}
}

// Calculate starting player using BiddingDriver
Player* GetStartingPlayer(vector<Player*> players) {
	BiddingDriver* biddingDriver = new BiddingDriver();
	Player* startingPlayer = biddingDriver->CalculateWinner(players);
	delete biddingDriver;
	return startingPlayer;
}