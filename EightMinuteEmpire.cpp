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

void UserPlaysDriver() {
	Player* cpu1 = new Player("CPU1", 15);
	Player* cpu2 = new Player("CPU2", 20);

	Player* player = new Player();
	string name;
	int age, bid;
	const int NUMBER_OF_PLAYERS = 3;

	std::cout << "\n\nPlease enter the player name\n";
	std::cin >> name;
	player->SetName(name);
	std::cout << "Please enter the player age\n";
	std::cin >> age;
	player->SetAge(age);

	vector<Player*> players = { player, cpu1, cpu2 };

	PrintPlayers(players);

	std::cout << "Please enter your bid (0-10)";
	std::cin >> bid;

	player->GetBiddingFacility()->SetBid(bid);
	cpu1->GetBiddingFacility()->RandomizeBid();
	cpu2->GetBiddingFacility()->RandomizeBid();

	PrintBids(players);

	Player* startingPlayer = GetStartingPlayer(players);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n";

	delete cpu1, cpu2, player;
	cpu1 = cpu2 = player = NULL;
	players.clear();
	players.shrink_to_fit();
}

void AutoDriver() {
	vector<Player*> cpus = { 
		new Player("CPU1", 15),
		new Player("CPU2", 25),
		new Player("CPU3", 20),
		new Player("CPU4", 30) 
	};

	PrintPlayers(cpus);

	cpus[0]->GetBiddingFacility()->SetBid(1);
	cpus[1]->GetBiddingFacility()->SetBid(2);
	cpus[2]->GetBiddingFacility()->SetBid(3);
	cpus[3]->GetBiddingFacility()->SetBid(4);

	PrintBids(cpus);

	Player* startingPlayer = GetStartingPlayer(cpus);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n\n";

	cpus[0]->GetBiddingFacility()->SetBid(3);
	cpus[1]->GetBiddingFacility()->SetBid(7);
	cpus[2]->GetBiddingFacility()->SetBid(7);
	cpus[3]->GetBiddingFacility()->SetBid(1);

	PrintBids(cpus);

	startingPlayer = GetStartingPlayer(cpus);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n\n";

	cpus[0]->GetBiddingFacility()->SetBid(0);
	cpus[1]->GetBiddingFacility()->SetBid(0);
	cpus[2]->GetBiddingFacility()->SetBid(0);
	cpus[3]->GetBiddingFacility()->SetBid(0);

	PrintBids(cpus);

	startingPlayer = GetStartingPlayer(cpus);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n\n";

	for (unsigned int i = 0; i < cpus.size(); i++) {
		delete cpus[i];
		cpus[i] = NULL;
	}

	cpus.clear();
	cpus.shrink_to_fit();
}


void PrintPlayers(vector<Player*> players) {
	for (unsigned int i = 0; i < players.size(); i++) {
		cout << players[i]->GetName() << " age: " << players[i]->GetAge() << "\n";
	}
}

void PrintBids(vector<Player*> players) {
	for (unsigned int i = 0; i < players.size(); i++) {
		cout << players[i]->GetName() << " bid: " << players[i]->GetBiddingFacility()->GetBid() << "\n";
	}
}

Player* GetStartingPlayer(vector<Player*> players) {
	BiddingDriver* biddingDriver = new BiddingDriver();
	Player* startingPlayer = biddingDriver->CalculateWinner(players);
	delete biddingDriver;
	return startingPlayer;
}