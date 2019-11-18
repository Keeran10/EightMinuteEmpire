#include "Map.h"
#include "MapLoader.h"
#include <iostream>
using namespace std;

City::City()
{
}

City::City(string color, string owner) : color(color), owner(owner)
{
}

City::~City()
{
}

Army::Army()
{
}

Army::Army(string color, string owner) : color(color), owner(owner)
{
}

Army::~Army()
{
}

// Region member functions 
Region::Region(){}

Region::Region(int region_id, int continent_id)
{	
	id = region_id;
	this->continent_id = continent_id;
	adjacents = new std::vector<std::pair<Region, int>>();
	armies = new vector<Army*>();
	cities = new vector<City*>();
	owner = "none";
	assets = 0;
}

Region::~Region() 
{ 
}

// Adds the adjacent region to both concerned regions 
void Region::AddAdjacent(Region region, int cost)
{
	std::pair<Region, int> adjacent;

	if (this->GetId() == region.GetId())
	{
		std::cout << "Invalid -- Region " << region.GetId() << " can't be adjacent to itself." << std::endl;
		return;
	}

	// from calling region to adjacent
	adjacent.first = region;
	adjacent.second = cost;
	adjacents->push_back(adjacent);

	// from adjacent to calling region for bi-directionality
	adjacent.first = *this;
	region.adjacents->push_back(adjacent);
}

// Checks if two regions are adjacent and returns the cost of travel between them
int Region::IsAdjacent(Region region)
{
	for (auto const& adjacent : *region.adjacents)
	{
		if (adjacent.first.GetId() == this->GetId())
		{
			return adjacent.second;
		}
	}
	return 0;
}

// Checks how many armies a specific user has on this region
int Region::CountArmies(string name)
{
	int ctr = 0;

	for (Army* army : *armies)
	{
		if (army->GetOwner() == name) ctr++;
	}

	return ctr;
}

// Checks how many cities a specific user has on this region
int Region::CountCities(string name)
{
	int ctr = 0;

	for (City* city : *cities)
	{
		if (city->GetOwner() == name) ctr++;
	}

	return ctr;
}

// displays a given region's adjacents
void Region::PrintAdjacents()
{
	cout << "\nadjacents to region " << this->GetId() << ": ";
	for (auto const& adjacent : *adjacents)
	{
		if(adjacent.second == 1)
			std::cout << " region " << adjacent.first.GetId() << " by land, " ;
		else
			std::cout << " region " << adjacent.first.GetId() << " by ship, ";
	}
}

// Continent member functions
Continent::Continent(){}

Continent::Continent(int id) 
{ 
	this->id = new int(id);
	regions = new std::map<int, Region*>();
	owner = "none";
	assets = 0;
}

Continent::~Continent()
{
}

// adds region to continent
// used by maploader to instantiate game map
void Continent::AddRegion(Region* region)
{
	if (region->GetContinentId() != this->GetId())
	{
		std::cout << "Invalid -- Region " << region->GetId() << " does not belong to continent " << this->GetId() << "." << std::endl;
	}

	std::map<int, Region*>::iterator itr = regions->find(region->GetId());

	if (itr == regions->end())
	{
		regions->operator[]((*region).GetId()) = region;
		return;
	}
	std::cout << "Invalid -- Region " << region->GetId() << " already exists in continent " << region->GetContinentId() << "." << std::endl;
}

// validates if continent has changed ownership and sets the new owner
void Continent::CheckController(string name)
{
	int count = 0;

	for (std::pair<int, Region*> region_pair : this->GetRegions())
	{
		if (region_pair.second->GetOwner() == name)
			count++;
	}


	if (count > this->assets)
	{
		this->assets = count;
		this->owner = name;
	}

	else if (count == this->assets && this->owner != name)
	{
		this->owner = "none";
	}

}

Map* Map:: mapInstance = NULL; //added for part4 singleton 
// Map
Map::Map() 
{
	continents = new std::map<int, Continent>();
}

/*
added for part 4 singleton
*/
Map* Map:: getInstance(){
	if (mapInstance == NULL){
		mapInstance = new Map();//not sure what params to pass. 
	}
	else {
		std:: cout<< "The instance of the map has been created. Please try again!";
	}
	return mapInstance;
}

Map::~Map()
{
	delete continents;
	continents = NULL;
}

// adds continent to game map
// used by maploader to instantiate game map
void Map::AddContinent(Continent* continent)
{
	if (!continent) 
	{
		std::cout << "Invalid -- Continent can't be null." << std::endl;
		delete continent;
		continent = NULL;
		return;
	}
	if (!continent->GetId())
	{
		std::cout << "Invalid -- Continent's id can't be null." << std::endl;
		delete continent;
		continent = NULL;
		return;
	}
	continents->operator[](continent->GetId()) = *continent;
}

// adds region to game map
// used by maploader to instantiate game map
void Map::AddRegion(Region* region)
{
	if (!region)
	{
		std::cout << "Invalid -- Region can't be null." << std::endl;
		delete region;
		region = NULL;
		return;
	}
	if (!region->GetContinentId())
	{
		std::cout << "Invalid -- Region's continent can't be null." << std::endl;
		delete region;
		region = NULL;
		return;
	}

	std::map<int, Continent>::iterator itr = continents->find(region->GetContinentId());

	if (itr == continents->end())
	{
		continents->operator[](region->GetContinentId()) = *new Continent(region->GetContinentId());
		continents->at(region->GetContinentId()).AddRegion(region);
		return;
	}
	continents->at(region->GetContinentId()).AddRegion(region);
}

// returns the region pointer given its id
Region* Map::GetRegion(int region_id)
{
	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		for (std::pair<int, Region*> region_pair : continent.GetRegions())
		{
			if (region_pair.second->GetId() == region_id) 
			{
				return region_pair.second;
			}
		}
	}
	return NULL;
}

// returns the number of regions under a player's control
int Map::CountControlledRegions(string name)
{
	int count = 0;

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		for (std::pair<int, Region*> region_pair : continent.GetRegions())
		{
			if (region_pair.second->GetOwner() == name)
				count++;
		}
	}

	return count;
}

// returns the number of continents under a player's control
int Map::CountControlledContinents(string name)
{
	int count = 0;

	for (pair<int, Continent> continent_pair : *this->continents)
	{
		if (continent_pair.second.GetOwner() == name)
			count++;
	}

	return count;
}

// returns the number of armies on all regions combined
int Map::CountAllArmies(string name)
{
	int count = 0;

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		for (std::pair<int, Region*> region_pair : continent.GetRegions())
		{
			count = count + region_pair.second->CountArmies(name);
		}

	}

	return count;
}

// prints the regions, armies and cities of each players
void Map::PrintPlayerRegions(string name)
{
	bool control_change = false;

	cout << "\n-----------------------------------------" << endl;
	cout << "*" << name << "'s REGIONS*\n";
	cout << "-----------------------------------------";
	

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		cout << "\nContinent " << continent.GetId() << ": ";

		for (std::pair<int, Region*> region_pair : continent.GetRegions())
		{
			int count_armies = region_pair.second->CountArmies(name);
			int count_cities = region_pair.second->CountCities(name);

			int assets = count_armies + count_cities;

			if (region_pair.second->GetAssets() < assets)
			{
				region_pair.second->SetAssets(assets);
				region_pair.second->SetOwner(name);
				control_change = true;

				this->GetRegion(region_pair.second->GetId())->SetOwner(name);
				this->GetRegion(region_pair.second->GetId())->SetAssets(assets);

				cout << "Region " << region_pair.second->GetId() << " controlled by " << name << endl;
			}

			else if (region_pair.second->GetAssets() == assets && region_pair.second->GetOwner() != name)
			{
				region_pair.second->SetOwner("none");
				control_change = true;
			}

			if (count_armies > 0 && count_cities > 0)
			{
				cout << region_pair.second->GetId() << " (" << count_armies << " armies, " << count_cities << " cities), ";
			}
			else if (count_armies > 0)
			{
				cout << region_pair.second->GetId() << " (" << count_armies << " armies), ";
			}
			else if (count_cities > 0)
			{
				cout << region_pair.second->GetId() << " (" << count_cities << " cities), ";
			}
		}

		if (control_change)
		{
			this->continents->at(continent.GetId()).CheckController(name);
			continent.CheckController(name);
			control_change = false;
		}
	}
	cout << endl;
}

// displays the game map
void Map::PrintMap() {
	
	if (!this) 
	{
		std::cout << "No Map detected." << std::endl;
		return;
	}

	std::cout << std::endl;

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;
		int key = cit->first;

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "continent " << cit->second.GetId() << std::endl;
		std::cout << "-----------------------------------------" << std::endl;

		std::map<int, Region*> regions = continent.GetRegions();

		for (auto rit = regions.begin(); rit != regions.end(); ++rit)
		{
			Region* region = rit->second;

			std::cout << "region " << region->GetId() << " -> c" << region->GetContinentId() << std::endl;
			std::cout << "adjacents: ";

			std::vector<std::pair<Region, int>> adjacents = region->GetAdjacents();

			for (auto const& adjacent : adjacents)
			{
				std::cout << "(" << adjacent.first.GetId() << ", " << adjacent.second << "), ";
			}

			std::cout << std::endl;
		}
	}
}

void MapDriver() 
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
}

void MapLoaderDriver()
{
	// errors
	MapLoader* ml1 = new MapLoader("game_map_err0.txt");
	MapLoader* ml2 = new MapLoader("game_map_err1.txt");
	MapLoader* ml3 = new MapLoader("game_map_err2.txt");
	MapLoader* ml4 = new MapLoader("game_map_err3.txt");

	// success
	MapLoader* ml = new MapLoader("game_map.txt");

	ml->GetMap()->PrintMap();
}