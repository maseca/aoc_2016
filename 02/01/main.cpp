#include "Numpad.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){
	Numpad elf;
	ifstream inFile;
	char udlr;

	inFile.open("input.txt");
	while(inFile.good()){
		inFile.get(udlr);
		if(inFile.good()){
			if(udlr == '\n')
				cout << elf.getNum();
			else
				elf.setNum(udlr);
		}
	}

	cout << endl;

	return 0;
}
