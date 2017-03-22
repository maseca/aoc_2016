#include "Taxi.h"
#include <fstream>
#include <cstdlib>

int main(){
	Taxi elf;
	ifstream inFile;
	char rl;
	bool isRight;
	short dist;

	inFile.open("input.txt");
	if(inFile.fail()){
		cerr << "File was not successfully opened.\n";
		exit(1);
	}else{
		while(inFile.good()){
			inFile.get(rl);
			switch(rl){
				case 'R':
					isRight = true;
					break;
				case 'L':
					isRight = false;
					break;
				default:
					cerr << "Read error.\n";
					exit(1);
			}
			inFile >> dist;
			inFile.ignore(2);

			elf.moveTaxi(isRight, dist);
		}
	}
	inFile.close();

	//elf.printResults();
	
	return(0);
}
