#include <iostream>
#include <vector>
#include "Player.h"
#include "BiddingDriver.h"
#include "DriverHelper.h"
#include "Cards.h"
#include "Map.h"

void UserPlaysDriver();

int main()
{
	char input = 'a';

	//Game loop
	while (input != 'q') {
		std::cout << "\nEnter one of the following characters:\n"
			<< "p to play with 2 CPUs\n"
			<< "1-5 for automatic drivers for respective parts\n"
			<< "q to quit\n\n";

		std::cin >> input;

		switch (input)
		{
			case '1':
				cout << "Map Driver\n\n";
				MapDriver();
				break;
			case '2':
				cout << "Map Loader Driver\n\n";
				MapLoaderDriver();
				break;
			case '3':
				cout << "Player Driver\n\n";
				Player::PlayerDriverGameLoop();
				break;
			case '4':
				cout << "Cards deck/hand Driver\n\n";
				CardsDriver();
				break;
			case '5':
				cout << "Bidding Driver\n\n";
				BiddingDriver::BiddingDriverGameLoop();
				break;
			case 'p':
				UserPlaysDriver();
				break;
			default:
				break;
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
	while (bid < 0 || bid > 10) {
		std::cout << "invalid value, please enter a valid number (0-10)";
	}

	player->GetBiddingFacility()->SetBid(bid);
	cpu1->GetBiddingFacility()->RandomizeBid();
	cpu2->GetBiddingFacility()->RandomizeBid();

	PrintBids(players);

	// Calculate the starting player
	Player* startingPlayer = GetStartingPlayer(players);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n";

	startingPlayer->SetCoins(startingPlayer->GetCoins() - startingPlayer->GetBiddingFacility()->GetBid());
	for (unsigned int i = 0; i < players.size(); i++) {
		cout << players[i]->GetName() << " coins: " << players[i]->GetCoins() << "\n";
	}


	// Free up memory
	delete cpu1, cpu2, player;
	cpu1 = cpu2 = player = NULL;
	players.clear();
	players.shrink_to_fit();
}