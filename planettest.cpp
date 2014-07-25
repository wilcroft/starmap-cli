#include <iostream>
#include <random>
#include "planet.h"

// A = Blue-White
// B = Blue
// F = White
// G = Yellow
// K = Orange
// M = Red
// O = Blue-Violet

int main(int argc, char** argv){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<> dist(0,100);
	
	double pct; //pct= dist(mt);
	double thresh;
	char starType=argv[1][0];
	int num [5] = {0,0,0,0,0};
	
	
	Planet* planets[5];
	
	switch (starType){
		case 'A':
			
			break;
		case 'B':
				thresh = 2;
				for (int i=0; i<5; i++){
					pct = dist(mt);
					if (pct<thresh){ //HIT
						//planets[i] = new Planet();
						thresh = thresh*0.9;
						num[i]++;
					}
					else{
						planets[i] = nullptr;
						thresh=thresh*2.5;
					}
				}
				
			break;
		case 'F':
			for (int j=0;j<1000000; j++){
				thresh = 20;
				for (int i=0; i<5; i++){
					pct = dist(mt);
					if (pct<thresh){ //HIT
						//planets[i] = new Planet();
						thresh = thresh/2;
						num[i]++;
					}
					else{
						planets[i] = nullptr;
						thresh=thresh+10;
					}
				}
				
			}		
			break;
		case 'G':
				thresh = 20;
				for (int i=0; i<5; i++){
					pct = dist(mt);
					if (pct<thresh){ //HIT
						//planets[i] = new Planet();
						thresh = thresh/3;
						num[i]++;
					}
					else{
						planets[i] = nullptr;
						thresh=thresh+15;
					}
				}
			
			break;
		case 'K':
			
			break;
		case 'M':
			
			break;
		case 'O':
			for (int i=0; i<5; i++) {
				planets[i] = nullptr;
			}
			break;
		default: return 0;	
	}
	for (int i=0; i<5; i++){
		cout << "Planet " << i << ": " ;
		cout << num[i] << " (" << num[i]/10000.0 << "%)" << endl;
		/*if (planets[i]==nullptr){
			cout << "N/A" << endl;
		}
		else{
			//planets[i]->printPlanet();
			cout << planets[i]->getTypeString() << endl;
			delete planets[i];
		}*/
	}
	
	return 0;
}