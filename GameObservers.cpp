#include "GameObservers.h"

PhaseView::PhaseView()
{
}

PhaseView::PhaseView(Player* player, Hand* hand):
	_player_subject(player), _hand_subject(hand)
{
}

PhaseView::~PhaseView()
{
}

void PhaseView::Update()
{
	_hand_subject->PrintHand();
}

StatsView::StatsView()
{
}

StatsView::StatsView(Player* player, Map* map):
	_player_subject(player), _map_subject(map)
{
}

StatsView::~StatsView()
{
}

void StatsView::Update()
{
	_map_subject->PrintPlayerRegions(_player_subject->GetName());
	cout << endl;
	DisplayResources();
	cout << endl;
	ComputeGameScore();
}

void StatsView::DisplayResources()
{
	cout << "-----------------------------------------" << endl;
	cout << "*" << _player_subject->GetName() << "'s RESOURCES: (number of cards: " << _player_subject->GetCards().size() << ")*\n";
	cout << "-----------------------------------------" << endl;
	
		cout << "(" << _player_subject->CountResources("FOREST") << " Forests), " <<
		"(" << _player_subject->CountResources("CARROT") << " Carrots), " <<
		"(" << _player_subject->CountResources("ANVIL") << " Anvils), " <<
		"(" << _player_subject->CountResources("ORE") << " Ores), " <<
		"(" << _player_subject->CountResources("CRYSTAL") << " Crystals), " <<
		"(" << _player_subject->CountResources("WILD") << " Wilds)" <<
		endl;
}

void StatsView::ComputeGameScore()
{
	cout << "-----------------------------------------" << endl;
	cout << "*" << _player_subject->GetName() << "'s TENTATIVE SCORE*" << endl;
	cout << "-----------------------------------------" << endl;

	int good = ScoreGoods();
	int reg = ScoreRegions();
	int cont = ScoreContinents();
	cout << "Total = " << good + reg + cont << endl;
}

// computes the total score of the resources. This calculation is based on the eight minute empire rulebook
// players with wild cards are prompt to change them into the resources of their liking
int StatsView::ScoreGoods()
{
	int score = 0;

	int forest = _player_subject->CountResources("FOREST");
	int carrot = _player_subject->CountResources("CARROT");
	int anvil = _player_subject->CountResources("ANVIL");
	int ore = _player_subject->CountResources("ORE");
	int crystal = _player_subject->CountResources("CRYSTAL");
	int wild = _player_subject->CountResources("WILD");


	if (forest >= 4) {
		score = score + 5;
		forest = 0;
	}
	if (carrot >= 4) {
		score = score + 5;
		carrot = 0;
	}
	if (anvil >= 4) {
		score = score + 5;
		anvil = 0;
	}
	if (ore >= 4) {
		score = score + 5;
		ore = 0;
	}
	if (crystal >= 4) {
		score = score + 5;
		crystal = 0;
	}

	score = score + forest + carrot + anvil + ore + crystal;

	cout << "Goods = " << score << " + (" << wild << " wild cards)" << endl;
	return score;
}

// computes and returns the number of controlled regions for a given player
int StatsView::ScoreRegions()
{
	int reg = _map_subject->CountControlledRegions(_player_subject->GetName());
	cout << "Regions count = " << reg << endl; 
	return reg;
}

// computes and returns the number of controlled continents for a given player
int StatsView::ScoreContinents()
{
	int cont = _map_subject->CountControlledContinents(_player_subject->GetName());
	cout << "Continents count = " << cont << endl;
	return cont;
}