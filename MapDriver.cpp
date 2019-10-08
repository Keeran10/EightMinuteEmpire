#include <iostream>
#include "Map.h"

void PrintMap(Map* map);

int main()
{
	int a(1), b(1), c(2), d(3), e(4), f(5), g(2), h(6);
	
	Map* game_map = new Map();
	Continent* continent1 = new Continent(&a);
	Continent* continent2 = new Continent(&g);

	Region* region1 = new Region(&b, continent1);
	Region* region2 = new Region(&c, continent1);
	Region* region3 = new Region(&d, continent1);
	Region* region4 = new Region(&e, continent1);
	Region* region5 = new Region(&f, continent1);
	Region* region6 = new Region(&h, continent2);

	game_map->AddRegion(region1, continent1);
	game_map->AddRegion(region2, continent1);
	game_map->AddRegion(region3, continent1);
	game_map->AddRegion(region4, continent1);
	game_map->AddRegion(region5, continent1);
	game_map->AddRegion(region6, continent2);

	region1->AddAdjacent(region2, 1);
	region1->AddAdjacent(region3, 1);
	region1->AddAdjacent(region4, 1);
	region1->AddAdjacent(region5, 3);
	region2->AddAdjacent(region3, 1);
	region2->AddAdjacent(region4, 1);
	region3->AddAdjacent(region5, 1);
	region4->AddAdjacent(region5, 1);

	// Invalid inputs; should expect errors
	game_map->AddRegion(region5, continent1); // duplicate value
	game_map->AddRegion(region6, continent1); // region in more than 1 continent exception
	region5->AddAdjacent(region5, 1); // adding edge to self not allowed
	continent1 = NULL;
	game_map->AddRegion(region1, continent1); // null exception 

	PrintMap(game_map); 
	
	return 0;
}

// Displays entire map 
void PrintMap(Map* map) {
	
	std::cout << std::endl;
	std::map<int, Continent> continents = (*map).GetContinents();

	for (auto cit = continents.begin(); cit != continents.end(); cit++)
	{
		Continent continent = cit->second;
		int key = cit->first;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "continent " << cit->second.GetId() << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::map<int, Region> regions = continent.GetRegions();

		for (auto rit = regions.begin(); rit != regions.end(); ++rit)
		{
			Region region = rit->second;

			std::cout << "region " << region.GetId() << std::endl;
			std::cout << "adjacents: ";

			std::vector<std::pair<Region, int>> adjacents = region.GetAdjacents();

			for (auto const& adjacent : adjacents)
			{
				std::cout << "(" << adjacent.first.GetId() << ", " << adjacent.second << "), ";
			}
			
			std::cout << std::endl;
		}
	}
}