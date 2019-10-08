#include "Map.h"
#include "MapLoader.h"
#include <iostream>


// Region member functions 
Region::Region(){}
/**/
Region::~Region() 
{ 
	static int ctr = 0;
	//std::cout << "region destroyed: " << ctr << std::endl;
	ctr++;
}
/**/
Region::Region(int* id, Continent* continent) 
{	
	this->id = id;
	this->continent = continent;
	adjacents = new std::vector<std::pair<Region, int>>();
}

void Region::setOwner(std::string* owner) { this->owner = owner; }

void Region::AddAdjacent(Region* region, int cost)
{
	std::pair<Region, int> adjacent;

	if (this->GetId() == region->GetId())
	{
		std::cout << "Invalid -- Region " << region->GetId() << " can't be adjacent to itself." << std::endl;
		return;
	}

	// from calling region to adjacent
	adjacent.first = *region;
	adjacent.second = cost;
	adjacents->push_back(adjacent);

	// from adjacent to calling region for bi-directionality
	adjacent.first = *this;
	region->adjacents->push_back(adjacent);
}


// Continent member functions
Continent::Continent(){}

/**/
Continent::~Continent()
{
	static int ctr = 0;
	//std::cout << "continent destroyed: " << ctr << std::endl;
	ctr++;
}
/**/
Continent::Continent(int* continent_id) 
{ 
	id = continent_id;
	regions = new std::map<int, Region>();
}


void Continent::AddRegion(Region* region)
{
	std::map<int, Region>::iterator itr = regions->find(region->GetId());

	if (itr == regions->end())
	{
		regions->operator[]((*region).GetId()) = *region;
		return;
	}
	std::cout << "Invalid -- Region " << region->GetId() << " already exists in continent " << region->GetContinent().GetId() << "." << std::endl;
}


// Map
Map::Map() 
{
	continents = new std::map<int, Continent>();
}
/**/
Map::~Map()
{
	static int ctr = 0;
	//std::cout << "map destroyed: " << ctr << std::endl;
	ctr++;
}
/**/

void Map::AddRegion(Region* region, Continent* continent) 
{
	if (!region || !continent ) 
	{
		std::cout << "Invalid -- Region or Continent can't be null." << std::endl;
		return;
	}

	int continent_id = region->GetContinent().GetId();

	if (continent_id != continent->GetId())
	{
		std::cout << "Invalid -- Region " << region->GetId() << " does not belong to continent " << (*continent).GetId() << "." << std::endl;
		return;
	}

	std::map<int, Continent>::iterator itr = continents->find(continent_id);

	if (itr == continents->end())
	{
		continents->operator[]((*continent).GetId()) = *continent;
		continent->AddRegion(region);
		return;
	}
	
	continents->find(continent_id)->second.AddRegion(region);
}