#ifndef __STARMAP_MAP_H_
#define __STARMAP_MAP_H_

#include <random>
#include "star.h"
#include "util.h"
#include <iterator>
#include <cstdio>

using namespace std;

class Map{
		int x;
		int y;
		
		long numStars;
		long numPlanets;
		long mapSeed;
		
		vector<Star*> starList;
		
		Star *** grid;
		
		void buildMap(int, int, long);
	
	public:
		vector<Star*>::iterator starListIterator;
		Map (int, int);
		Map (int, int, long);
		~Map ();
		Star* getStar(int,int);
		int getGridWidth();
		int getGridHeight();
        vector<Star*>::iterator begin();
        vector<Star*>::iterator end();
		void printAllStars();
		long getNumStars();
		long getNumPlanets();
		long getMapSeed();
		
};












#endif
