#ifndef __STARMAP_UTIL_H_
#define __STARMAP_UTIL_H_
#include <string>

#define ISDEBUG 0
#define PRINTDEBUG(...) if (ISDEBUG) printf(__VA_ARGS__)

#define INPUTMAP "../200x200.rgb"
#define OUTPUTRGB "output.rgb"

#ifndef ISCLI
#define ISCLI 1
#endif

#if ISCLI
extern std::string inputImage;
extern bool hasUserImg;
extern bool generateImage;
#else
#define hasUserImg 0
#define generateImage 1

#endif
typedef struct rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} rgb_t;






#endif
