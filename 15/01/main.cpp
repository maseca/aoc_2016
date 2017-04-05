#include <iostream>
using namespace std;

class Disc{
		unsigned int pos, mod;
	public:
		Disc(unsigned int p, unsigned int m);
		Disc operator++(int);
		unsigned int getPos();
		unsigned int getMod();
};

Disc::Disc(unsigned int p, unsigned int m){
	pos = p;
	mod = m;
}

Disc Disc::operator++(int){
	pos = ++pos % mod;
	return *this;
}

unsigned int Disc::getPos(){
	return pos;
}

unsigned int Disc::getMod(){
	return mod;
}

int main(){
	Disc* discs[6];
	int time = -1;

	discs[0] = new Disc(15, 17);
	discs[1] = new Disc(2, 3);
	discs[2] = new Disc(4, 19);
	discs[3] = new Disc(2, 13);
	discs[4] = new Disc(2, 7);
	discs[5] = new Disc(0, 5);

	for(int i = 1; i < 6; ++i)
		for(int j = 0; j < i; ++j)
			(*discs[i])++;

	while(discs[0]->getPos() != 0 || 
		  discs[0]->getPos() != discs[1]->getPos() ||
		  discs[1]->getPos() != discs[2]->getPos() || 
		  discs[2]->getPos() != discs[3]->getPos() ||
		  discs[3]->getPos() != discs[4]->getPos() || 
		  discs[4]->getPos() != discs[5]->getPos()){
		++time;
		for(int i = 0; i < 6; ++i)
			(*discs[i])++;
	}

	cout << time << endl;

	return 0;
}
