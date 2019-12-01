#include "CardsFactory.h"


CardOptions::CardOptions() {
	this->ResetOptions();
}

CardOptions::~CardOptions() {}

void CardOptions::ResetOptions() {
	move = 0;
	add = 0;
	destroy = false;
	build = false;
	five = false;
	by_ship = false;
	OR = false;
	AND = false;
}

CardsFactory::CardsFactory(){}
CardsFactory::~CardsFactory(){}

Card* CardsFactory::GenerateCard(string type, string action, CardOptions* options)
{
	if (type == "FOREST") {
		return new ForestCard(action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
	}
	else if (type == "CARROT") {
		return new CarrotCard(action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
	}
	else if (type == "ANVIL") {
		return new AnvilCard(action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
	}
	else if (type == "ORE") {
		return new OreCard(action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
	}
	else if (type == "CRYSTAL") {
		return new CrystalCard(action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
	}
	else if (type == "WILD") {
		return new WildCard(action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
	}
	else return new Card(type, action, options->move, options->add, options->build, options->destroy, options->five, options->by_ship, options->OR, options->AND);
}

