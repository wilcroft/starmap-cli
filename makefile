all: starmap

win: starmap-win

starmap: main.cpp star.o map.o planet.o
	g++ main.cpp star.o planet.o map.o -o starmap -std=c++11 -D ISCLI
	
lite: main.cpp star.o map.o
	g++ -g -std=c++11 -o lite main.cpp star.o map.o -D ISCLI
	
star.o: star.cpp star.h planet.h util.h
	g++ -c -g -std=c++11 -o star.o star.cpp -D ISCLI
	
map.o: map.cpp map.h star.h util.h
	g++ -c -g -std=c++11 -o map.o map.cpp -D ISCLI
	
planet.o: planet.cpp planet.h util.h
	g++ planet.cpp -c -g -o planet.o -std=c++11 

run: starmap
	./starmap

run-lite: lite
	./lite 200 200 -i 200x200.rgb --no-lookup

starmap-win: main.cpp starw.o mapw.o planetw.o
	i686-pc-mingw32-g++ main.cpp star.o planet.o map.o -o starmap-win -std=c++11 -D ISCLI

lite-win: main.cpp starw.o mapw.o 
	i686-pc-mingw32-g++ main.cpp starw.o mapw.o -o lite-win -std=c++11 -static -D ISCLI
	
starw.o: star.cpp star.h planet.h util.h
	i686-pc-mingw32-g++ -c -g -std=c++11 -o starw.o star.cpp -static -D ISCLI
	
mapw.o: map.cpp map.h star.h util.h
	i686-pc-mingw32-g++ -c -g -std=c++11 -o mapw.o map.cpp -static -D ISCLI
	
clean:
	rm -f *.o
	
