#include <bitset>
#include <stdio.h>
#include <string>
using namespace std;

const int INPUT = 1362;
const unsigned char RANGE = 51;

bool isWall(int posX, int posY, int input){
	int total, count;
	string bin;
	
	count = 0;
	total = posX*posX + 3*posX + 2*posX*posY + posY + posY*posY + input;
	bin = bitset<64>(total).to_string();

	for(int i = 0; i < 64; ++i)
		if(bin.at(i) == '1')
			++count;
	if(count % 2 == 0)
		return false;
	else
		return true;
}

int main(){
	char map[RANGE][RANGE+1];

	for(unsigned char i = 0; i < RANGE; ++i)
		for(unsigned char j = 0; j < RANGE; ++j)
			if(isWall(j, i, INPUT))
				map[i][j] = '#';
			else
				map[i][j] = '.';

	for(unsigned char i = 0; i < RANGE; ++i){
		map[i][RANGE] = '\0';
		puts(map[i]);
	}

	return 0;
}
