#pragma once
#include "Observer.h"
#include "Player.h"
#include <list>
using namespace std;


class PhaseView : public Observer {

private:
	Player* _player_subject;
	Hand* _hand_subject;

public:
	PhaseView();
	PhaseView(Player* player, Hand* hand);
	~PhaseView();
	void Update();
};


class StatsView : public Observer {

private:
	Player* _player_subject;
	Map* _map_subject;

public:
	StatsView();
	StatsView(Player* player, Map* map);
	~StatsView();
	void Update();
	void DisplayResources();
	void ComputeGameScore();
	int ScoreGoods();
	int ScoreRegions();
	int ScoreContinents();
};