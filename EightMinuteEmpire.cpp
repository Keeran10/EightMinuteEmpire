#include <iostream>
#include <vector>
#include "Player.h"
#include "BiddingDriver.h"
#include "DriverHelper.h"
#include "Cards.h"
#include "Map.h"
#include "MapLoader.h"
#include <random>

void UserPlaysDriver();
Player* SetupPhase(Map* map, vector<Player*> players, Deck* deck, Hand* boardHand);
void StartingRegionPhase(Map* map, vector<Player*> players);
void PlayerTurnPhase(Map* map, Player* startingPlayer, Deck* deck, Hand* boardHand);
void PlayGame(Map* map, vector<Player*> players, Deck* deck);

int main()
{
	MapLoader* ml;
	Map* map;
	do {
		std::cout << "Welcome to Eight Minute Empire, here are a list of the maps available.\n";
		// cout the maps
		//please select a map
		//cin map by number
		ml = new MapLoader("game_map.txt");
		map = ml->GetMap();
	} while (!ml->getIsValid());


	int cpus = 0;
	do {
		std::cout << "\nPlease enter how many CPUs you would like to play with (1-4): ";
		std::cin >> cpus;
	} while (cpus > 4 || cpus < 1);

	vector<Player*> players;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(5.0, 100.0);

	for (int i = 0; i < cpus; i++) {
		players.push_back(new Player("CPU" + std::to_string(i), (int)dist(mt)));
	}

	Player* player = new Player();
	string name = "";
	int age = 0;

	std::cout << "\nPlease enter the player name: ";
	std::cin >> name;
	player->SetName(name);

	do {
		std::cout << "Please enter the player age (5-100): ";
		std::cin >> age;
	} while (age > 100 || age < 5);
	player->SetAge(age);

	players.push_back(player);

	std::cout << "Here is the map and the players you will be playing with\n\n";

	map->PrintMap();
	cout << "\n-----------------------------------------" << endl;
	cout << "*PLAYERS*" << endl;
	cout << "-----------------------------------------" << endl;
	PrintPlayers(players);

	Deck* deck = new Deck(players.size());

	PlayGame(map, players, deck);

	delete ml, player, deck;
	players.clear();
	players.shrink_to_fit();
	return 0;
}

void A1Drivers() {
	char input = 'a';

	//Game loop
	while (input != 'q') {
		std::cout << "\nEnter one of the following characters:\n"
			<< "p to play with CPUs\n"
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
	cpu1->GetBiddingFacility()->RandomizeBid(10);
	cpu2->GetBiddingFacility()->RandomizeBid(10);

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

// MAIN GAME LOOP
void PlayGame(Map* map, vector<Player*> players, Deck* deck) {
	
	Hand* boardHand = new Hand(deck);
	
	Player* startingPlayer = SetupPhase(map, players, deck, boardHand);
	
	StartingRegionPhase(map, players);

	PlayerTurnPhase(map, startingPlayer, deck, boardHand);

	delete boardHand;
}

Player* SetupPhase(Map* map, vector<Player*> players, Deck* deck, Hand* boardHand)
{
	int coins = 0;

	switch (players.size()) {
	case 2:
		coins = 14;
		break;
	case 3:
		coins = 11;
		break;
	case 4:
		coins = 9;
		break;
	case 5:
		coins = 8;
		break;
	}

	for (int i = 0; i < players.size(); i++) {
		players[i]->SetCoins(coins);
	}

	int bid;
	do {
		std::cout << "Please enter your bid (0-" + std::to_string(players.back()->GetCoins()) + "): ";
		std::cin >> bid;
	} while (bid < 0 || bid > players.back()->GetCoins());
	for (int i = 0; i < players.size() - 1; i++) {
		players[i]->GetBiddingFacility()->RandomizeBid(coins);
	}
	players.back()->GetBiddingFacility()->SetBid(bid);

	PrintBids(players);

	Player* startingPlayer = GetStartingPlayer(players);

	cout << "Starting player: " << startingPlayer->GetName() << "\n\n";

	cout << "\nGame has begun. Please enter q (for quit) in any input prompts to exit the game." << endl;

	return startingPlayer;
}

void StartingRegionPhase(Map* map, vector<Player*> players)
{

}

void PlayerTurnPhase(Map* map, Player* startingPlayer, Deck* deck, Hand* boardHand)
{
	char input = 'a';
	do
	{
		cout << "\nHere are the cards from the board.\n";

		boardHand->PrintHand();

		cout << startingPlayer->GetName() << " select a card from the board from positions 1 to 6: ";

		cin >> input;

		pair<Card*, int> card_cost = boardHand->Exchange(input, startingPlayer->GetCoins(), deck);

		if (card_cost.second == -1) {
			cout << "\n" << startingPlayer->GetName() << " select a card from the board from positions 1 to 6: ";
			cin >> input;
			continue;
		}

		startingPlayer->SetCoins(startingPlayer->GetCoins() - card_cost.second);

		cout << startingPlayer->GetName() << ", you have " << startingPlayer->GetCoins() << " coins remaining." << endl;

		Card* card = card_cost.first;

		startingPlayer->SetCards(card);

		pair<string, int> readCard = card->ReadCardAction();

		string action = readCard.first;

		if (action == "move_by_sea" || action == "move_by_land")
		{
			char take;
			do {
				cout << "Would you like to take the above action or ignore it? (y/n): ";
				cin >> take;

				if (take == 'n' || take == 'N')
				{
					break; // ignore action
				}
				else if (take == 'y' || take == 'Y')
				{
					int move_count = readCard.second;

					while (move_count > 0 || take == 'n' || take == 'N')
					{
						int source = -1;
						int destination = -1;
						int armies_to_move = -1;

						map->GetPlayerRegions(startingPlayer->GetName()); // bug

						do
						{
							cout << "Move armies from region: ";
							cin >> source;
						} while (source <= 0);
						do
						{
							cout << "\nto region: ";
							cin >> destination;
						} while (destination <= 0);
						do
						{
							cout << "Number of armies to move? Out of a possible " << move_count << ": ";
							cin >> armies_to_move;
						} while (armies_to_move <= 0 || armies_to_move > move_count);

						move_count = -armies_to_move;

						startingPlayer->MoveArmies(map, source, destination, armies_to_move);

						cout << "Move more armies or yield your turn? (y/n): ";
						cin >> take;
					}
				}
			} while (take == 'y' || take == 'n');
		}
		else if (action == "add")
		{

		}
		else if (action == "destroy")
		{

		}
		else if (action == "build")
		{

		}
		else if (action == "move_or_add")
		{

		}
		else if (action == "build_or_destroy")
		{

		}
		else if (action == "add_and_destroy")
		{

		}
		else if (action == "default")
		{
			cout << "Something went wrong. Abort..." << endl;
		}

	} while (input != 'q');
}