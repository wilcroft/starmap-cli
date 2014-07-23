#include <iostream>
#include <cstdlib>
#include <random>
#include <string>
#include <cstring>
#include "star.h"
#include "map.h"
//#include "util.h"

using namespace std;

void printHelpMsg(const char* progName){
		cout << "Usage: " << progName << " <x> <y> [<options>]" << endl;
		cout << "Options: " << endl;
		cout << "\t-h, --help                Display this help message." << endl;
		cout << "\t-s, --seed <int>          Specify the seed for generation. Random if not provided." << endl; 
		cout << "\t-i  --input-image <str>   Specify the image used for generating the map." << endl;
		cout << "\t-o  --output-image <str>  Specify the name of the generated image." << endl;
		cout << "\t    --no-output           Skip output image generation (Lookup mode)." << endl;
		cout << "\t    --no-lookup           Skip lookup mode (Only generate output image)." << endl;
}


	string inputImage;
	string outputImage;
	bool hasUserSeed = false;
	bool hasUserImg = false;
	bool hasUserOutputImg = false;
	bool generateImage = true;

int main(int argc, char ** argv){
	char* xptr;
	char* yptr;
	int x;
	int y;
	long seed;
	Map* myMap;
	
	string xstr, ystr;
	int xLookup, yLookup;
	bool doLookup = true;
	bool validX, validY;
	
/*	long seed = 1286040885;
	string seedString;
	
	cout << argc << endl;
 	if (argc != 1 && argc != 2){
		cout << "Error!" << endl;
		return -1;
	} */
	
//Check for Correct Arguments
	if (argc < 3){
		cout << "Error!" << endl;
		printHelpMsg(argv[0]);
		return -1;
	}

//Convert dimension arguments, checking for errors
	x = strtol (argv[1], &xptr, 10);
	y = strtol (argv[2], &yptr, 10);
	if (x <= 0 || (*xptr)!='\0'){
		cout << "An x-value of '" << argv[1] << "' is illegal." << endl;
		cout << "Enter a positive integer instead." << endl;
		return -1;
	}
	if (y <= 0 || (*yptr)!='\0'){
		cout << "A y-value of '" << argv[2] << "' is illegal." << endl;
		cout << "Enter a positive integer instead." << endl;
		return -1;
	}
	cout << x << " " << y << endl;
	
	int idx = 3;
	if (argc > 3){ //&& (argc-3)%2==0){
		cout << "Evaluating other options:" << endl;
		while (idx < argc){
			if (argv[idx][0] != '-'){
				cerr << "Invalid option '" << argv[idx] << "'.\n";
				printHelpMsg(argv[0]);
				return -1;
			}
			
			if (strcmp(argv[idx],"--help")==0||strcmp(argv[idx],"-h")==0){
				printHelpMsg(argv[0]);
				return 0;
			}
			else if (strcmp(argv[idx],"--seed")==0||strcmp(argv[idx],"-s")==0){
				if (hasUserSeed){
					cerr << "Error: Multiple seeds specified!" << endl;
					return -1;
				}
				if (argc <= idx+1){
					cerr << "Missing value for --seed option." << endl;
					return -1;
				}
				char * sdptr;
				seed = strtol(argv[idx+1],&sdptr,10);
				if (seed < 0 || *sdptr!='\0'){
					cerr << "Seed value must an integer be greater than 0." << endl;
					return -1;
				}
				hasUserSeed = true;
				idx +=2;
			}
			else if (strcmp(argv[idx],"--input-image")==0||strcmp(argv[idx],"-i")==0){
				if (hasUserImg){
					cerr << "Error: Multiple Input Images specified." << endl;
					return -1;
				}
				if (argc <= idx+1){
					cerr << "Missing value for --input-image option." << endl;
					return -1;
				}
				inputImage=argv[idx+1];
				cout << "Using image '" << inputImage << "'." << endl;
				idx+=2;
				hasUserImg=true;
			}
			else if (strcmp(argv[idx],"--output-image")==0||strcmp(argv[idx],"-o")==0){
				if (hasUserOutputImg){
					cerr << "Error: Multiple Output Images specified." << endl;
					return -1;
				}				
				if (argc <= idx+1){
					cerr << "Missing value for --output-image option." << endl;
					return -1;
				}
				if (!generateImage){
					cout << "Ignoring " << argv[idx] << " flag (--no-output specified)." << endl;
				}
				else{
					outputImage=argv[idx+1];
					cout << "Using image '" << outputImage << "'." << endl;
					hasUserOutputImg=true;
				}
				idx+=2;
			}
			else if (strcmp(argv[idx],"--no-output")==0){
				if (hasUserOutputImg){
					cout << "Ignoring user-defined output file." << endl;
				}
				generateImage = false;
				idx ++;
			}
			else if (strcmp(argv[idx],"--no-lookup")==0){
				if (hasUserOutputImg){
					cout << "Skipping Lookup Mode." << endl;
				}
				doLookup = false;
				idx ++;
			}
			else{
				cerr << "Unknown option '" << argv[idx] << "'.\n";
				return -1;
			}
		}
	}
	
	if (!hasUserSeed){
		myMap = new Map(x, y);
	}
	else {
		myMap = new Map(x, y, seed);
	}
	
	
	//myMap->printAllStars();
	cout << myMap->getNumStars() << " Stars Generated\n" << endl;
	
	//Lookup Mode
	if (doLookup)
		cout << "To lookup a star, enter the co-ordinates. To exit, enter -1" << endl;
	
	while (doLookup){
		validX=false;
		validY=false;
		while (!validX){
			cin >> xstr;
			xLookup = strtol ( xstr.c_str(),  &xptr, 10);
			if ((*xptr)!='\0'){
				cerr << "An x-value of '" << xstr << "' is illegal." << endl;
				cerr << "Enter a positive integer instead, or -1 to exit" << endl;
			}
			else if (xLookup == -1){
				doLookup=false;
				validX=true;	//X is actually invalid, but marked as valid so we can exit
			}
			else if (xLookup >= x || xLookup < 0){
				cerr << "X Co-ordinate must be less than " << x << " and greater than or equal to 0." << endl;
			}
			else
				validX=true;
		}
		while (!validY&&doLookup){	//get a Y coord unless we want to exit
			cin >> ystr;
			yLookup = strtol ( ystr.c_str(),  &yptr, 10);
			if ((*yptr)!='\0'){
				cerr << "A y-value of '" << ystr << "' is illegal." << endl;
				cerr << "Enter a positive integer instead." << endl;
			}
			else if (yLookup >= y || yLookup < 0){
				cerr << "Y Co-ordinate must be less than " << y << " and greater than or equal to 0." << endl;
			}
			else
				validY=true;
		}
		
		if (doLookup){
			if (myMap->getStar(xLookup,yLookup)==nullptr)
				cout << "No star at (" << xLookup << "," << yLookup << ")." << endl;
			else
				myMap->getStar(xLookup,yLookup)->printStarInfo();
		}
	}
	
	delete myMap;
	/* std::random_device rd;
	std::mt19937 mt (rd());
	
	for (int i = 0; i<10; i++){
		Star newStar(&mt);
		newStar.printStarType();
	}
 */



}