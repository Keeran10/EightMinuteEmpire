#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Continent;

class City
{
	string owner;
	string color;
public:
	City();
	City(string color, string owner);
	~City();
	inline string GetOwner() { return owner; }
	inline string GetColor() { return color; }
};

class Army {

	string color;
	string owner;
public:
	Army();
	Army(string color, string owner);
	~Army();
	inline string GetColor() { return color; }
	inline string GetOwner() { return owner; }
};

class Region 
{
private:
	int id;
	int continent_id;
	// this might need to be refactored into map<player -> pair<armies, cities>>
	string* owner;
	// the int represents the cost of travel (either 1 for land or 3 for water)
	typedef pair<Region, int> vertex;
	vector<vertex>* adjacents;
	vector<Army*>* armies;
	vector<City*>* cities;

public:
	// Contructors & Destructors
	Region();
	~Region();
	Region(int id, int continent_id);
	// Getters and Setters
	string GetOwner();
	void setOwner(string* owner);
	int GetId() const;
	int GetContinentId();
	vector<vertex> GetAdjacents();
	void AddAdjacent(Region region, int cost);
	void PrintAdjacents();

	// part 4
	int IsAdjacent(Region region);
	int CountArmies(string name);
	inline void SetArmy(Army* army) { armies->push_back(army); }
	inline void SetCity(City* city) { cities->push_back(city); }
	inline vector<Army*>* GetArmies() { return armies; }
	inline vector<City*>* GetCities() { return cities; }
};



class Continent
{
private:
	int* id;
	map<int, Region*>* regions;
	
public:
	string s;
	Continent();
	~Continent();
	Continent(int id);
	int GetId();
	int* GetCId();
	void AddRegion(Region* region);
	map<int, Region*> GetRegions();
};

class Map
{
private:
	map<int, Continent>* continents;
public:
	Map();
	~Map();
	map<int, Continent> GetContinents();
	void AddRegion(Region* region);
	void AddContinent(Continent* continent);
	Region* GetRegion(int region_id);
	void PrintPlayerRegions(string name);
	void PrintMap();
};

inline int Region::GetId() const { return id; }
inline int Region::GetContinentId() { return continent_id; }
inline string Region::GetOwner() { return *owner; }
inline vector<pair<Region, int>> Region::GetAdjacents() { return *adjacents; }

inline map<int, Region*> Continent::GetRegions(){ return *regions; }
inline int Continent::GetId() { return *id; }
inline int* Continent::GetCId() { return id; }

inline map<int, Continent> Map::GetContinents() { return *continents;}

void MapDriver();
void MapLoaderDriver();