#include "Map.h"
#include "MapLoader.h"
#include <iostream>


// Region member functions 
Region::Region(){}

Region::~Region() 
{ 
}

Region::Region(int region_id, int continent_id) 
{	
	id = new int(region_id);
	this->continent_id = new int(continent_id);
	adjacents = new std::vector<std::pair<Region, int>>();
}

void Region::setOwner(std::string* owner) { this->owner = owner; }

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


// Continent member functions
Continent::Continent(){}


Continent::~Continent()
{
}

Continent::Continent(int id) 
{ 
	this->id = new int(id);
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
	std::cout << "Invalid -- Region " << region->GetId() << " already exists in continent " << region->GetContinentId() << "." << std::endl;
}


// Map
Map::Map() 
{
	continents = new std::map<int, Continent>();
}

Map::~Map()
{
}

void Map::AddContinent(Continent* continent)
{
	if (!continent) 
	{
		std::cout << "Invalid -- Continent can't be null." << std::endl;
		return;
	}
	if (!continent->GetId())
	{
		std::cout << "Invalid -- Continent's id can't be null." << std::endl;
		return;
	}
	continents->operator[](continent->GetId()) = *continent;
}

void Map::AddRegion(Region* region)
{

	if (!region)
	{
		std::cout << "Invalid -- Region can't be null." << std::endl;
		return;
	}
	if (!region->GetContinentId())
	{
		std::cout << "Invalid -- Region's continent can't be null." << std::endl;
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

Region Map::GetRegion(int region_id)
{
	for (auto cit = continents->begin(); cit != continents->end(); cit++)
	{
		Continent continent = cit->second;

		for (std::pair<int, Region> region_pair : continent.GetRegions())
		{
			if (region_pair.second.GetId() == region_id) 
			{
				return region_pair.second;
			}
		}
	}
}

void Map::PrintMap() {

	std::cout << std::endl;

	for (auto cit = continents->begin(); cit != continents->end(); cit++)
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

			std::cout << "region " << region.GetId() << " -> c" << region.GetContinentId() << std::endl;
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