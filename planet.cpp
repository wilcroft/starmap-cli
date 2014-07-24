#include "planet.h"

Planet::Planet(){

}


enum planetType Planet::getType(){ return type;}
enum planetSize Planet::getSize(){ return size;}
enum planetBiome Planet::getBiome(){return biome;}
std::string Planet::getTypeString(){
	switch (type){
		case PLANETTYPE_ROCKY:
				return "ROCKY";
		case PLANETTYPE_GAS:
				return "GAS";
		default:
				return "NONE";
	}
}
std::string Planet::getSizeString(){
	switch (size){
		case PLANETSIZE_SMALL:
				return "SMALL";
		case PLANETSIZE_AVERAGE:
				return "AVERAGE";
		case PLANETSIZE_LARGE:
				return "LARGE";
		default: 
				return "NONE";
	}	
}
std::string Planet::getBiomeString(){
	switch (biome){
		case PLANETBIOME_BARREN:
				return "BARREN";
		case PLANETBIOME_ARID:
				return "ARID";
		case PLANETBIOME_EARTHLIKE:
				return "EARTHLIKE";
		case PLANETBIOME_ARCTIC:
				return "ARCTIC";
		case PLANETBIOME_GAS:
				return "GAS GIANT";
		default:
				return "NONE";
	}
}