#include "star.h"


/**************************************
 *        PRIVATE FUNCTIONS
 **************************************/
void Star::setX(int newX){ x = newX; }
void Star::setY(int newY){ y = newY; }

void Star::addPlanets(std::mt19937* mt){
	std::uniform_real_distribution<> dist(0,100);
	double pct;
	double thresh;
	switch (type){
		case (TYPE_RED):		// M
////////////UNIMPLIMENTED!!!//////////////		
			for (int i=0; i<5; i++) {
				planet[i] = nullptr;
			}
			break;
		case (TYPE_ORANGE): 	// K
////////////UNIMPLIMENTED!!!//////////////	
			for (int i=0; i<5; i++) {
				planet[i] = nullptr;
			}
			break;
		case (TYPE_YELLOW): 	// G
				thresh = 20;
				for (int i=0; i<5; i++){
					pct = dist(*mt);
					if (pct<thresh){ //HIT
						planet[i] = new Planet(mt, i, this);
						thresh = thresh/3;
						numPlanets++;
					}
					else{
						planet[i] = nullptr;
						thresh=thresh+15;
					}
				}
			break;
		case (TYPE_WHITE):		// F
				thresh = 20;
				for (int i=0; i<5; i++){
					pct = dist(*mt);
					if (pct<thresh){ //HIT
						planet[i]=new Planet(mt, i, this);
						thresh = thresh/2;
						numPlanets++;
					}
					else{
						planet[i] = nullptr;
						thresh=thresh+10;
					}
				}	
			break;
		case (TYPE_BLUEWHITE):	// A
		case (TYPE_BLUE):		// B
				thresh = 2;
				for (int i=0; i<5; i++){
					pct = dist(*mt);
					if (pct<thresh){ //HIT
						planet[i]=new Planet(mt, i, this);
						thresh = thresh*0.9;
						numPlanets++;
					}
					else{
						planet[i] = nullptr;
						thresh=thresh*2.5;
					}
				}
				
			break;
		case (TYPE_BLUEVIOLET): // O
		default:
			for (int i=0; i<5; i++) {
				planet[i] = nullptr;
			}
	}
}

 
/**************************************
 *        PUBLIC FUNCTIONS
 **************************************/
 //Constructor
Star::Star (std::mt19937* mt) {
	double pct;
	std::uniform_real_distribution<> dist(0,100);
	pct = dist (*mt);
	
	if (pct < 76.45)
		type = TYPE_RED;
	else if (pct < 88.55)
		type = TYPE_ORANGE;
	else if (pct < 96.19)
		type = TYPE_YELLOW;
	else if (pct < 99.24)
		type = TYPE_WHITE;
	else if (pct < 99.87)
		type = TYPE_BLUEWHITE;
	else if (pct < 99.995)
		type = TYPE_BLUE;
	else
		type = TYPE_BLUEVIOLET;
		
	pct = dist(*mt);
	
	if (pct < 85)
		size = DWARF;
		
	// The following Stars classes can be giant-sized; others with be re-categorized
	//    RED
	//    BLUE
	//    BLUEVIOLET
	else if (pct < 98){
		size = GIANT;
		if (type == TYPE_ORANGE || type ==TYPE_YELLOW || type == TYPE_WHITE)
			type = TYPE_RED;
		else if (type == TYPE_BLUEWHITE)
			type = TYPE_BLUE;
	}		
	// The following Stars classes can be supergiant-sized; others with be re-categorized
	//    RED
	//    YELLOW
	//    BLUE
	//    BLUEVIOLET
	else{
		size = SUPERGIANT;
		if (type == TYPE_ORANGE)
			type = TYPE_RED;
		else if  (type == TYPE_WHITE)
			type = TYPE_YELLOW;
		else if (type == TYPE_BLUEWHITE)
			type = TYPE_BLUE;
	}
	
	//Generate Planets
	numPlanets=0;
	addPlanets(mt);
	
	
}

//Destructor
Star::~Star(){
	for (int i=0; i<5; i++)
		if (planet[i]!=nullptr)
			delete planet [i];
}

int Star::getX(){ return x;}
int Star::getY(){ return y;}

int Star::getNumPlanets(){return numPlanets;}

enum starType Star::getType(){ return type;}
enum starSize Star::getSize(){ return size;}

std::string Star::getTypeString(){
	switch (type){
		case TYPE_NIL:
				return "NONE";
		case TYPE_RED:
				return "RED";
		case TYPE_YELLOW:
				return "YELLOW";
		case TYPE_ORANGE:
				return "ORANGE";
		case TYPE_WHITE:
				return "WHITE";
		case TYPE_BLUE:
				return "BLUE";
		case TYPE_BLUEWHITE:
				return "BLUE-WHITE";
		case TYPE_BLUEVIOLET:
				return "BLUE-VIOLET";
		default:
				return "NONE";
	}
}std::string Star::getSizeString(){
	switch (size){
		case DWARF:
			return "DWARF";
		case GIANT:
			return "GIANT";
		case SUPERGIANT:
			return "SUPERGIANT";
		default:
			return "NONE";
	}
}

void Star::printStarInfo() { 
	cout << "(" << x << ", " << y << ") " ;
	switch (type){
		case TYPE_NIL:
				cout << "NONE" << endl;
				break;
		case TYPE_RED:
				cout << "RED ";
				break;	
		case TYPE_YELLOW:
				cout << "YELLOW ";
				break;
		case TYPE_ORANGE:
				cout << "ORANGE ";
				break;
		case TYPE_WHITE:
				cout << "WHITE ";
				break;
		case TYPE_BLUE:
				cout << "BLUE ";
				break;
		case TYPE_BLUEWHITE:
				cout << "BLUE-WHITE ";
				break;
		case TYPE_BLUEVIOLET:
				cout << "BLUE-VIOLET ";
	}
	switch (size){
		case DWARF:
			cout << "DWARF ";
			break;
		case GIANT:
			cout << "GIANT ";
			break;
		case SUPERGIANT:
			cout << "SUPERGIANT ";
			break;
	}
	cout << endl;
}


rgb_t Star::getColor(){
	rgb_t color;
	switch(type){
		case TYPE_RED:
			color.r=0xFF;
			color.g=0x82;
			color.b=0x59;
			break;
		case TYPE_ORANGE:
			color.r=0xFF;
			color.g=0xBB;
			color.b=0x78;
			break;
		case TYPE_YELLOW:
			color.r=0xFF;
			color.g=0xFF;
			color.b=0x9F;
			break;
		case TYPE_WHITE:
			color.r=0xFF;
			color.g=0xFF;
			color.b=0xFF;
			break;
		case TYPE_BLUEWHITE:
			color.r=0xCA;
			color.g=0xFA;
			color.b=0xFF;
			break;
		case TYPE_BLUE:
			color.r=0xBF;
			color.g=0xDC;
			color.b=0xFF;
			break;
		case TYPE_BLUEVIOLET:
			color.r=0x9D;
			color.g=0xBB;
			color.b=0xFF;
			break;
		default:
			color.r=0;
			color.g=0;
			color.b=0;
	}
	return color;
}

enum planetType Star::getPlanetType(int i){
	if (i<0 || i>=5 || planet[i]==nullptr)
		return PLANETTYPE_NOPLANET;
	else
		return planet[i]->getType();
}
enum planetSize Star::getPlanetSize(int i){
	if (i<0 || i>=5 || planet[i]==nullptr)
		return PLANETSIZE_NOPLANET;
	else
		return planet[i]->getSize();
}
enum planetBiome Star::getPlanetBiome(int i){
	if (i<0 || i>=5 || planet[i]==nullptr)
		return PLANETBIOME_NOPLANET;
	else
		return planet[i]->getBiome();
}
std::string Star::getPlanetTypeString(int i){
	if (i<0 || i>=5 || planet[i]==nullptr)
		return "";
	else
		return planet[i]->getTypeString();
}
std::string Star::getPlanetSizeString(int i){
	if (i<0 || i>=5 || planet[i]==nullptr)
		return "";
	else
		return planet[i]->getSizeString();
}
std::string Star::getPlanetBiomeString(int i){
	if (i<0 || i>=5 || planet[i]==nullptr)
		return "";
	else
		return planet[i]->getBiomeString();
}
void Star::printPlanet(int i){
	if (i>=0 && i<5 && planet[i]!=nullptr)
		planet[i]->printPlanet();
}

/* Star::Star (long seed, std::mt19937* mt) {
	double pct;
	std::mt19937 mt(seed); //set different seed
	std::uniform_real_distribution<> dist(0,100);
//	type = NOSTAR;
//	size = NONE;
	pct = dist(&mt);
} */