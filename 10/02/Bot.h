using namespace std;

#ifndef BOT_H
#define BOT_H
class Bot{
		int loIndex, hiIndex, loVal, hiVal;
	public:
		Bot();
		int getLoVal();
		int getHiVal();
		int getLoIndex();
		int getHiIndex();
		void setIndexes(int lo, int hi);
		void setVal(int val);
		void resetVal();
};

const int NUM_BOTS = 210;
const int NUM_OUTS = 22;
const int LO = 17;
const int HI = 61;
#endif
