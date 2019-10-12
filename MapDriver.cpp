/**
#include <iostream>
#include "Map.h"

int main()
{
	int a(1), b(1), c(2), d(3), e(4), f(5), g(2), h(6);
	
	Map* game_map = new Map();
	Continent* continent1 = new Continent(a);
	Continent* continent2 = new Continent(g);

	Region* region1 = new Region(b, continent1->GetId());
	Region* region2 = new Region(c, continent1->GetId());
	Region* region3 = new Region(d, continent1->GetId());
	Region* region4 = new Region(e, continent1->GetId());
	Region* region5 = new Region(f, continent1->GetId());
	Region* region6 = new Region(h, continent2->GetId());

	game_map->AddRegion(region1);
	game_map->AddRegion(region2);
	game_map->AddRegion(region3);
	game_map->AddRegion(region4);
	game_map->AddRegion(region5);
	game_map->AddRegion(region6);

	region1->AddAdjacent(*region2, 1);
	region1->AddAdjacent(*region3, 1);
	region1->AddAdjacent(*region4, 1);
	region1->AddAdjacent(*region5, 3);
	region2->AddAdjacent(*region3, 1);
	region2->AddAdjacent(*region4, 1);
	region3->AddAdjacent(*region5, 1);
	region4->AddAdjacent(*region5, 1);

	// Invalid inputs; should expect errors
	game_map->AddRegion(region5); // duplicate value
	game_map->AddRegion(region6); // region in more than 1 continent exception
	region5->AddAdjacent(*region5, 1); // adding edge to self not allowed
	continent1 = NULL;
	game_map->AddRegion(region1); // null exception 

	game_map->PrintMap(); 

	return 0;
}

/**/