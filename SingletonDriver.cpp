#include "Map.h"
#include "MapLoader.h"

using namespace std;

int main(){
    cout<< "Please select the first map"<<endl;
    Map* firstMap = MapLoader::GetMap();

    cout<< "Please select the second map"<<endl;
    Map *secondMap = MapLoader::GetMap();

    cout<<"The pointer to map 1 is: "<<firstMap<<endl;
    cout<<"The pointer to map 2 is: "<<secondMap<<endl;



}