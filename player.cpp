#include "player.h"

rgb_t getPlayerColor(enum starmapPlayer p){
	rgb_t color;
	switch (p){
		case STARMAPPLAYER_ONE:
			color.r=0;
			color.g=0xcb;
			color.b=0;
			break;
		case STARMAPPLAYER_TWO:
            color.r=29;//0xff;
            color.g=90;//0;
            color.b=252;//0xe8;
			break;
		case STARMAPPLAYER_THREE:
			color.r=0xbf;
			color.g=0xbf;
			color.b=0xbf;
			break;
		case STARMAPPLAYER_FOUR:
			color.r=0;
			color.g=0xff;
			color.b=0xbf;
			break;
		case STARMAPPLAYER_FIVE:
			color.r=0xff;
			color.g=0x45;
			color.b=0;
			break;
		case STARMAPPLAYER_SIX:
			color.r=0xff;
			color.g=0xf9;
			color.b=0;
			break;
		case STARMAPPLAYER_SEVEN:
			color.r=0;
			color.g=0;
			color.b=0;
			break;
		case STARMAPPLAYER_EIGHT:
			color.r=0;
			color.g=0;
			color.b=0;
			break;
		case STARMAPPLAYER_NIL:
		default:
			color.r=0;
			color.g=0;
			color.b=0;
	}
	return color;
}
