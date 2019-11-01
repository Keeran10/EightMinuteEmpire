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
bool StartingRegionPhase(Map* map, vector<Player*> players);
void PlayerTurnPhase(Map* map, vector<Player*> players, int position, Deck* deck, Hand* boardHand);
void PlayGame(Map* map, vector<Player*> players, Deck* deck);

const static int STARTING_REGION = 12;

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
	vector<string> colors = {"yellow", "red", "green", "orange"};
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(5.0, 100.0);

	for (int i = 0; i < cpus; i++) {
		players.push_back(new Player("CPU" + std::to_string(i), (int)dist(mt), colors.at(i)));
	}

	Player* player = new Player();
	string name = "";
	int age = 0;
	player->SetColor("blue");

	std::cout << "Please enter the player name: ";
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
	Player* cpu1 = new Player("CPU1", 15, "violet");
	Player* cpu2 = new Player("CPU2", 20, "purple");
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

	int player_position = -1;

	for (int i = 0; i < players.size(); i++)
	{
		if (startingPlayer == players.at(i))
			player_position = i;
	}

	if (player_position < 0)
	{
		cout << "Starting player not found. Abort..." << endl;
		return;
	}

	bool valid_region = StartingRegionPhase(map, players);

	if(valid_region)
		PlayerTurnPhase(map, players, player_position, deck, boardHand);

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
		std::cout << "\nPlease enter your bid (0-" + std::to_string(players.back()->GetCoins()) + "): ";
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

bool StartingRegionPhase(Map* map, vector<Player*> players)
{
	Player* player;
	Region* region = map->GetRegion(STARTING_REGION);

	if (region == nullptr)
	{
		cout << "Starting region " << STARTING_REGION << " does not exist." << endl;
		return false;
	}

	cout << "\n-----------------------------------------" << endl;
	cout << "*STARTING REGION " << STARTING_REGION << "*"<< endl;
	cout << "-----------------------------------------" << endl;

	for (int i = 0; i < players.size(); i++)
	{
		player = players.at(i);
		player->PlaceNewArmies(map, region, 3);
	}
	return true;
}

void PlayerTurnPhase(Map* map, vector<Player*> players, int position, Deck* deck, Hand* boardHand)
{
	char input = 'a';
	
	do
	{
		bool or_invoked = false;
		bool and_invoked = false;

		Player* startingPlayer = players.at(position);

		boardHand->PrintHand();

		cout << startingPlayer->GetName() << " select a card from the board from positions 1 to 6: ";

		cin >> input;

		pair<Card*, int> card_cost = boardHand->Exchange(input, startingPlayer->GetCoins(), deck);

		if (card_cost.second == -1) {
			continue;
		}

		startingPlayer->SetCoins(startingPlayer->GetCoins() - card_cost.second);

		cout << "\n" << startingPlayer->GetName() << ", you have " << startingPlayer->GetCoins() << " coins remaining." << endl;

		Card* card = card_cost.first;

		startingPlayer->SetCards(card);

		pair<string, int> readCard = card->ReadCardAction();

		string action = readCard.first;
		
		char take{};
		
		if (action == "move_or_add")
		{
			do {
				cout << "\nWould you like to take the above action or ignore it? (y/n): ";
				cin >> take;

				if (take == 'n' || take == 'N')
				{
					break; // ignore action
				}

				int or_action = readCard.second;
				int add_action = or_action % 10;
				int move_action = (or_action - add_action) / 10;
				string decision = "a";

				do {
					cout << "Do you want to move " << move_action << " or add " << add_action << " armies? (move|add): ";
					cin >> decision;
				} while (decision != "move" && decision != "add");
				
				or_invoked = true;
				
				if (decision == "move")
				{
					action = "move_by_land";
					readCard.second = move_action;
					break;
				}
				else
				{
					action = "add";
					readCard.second = add_action;
					break;
				}

				break;

			} while (take == 'y' || take == 'n');
		}

		if (action == "build_or_destroy")
		{
			do {
				cout << "\nWould you like to take the above action or ignore it? (y/n): ";
				cin >> take;

				if (take == 'n' || take == 'N')
				{
					break; // ignore action
				}

				int or_action = readCard.second;
				string decision = "a";

				do {
					cout << "Do you want to build or destroy? (build|destroy): ";
					cin >> decision;
				} while (decision != "build" && decision != "destroy");

				or_invoked = true;

				if (decision == "destroy")
				{
					action = "destroy";
					break;
				}
				else
				{
					action = "build";
					break;
				}

				break;

			} while (take == 'y' || take == 'n');
		}

		if (action == "add_and_destroy")
		{
			cout << "\nWould you like to take the above action or ignore it? (y/n): ";
			cin >> take;

			if (take == 'n' || take == 'N')
			{
				break; // ignore action
			}
			else
				and_invoked = true;
		}

		if (action == "move_by_sea" || action == "move_by_land")
		{

			do {
				if (!or_invoked) {
					cout << "\nWould you like to take the above action or ignore it? (y/n): ";
					cin >> take;

					if (take == 'n' || take == 'N')
					{
						break; // ignore action
					}
				}

				int move_count = readCard.second;

				while (move_count > 0 && take != 'n')
				{
					int source = -1;
					int destination = -1;
					int armies_to_move = -1;

					for(Player* player : players)
						map->PrintPlayerRegions(player->GetName()); 

					do
					{
						cout << "\nMove armies from region: ";
						cin >> source;
					} while (source <= 0);
					do
					{
						map->GetRegion(source)->PrintAdjacents();
						cout << "\n\nto region: ";
						cin >> destination;
					} while (destination <= 0);
					do
					{
						cout << "\nNumber of armies to move? Out of a possible " << move_count << ": ";
						cin >> armies_to_move;
					} while (armies_to_move <= 0 || armies_to_move > move_count);

					int success = startingPlayer->MoveArmies(map, source, destination, armies_to_move, action);

					move_count = move_count - success;

					if (move_count == 0) break;

					cout << "Move more armies or yield your turn? (y/n): ";
					cin >> take;
				}
				break;
				
			} while (take == 'y' || take == 'n');
		}

		if (action == "add" || and_invoked)
		{
			do {
				if (!or_invoked && !and_invoked) {
					cout << "\nWould you like to take the above action or ignore it? (y/n): ";
					cin >> take;

					if (take == 'n' || take == 'N')
					{
						break; // ignore action
					}
				}
				if (and_invoked) {
					cout << "\nWould you like to add armies to a region? (y/n): ";
					cin >> take;

					if (take == 'n' || take == 'N')
					{
						action = "destroy";
						break;
					}
				}

				int add_count = readCard.second;

				while (add_count > 0 && take != 'n')
				{
					int source = -1;
					int armies_to_add = -1;

					for (Player* player : players)
						map->PrintPlayerRegions(player->GetName());

					do
					{
						cout << "\nChoose a region with at least 1 city to add armies: ";
						cin >> source;
					} while (source <= 0);
					do
					{
						cout << "\nNumber of armies to add? Out of a possible " << add_count << ": ";
						cin >> armies_to_add;
					} while (armies_to_add <= 0 || armies_to_add > add_count);

					int success = startingPlayer->AddArmies(map, map->GetRegion(source), armies_to_add);

					add_count = add_count - success;

					if (add_count == 0) break;

					cout << "Add more armies or yield your turn? (y/n): ";
					cin >> take;
				}
				break;
			} while (take == 'y' || take == 'n');
		}

		if (action == "destroy")
		{
			do {
				if (!or_invoked && !and_invoked) {
					cout << "\nWould you like to take the above action or ignore it? (y/n): ";
					cin >> take;

					if (take == 'n' || take == 'N')
					{
						break; // ignore action
					}
				}
				if (and_invoked) {
					cout << "\nWould you like to destroy an army on your region? (y/n): ";
					cin >> take;

					if (take == 'n' || take == 'N')
					{
						break;
					}
				}

				int destroy_army = readCard.second;

				if (and_invoked)
					destroy_army = 1;

				while (destroy_army > 0 && take != 'n')
				{
					int source = -1;
					string enemy = "a";

					for (Player* player : players)
						map->PrintPlayerRegions(player->GetName());

					do
					{
						cout << "\nWhose army do you wish to destroy? ";
						cin >> enemy;
					} while (enemy != "CPU0" && enemy != "CPU1" && enemy != "CPU2" && enemy != "CPU3" && enemy != "CPU4");

					do
					{
						cout << "\nFrom which region? ";
						cin >> source;
					} while (source <= 0);

					int success = startingPlayer->DestroyArmy(map, source, enemy);

					destroy_army = destroy_army - success;

					if (destroy_army == 0) break;

					cout << "Destroy an army or yield your turn? (y/n): ";
					cin >> take;
				}
				break;
			} while (take == 'y' || take == 'n');
		}
		if (action == "build")
		{
			do {
				if (!or_invoked) {
					cout << "\nWould you like to take the above action or ignore it? (y/n): ";
					cin >> take;

					if (take == 'n' || take == 'N')
					{
						break; // ignore action
					}
				}

				int build_city = readCard.second;

				while (build_city > 0 && take != 'n')
				{
					int source = -1;

					for (Player* player : players)
						map->PrintPlayerRegions(player->GetName());

					do
					{
						cout << "\nChoose one of your regions to build a city: ";
						cin >> source;
					} while (source <= 0);


					int success = startingPlayer->BuildCity(map, source);

					build_city = build_city - success;

					if (build_city == 0) break;

					cout << "Build a city or yield your turn? (y/n): ";
					cin >> take;
				}
				break;
			} while (take == 'y' || take == 'n');
		}
		
		if(action == "default")
		{
			cout << "Something went wrong. Abort..." << endl;
		}

		if (position == players.size() - 1)
			position = 0;
		else
			position++;

	} while (input != 'q');
}