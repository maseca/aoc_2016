#include "Bot.h"

Bot::Bot(){
	loVal = -1;
	hiVal = -1;
	loIndex = NUM_BOTS + NUM_OUTS - 1;
	hiIndex = NUM_BOTS + NUM_OUTS - 1;
}

int Bot::getLoVal(){
	return loVal;
}

int Bot::getHiVal(){
	return hiVal;
}

int Bot::getLoIndex(){
	return loIndex;
}

int Bot::getHiIndex(){
	return hiIndex;
}

void Bot::setIndexes(int lo, int hi){
	loIndex = lo;
	hiIndex = hi;
}

void Bot::setVal(int val){
	if(loVal < 0)
		loVal = val;
	else if(val < loVal){
		int swap = loVal;
		loVal = val;
		hiVal = swap;
	}else
		hiVal = val;
}

void Bot::resetVal(){
	loVal = -1;
	hiVal = -1;
}
