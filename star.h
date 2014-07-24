#ifndef __STARMAP_STAR_H_
#define __STARMAP_STAR_H_

#include <random>
#include <iostream>
#include "planet.h"
#include "util.h"

#define THRESHOLD 10.0

using namespace std;

enum starType{
	TYPE_NIL = 0,
	TYPE_RED,
	TYPE_ORANGE,
	TYPE_BLUE,
	TYPE_YELLOW,
	TYPE_WHITE,
	TYPE_BLUEWHITE,
	TYPE_BLUEVIOLET,
	TYPE_BROWN
};

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
		void setX(int);
		void setY(int);
		Planet* planet[5];
	
	public:
		Star (std::mt19937*);
//		Star (long, std::mt19937*);
		enum starType getType();
		enum starSize getSize();
		std::string getTypeString(); 
		std::string getSizeString(); 
		void printStarInfo();
		rgb_t getColor();
		int getX();
		int getY();

};
#endif