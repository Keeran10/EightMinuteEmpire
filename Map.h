#pragma once

#include <iostream>
#include <vector>
#include <map>

class Continent;

class Region 
{
private:
	int* id;
	int* continent_id;
	// this might need to be refactored into map<player -> pair<armies, cities>>
	std::string* owner;
	// the int represents the cost of travel (either 1 for land or 3 for water)
	typedef std::pair<Region, int> vertex;
	std::vector<vertex>* adjacents;

public:
	// Contructors & Destructors
	Region();
	~Region();
	Region(int id, int continent_id);
	// Getters and Setters
	std::string GetOwner();
	void setOwner(std::string* owner);
	int GetId() const;
	int GetContinentId();
	std::vector<vertex> GetAdjacents();
	void AddAdjacent(Region region, int cost);
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
	Continent(int id);
	int GetId();
	int* GetCId();
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
	void AddRegion(Region* region);
	void AddContinent(Continent* continent);
	Region GetRegion(int region_id);
	void PrintMap();
};

inline int Region::GetId() const { return *id; }
inline int Region::GetContinentId() { return *continent_id; }
inline std::string Region::GetOwner() { return *owner; }
inline std::vector<std::pair<Region, int>> Region::GetAdjacents() { return *adjacents; }

inline std::map<int, Region> Continent::GetRegions(){ return *regions; }
inline int Continent::GetId() { return *id; }
inline int* Continent::GetCId() { return id; }

inline std::map<int, Continent> Map::GetContinents() { return *continents;}