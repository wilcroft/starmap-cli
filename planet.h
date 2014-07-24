#ifndef __STARMAP_PLANET_H_
#define __STARMAP_PLANET_H_
#include <string>
#include "util.h"

enum planetType{
	PLANETTYPE_ROCKY,
	PLANETTYPE_GAS
};

enum planetSize{
	PLANETSIZE_SMALL,
	PLANETSIZE_AVERAGE,
	PLANETSIZE_LARGE
};

enum planetBiome{
	PLANETBIOME_BARREN,
	PLANETBIOME_ARID,
	PLANETBIOME_EARTHLIKE,
	PLANETBIOME_ARCTIC,
	PLANETBIOME_GAS
};




class Planet{
		enum planetType type;
		enum planetSize size;
		enum planetBiome biome;

		int numMoons;
		
	public:
		Planet();
		enum planetType getType();
		enum planetSize getSize();
		enum planetBiome getBiome();
		std::string getTypeString();
		std::string getSizeString();
		std::string getBiomeString();
		
	


};


#endif