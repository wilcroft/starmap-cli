#include "planet.h"
#include "star.h"

Planet::Planet(){

}
Planet::Planet(std::mt19937* mt, int orbit, Star* star){
	bool hasGas = false;
	std::uniform_int_distribution<> dist(0,99);
	int pct = dist(*mt);	
	
// No rocky planets on orbits outside of gas giant orbits
	for (int i=0; i<orbit; i++){
		if (star->getPlanetType(i)==PLANETTYPE_GAS){
			hasGas=true;
		}
	}
	
///////////////////////////////////////////////////////////	
//			Orbits	0		1		2		3		4
// A (Blue-White)	R		R4G6	R3G7	R2G8	G
// B (Blue)			R		R2G8	R1G9	G		G
// F (White)		R		R6H4	R3H		R5G5	G
// G (Yellow)		R		R5H5	R3H7	R4G6	R2G8
// K (Orange)		R		R4H6	R6H4	R3G7	R1G9
// M (Red)			R7H3	R3H7	R		G		G
// O (Blue-Violet)	-		-		-		-		-
///////////////////////////////////////////////////////////
	switch (star->getType()){
		case TYPE_BLUEWHITE:
			switch (orbit){
				case 0:
					type=PLANETTYPE_ROCKY;
					biome=PLANETBIOME_BARREN;
					size=PLANETSIZE_AVERAGE;
					break;
				case 1:
					if (pct<40){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 2:
					if (pct<30&&!hasGas){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 3:
					if (pct<20&&!hasGas){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 4:
					type=PLANETTYPE_GAS;
					biome=PLANETBIOME_GAS;
					size=PLANETSIZE_GIANT;
					break;
			}
			break;
		case TYPE_BLUE:
			switch (orbit){
				case 0:
					type=PLANETTYPE_ROCKY;
					biome=PLANETBIOME_BARREN;
					size=PLANETSIZE_AVERAGE;
					break;
				case 1:
					if (pct<20){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 2:
					if (pct<10&&!hasGas){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 3:
				case 4:
					type=PLANETTYPE_GAS;
					biome=PLANETBIOME_GAS;
					size=PLANETSIZE_GIANT;
					break;
			}
			break;
		case TYPE_WHITE:
			switch (orbit){
				case 0:
					type=PLANETTYPE_ROCKY;
					biome=PLANETBIOME_BARREN;
					size=PLANETSIZE_AVERAGE;
					break;
				case 1:
					if (pct<60){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<40)
                            biome=PLANETBIOME_ARID;
                        else if (pct<90)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 2:
					if (pct<30){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<20)
                            biome=PLANETBIOME_ARID;
                        else if (pct<70)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 3:
					if (pct<50){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 4:
					type=PLANETTYPE_GAS;
					biome=PLANETBIOME_GAS;
					size=PLANETSIZE_GIANT;	
					break;
			}
			break;
		case TYPE_YELLOW:
			switch (orbit){
				case 0:
					type=PLANETTYPE_ROCKY;
					biome=PLANETBIOME_BARREN;
					size=PLANETSIZE_AVERAGE;
					break;
				case 1:
					if (pct<50){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<30)
                            biome=PLANETBIOME_ARID;
                        else if (pct<80)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 2:
					if (pct<30){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<20)
                            biome=PLANETBIOME_ARID;
                        else if (pct<80)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;				
					}
					break;
				case 3:
					if (pct<40){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 4:
					if (pct<20&&!hasGas){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				;
			}
			break;
		case TYPE_ORANGE:
			switch (orbit){
				case 0:
					type=PLANETTYPE_ROCKY;
					biome=PLANETBIOME_BARREN;
					size=PLANETSIZE_AVERAGE;
					break;
				case 1:
					if (pct<40){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<30)
                            biome=PLANETBIOME_ARID;
                        else if (pct<90)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 2:
					if (pct<60){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<10)
                            biome=PLANETBIOME_ARID;
                        else if (pct<50)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 3:
					if (pct<30){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				case 4:
					if (pct<10&&!hasGas){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
					else{
						type=PLANETTYPE_GAS;
						biome=PLANETBIOME_GAS;
						size=PLANETSIZE_GIANT;					
					}
					break;
				;
			}
			break;
		case TYPE_RED:
			switch (orbit){
				case 0:
					if (pct<70){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<50)
                            biome=PLANETBIOME_ARID;
                        else if (pct<90)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 1:
					if (pct<30){
						type=PLANETTYPE_ROCKY;
						biome=PLANETBIOME_BARREN;
						size=PLANETSIZE_AVERAGE;
					}
                    else{
                        pct = dist(*mt);
                        type=PLANETTYPE_ROCKY;
                        if (pct<10)
                            biome=PLANETBIOME_ARID;
                        else if (pct<70)
                            biome=PLANETBIOME_EARTHLIKE;
                        else
                            biome=PLANETBIOME_ARCTIC;
						size=PLANETSIZE_AVERAGE;					
					}
					break;
				case 2:
					type=PLANETTYPE_ROCKY;
					biome=PLANETBIOME_BARREN;
					size=PLANETSIZE_AVERAGE;
					break;
				case 3:
					type=PLANETTYPE_GAS;
					biome=PLANETBIOME_GAS;
					size=PLANETSIZE_GIANT;		
					break;
				case 4:
					type=PLANETTYPE_GAS;
					biome=PLANETBIOME_GAS;
					size=PLANETSIZE_GIANT;		
					break;
			}
			break;
        default: ;
	}
}

Planet::Planet(enum planetType pType){
	type=pType;
}

enum planetType Planet::getType(){ return type;}
enum planetSize Planet::getSize(){ return size;}
enum planetBiome Planet::getBiome(){return biome;}
void Planet::setType(enum planetType pType) {type = pType;}
void Planet::setSize(enum planetSize pSize) {size = pSize;}
void Planet::setBiome(enum planetBiome pBiome) {biome = pBiome;}
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
void Planet::printPlanet(){
	if (type==PLANETTYPE_GAS){
		cout << "GAS GIANT" << endl;
	}
	else{
		cout << getSizeString() << " " << getBiomeString() << endl;
	}
}
