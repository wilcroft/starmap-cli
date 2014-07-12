all: starmap

starmap: main.cpp star.o map.o planet.o
	g++ main.cpp star.o planet.o map.o -o starmapv2 -std=c++11
	
lite: main.cpp star.o map.o
	g++ -g -std=c++11 -o starmapv2 main.cpp star.o map.o
	
star.o: star.cpp star.h planet.h util.h
	g++ -c -g -std=c++11 -o star.o star.cpp
	
map.o: map.cpp map.h star.h util.h
	g++ -c -g -std=c++11 -o map.o map.cpp 
	
planet.o: planet.cpp planet.h 
	g++ planet.cpp -c -g -o planet.o -std=c++11

run: starmap
	./starmapv2.exe
	
clean:
	rm -f *.o