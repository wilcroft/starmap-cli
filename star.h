#ifndef __STARMAP_STAR_H_
#define __STARMAP_STAR_H_

#include <random>
#include <iostream>
#include "planet.h"
#include "startype.h"
#include "util.h"

#define THRESHOLD 10.0

using namespace std;

enum starSize{
	NONE = 0,
	DWARF,
	GIANT,
	SUPERGIANT
};
enum starClass{
	CLASSO,
	CLASSB,
	CLASSA,
	CLASSF,
	CLASSG,
	CLASSK,
	CLASSM
};

class Map;

/***************************************************
 * Star Class
 *  A star is of one of three sizes, and seven colours.
 *  It links to up to 5 planets, which are sorted from
 *  smallest to largest orbits.
 *
 *  All aspects of the star - including the number and 
 *  type and location of planets, is determined off a
 *  seeded mt19937, which produces real values (0,100]
 ***************************************************/ 
class Star {
		friend Map;
		
		enum starType type;
		enum starSize size;
		int x, y;
		int numPlanets;
		Planet* planet[5];
	
		void setX(int);
		void setY(int);
		void addPlanets(std::mt19937*);
		
	public:
		Star (std::mt19937*);
		~Star();
//		Star (long, std::mt19937*);
		int getX();
		int getY();
		int getNumPlanets();
		enum starType getType();
		enum starSize getSize();
		std::string getTypeString(); 
		std::string getSizeString(); 
		void printStarInfo();
		rgb_t getColor();
		enum planetType getPlanetType(int);
		enum planetSize getPlanetSize(int);
		enum planetBiome getPlanetBiome(int);
		std::string getPlanetTypeString(int);
		std::string getPlanetSizeString(int);
		std::string getPlanetBiomeString(int);
		void printPlanet(int);
		

};
#endif