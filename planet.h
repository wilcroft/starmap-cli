#ifndef __STARMAP_PLANET_H_
#define __STARMAP_PLANET_H_
#include <iostream>
#include <string>
#include <random>
#include "util.h"
#include "startype.h"

using namespace std;

enum planetType{
	PLANETTYPE_NOPLANET,
	PLANETTYPE_ROCKY,
	PLANETTYPE_GAS
};

enum planetSize{
	PLANETSIZE_NOPLANET,
	PLANETSIZE_SMALL,
	PLANETSIZE_AVERAGE,
	PLANETSIZE_LARGE,
	PLANETSIZE_GIANT
};

enum planetBiome{
	PLANETBIOME_NOPLANET,
	PLANETBIOME_BARREN,
	PLANETBIOME_ARID,
	PLANETBIOME_EARTHLIKE,
	PLANETBIOME_ARCTIC,
	PLANETBIOME_GAS
};



class Star;

class Planet{
		friend Star;
		
		enum planetType type;
		enum planetSize size;
		enum planetBiome biome;

		int numMoons;
		
		void setType(enum planetType);
		void setSize(enum planetSize);
		void setBiome(enum planetBiome);
		
	public:
		Planet();
		Planet(enum planetType);
		Planet(std::mt19937*, int, Star*);
		enum planetType getType();
		enum planetSize getSize();
		enum planetBiome getBiome();
		std::string getTypeString();
		std::string getSizeString();
		std::string getBiomeString();
		void printPlanet();
		
	


};


#endif