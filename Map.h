#pragma once

#include <iostream>
#include <vector>
#include <map>

class Continent;

class Region 
{
private:
	int* id;
	Continent* continent;
	// this might need to be refactored into map<player -> pair<armies, cities>>
	std::string* owner;
	// the int represents the cost of travel (either 1 for land or 3 for water)
	typedef std::pair<Region, int> vertex;
	std::vector<vertex>* adjacents;

public:
	// Contructors & Destructors
	Region();
	~Region();
	Region(int* id, Continent* continent);
	// Getters and Setters
	std::string GetOwner();
	void setOwner(std::string* owner);
	int GetId() const;
	Continent GetContinent();
	std::vector<vertex> GetAdjacents();
	void AddAdjacent(Region* region, int cost);
};



class Continent
{
private:
	int* id;
	std::map<int, Region>* regions;
	
public:
	std::string s;
	Continent();
	~Continent();
	Continent(int* id);
	int GetId();
	void AddRegion(Region* region);
	std::map<int, Region> GetRegions();
};

class Map
{
private:
	std::map<int, Continent>* continents;
public:
	Map();
	~Map();
	std::map<int, Continent> GetContinents();
	void AddRegion(Region* region, Continent* continent);
};

inline int Region::GetId() const { return *id; }
inline Continent Region::GetContinent() { return *continent; }
inline std::string Region::GetOwner() { return *owner; }
inline std::vector<std::pair<Region, int>> Region::GetAdjacents() { return *adjacents; }

inline std::map<int, Region> Continent::GetRegions(){ return *regions; }
inline int Continent::GetId() { return *id; }

inline std::map<int, Continent> Map::GetContinents() { return *continents;}