#ifndef __STARMAP_UTIL_H_
#define __STARMAP_UTIL_H_
#include <string>

#define ISDEBUG 0
#define PRINTDEBUG(...) if (ISDEBUG) printf(__VA_ARGS__)

#define INPUTMAP "galaxy.rgb"
#define OUTPUTRGB "output.rgb"

extern std::string inputImage;
extern bool hasUserImg;
extern bool generateImage;

typedef struct rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} rgb_t;






#endif