#include "map.h"


Map::Map(int sizex, int sizey){
	std::random_device rd;
	long seed;
	
	seed = rd();
	
	cout << "Using seed " << seed << endl;
	buildMap(sizex,sizey,seed);
}
Map::Map(int sizex, int sizey, long seed){
	cout << "Using seed " << seed << endl;
	buildMap(sizex,sizey,seed);
}

void Map::buildMap(int sizex, int sizey, long seed){
	FILE* image;
	FILE* output;
	unsigned char intensity;
	double pct;
	double thresh;
	Star * newStar;
	char convertCMD[100];

	std::uniform_real_distribution<> dist(0,100);
	
	if (hasUserImg){
		image = fopen (inputImage.c_str(), "rb");
	}
	else{
		image = fopen (INPUTMAP,"rb");
	}
	if (image == nullptr) {
		cerr << "INPUT FILE NOT FOUND";
		exit (EXIT_FAILURE);
	}
	if (generateImage){
		output = fopen (OUTPUTRGB,"wb+");
	}
	std::mt19937 mt (seed);
	
	x = sizex;
	y = sizey;
	numStars = 0;
	
	grid = new Star** [y];
	for (int i = 0; i < y; i++){
		grid[i] =  new Star* [x]();
	}
		

	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			intensity = (fgetc(image) + 2*fgetc(image) + fgetc(image))/4;
			if (grid[i][j]==nullptr){
				thresh = (intensity+1)*(intensity+1)/65536.0*THRESHOLD;
				pct = dist(mt);
				PRINTDEBUG("%f, %f, (%d,%d)\t", pct, thresh, j, i);
				if ((j!=0 && grid[i][j-1] != nullptr) || (i!=0 && grid[i-1][j] != nullptr)){
					PRINTDEBUG("NULL-A\n");
					grid[i][j] = nullptr;
				}
				else if (j!=0 && i!=0 && grid[i-1][j-1] != nullptr){
					PRINTDEBUG("NULL-B\n");
					grid[i][j] = nullptr;
				}
				else if (j!=x-1 && i!=0 && grid[i-1][j+1] != nullptr){
					PRINTDEBUG("NULL-C\n");
					grid[i][j] = nullptr;
				}
				else if (pct <= thresh){
					PRINTDEBUG("Making Star...");
					bool starOK;
					//grid[i][j] = new Star (&mt);
					do{
						starOK=true;
						newStar = new Star (&mt);
						if (newStar->getSize() == GIANT && (j==x-1 || i==y-1))
							starOK=false;
						if (newStar->getSize() == SUPERGIANT && (j>x-3 || i>y-3))
							starOK=false;
						if ((newStar->getSize()==GIANT || newStar->getSize() == SUPERGIANT) && i!=0 && j!=x-2 && grid[i-1][j+2] != nullptr)
							starOK=false;
						if (newStar->getSize() == SUPERGIANT && i!=0 && j!=x-3 && grid[i-1][j+3] != nullptr)
							starOK=false;
						
						if (starOK==false){
							delete newStar;
							PRINTDEBUG("RETRYING...");
						}
					}while (!starOK);
					PRINTDEBUG("OK!\n");
					starList.push_back (newStar);
					PRINTDEBUG("\t ADDED TO LIST...");
					PRINTDEBUG(" ADDED TO GRID...");
					newStar->setX(j);
					newStar->setY(i);
					PRINTDEBUG(" COORIDINATES SET.\n");
					numStars ++;
									
					grid[i][j] = newStar;
					if (newStar->getSize()==GIANT){
						PRINTDEBUG("\t GIANTSTAR\n");
						grid[i][j+1] = newStar;
						grid[i+1][j] = newStar;
						grid[i+1][j+1] = newStar;
					}
					else if (newStar->getSize()==SUPERGIANT){
						PRINTDEBUG("\t SUPERGIANTSTAR\n");
						grid[i][j+1] = newStar;
						grid[i][j+2] = newStar;
						grid[i+1][j] = newStar;
						grid[i+1][j+1] = newStar;
						grid[i+1][j+2] = newStar;
						grid[i+2][j] = newStar;
						grid[i+2][j+1] = newStar;
						grid[i+2][j+2] = newStar;
					}	
					PRINTDEBUG("\t DONE\n");
				}
				else {
					PRINTDEBUG("NULL-D\n");
					grid[i][j] = nullptr;
				}
			}
		}
	}
	
	cout << "Grid Complete - Building Image... " << endl;
//	PRINTDEBUG("\t");
	//for (int i = 0; i < 10; i++)
		//PRINTDEBUG("0123456789");
	//PRINTDEBUG("\n");
	starListIterator=starList.begin();
	for (int i=0; i<numStars; i++){
		PRINTDEBUG ("%d:0x%X\n",i,*(starListIterator+i));
	}
	cout << endl;
	if (generateImage){
		for (int i = 0; i < y; i++){
			//PRINTDEBUG("%d:\t",i);
			PRINTDEBUG("%d:\n",i);
			for (int j = 0; j < x; j++){
				PRINTDEBUG("\t%d\t0x%X\n",j,grid[i][j]);
				if (grid[i][j] == nullptr){
				//	PRINTDEBUG("-");
					fputc(0,output);
					fputc(0,output);
					fputc(0,output);
				}
				else{
				//	PRINTDEBUG("C");
					rgb_t color = grid[i][j]->getColor();
					fputc(color.r,output);
					fputc(color.g,output);
					fputc(color.b,output);
				}
			}
			//PRINTDEBUG("\n");
		}
		fclose (output);
		PRINTDEBUG("CONVERTING IMAGE FROM RAW...");
		sprintf(convertCMD,"convert.exe -size %dx%d -depth 8 rgb:output.rgb -scale 400%% output.png",x,y);
		cout << convertCMD << endl;
		system(convertCMD);
		sprintf(convertCMD,"convert -size %dx%d output.png -size %dx%d largeout.png", x,y,2*x,2*y);
		system(convertCMD);
	}
	fclose (image);
	PRINTDEBUG("DONE!\n");
}

Map::~Map(){
	for (int i = 0; i < y; i++){
		delete grid[i];
	}
	delete grid;
	for (starListIterator=starList.begin(); starListIterator != starList.end(); starListIterator ++){
		delete (*starListIterator);
	}
}

Star* Map::getStar (int xco, int yco){
	if (xco < 0 || xco > x || yco < 0 || yco > y)
		return nullptr;
	else
		return grid[yco][xco];
}
int Map::getGridWidth () { return x;}
int Map::getGridHeight () { return y;}
long Map::getNumStars () {return numStars;}

void Map::printAllStars(){
	for (starListIterator=starList.begin(); starListIterator != starList.end(); starListIterator ++){
		(*starListIterator)->printStarInfo();
	}
}
	

//starListIterator Map::begin() {return starList.begin(); }
//starListIterator Map::end() {return starList.end(); }