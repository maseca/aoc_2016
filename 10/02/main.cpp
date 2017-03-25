#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Bot.h"

int main(){
	ifstream inFile;
	stringstream ss;
	string temp;
	Bot botArr[NUM_BOTS + NUM_OUTS]; //output 0 == botArr[210 + 0]
	Bot reset;
	int index, low, high, value;
	bool isOutLo, isOutHi, moved;

	inFile.open("input.txt");
	while(inFile.good()){
		getline(inFile, temp);
		if(inFile.good()){
			ss.clear();
			ss.str(temp);
			isOutLo = isOutHi = false;
			//cout << temp << endl; //test
			if(ss.good() && ss.peek() == 'b'){
				while(ss.good()){
					if(isdigit(ss.peek())){
						ss >> index;
						break;
					}else
						ss.ignore();
				}
				while(ss.good()){
					if(isdigit(ss.peek())){
						ss >> low;
						break;
					}else if(ss.peek() == 'o'){
						ss.ignore();
						if(ss.peek() == 'u')
							isOutLo = true;
					}else
						ss.ignore();
				}
				while(ss.good()){
					if(isdigit(ss.peek())){
						ss >> high;
						break;
					}else if(ss.peek() == 'o'){
						ss.ignore();
						if(ss.peek() == 'u')
							isOutHi = true;
					}else
						ss.ignore();
				}
				
				if(isOutLo)
					low += NUM_BOTS;
				if(isOutHi)
					high += NUM_BOTS; 

				botArr[index].setIndexes(low, high);
				/*cout << index << endl 
					 << botArr[index].getLoIndex() << endl 
					 << botArr[index].getHiIndex() << endl;*/

			}else if(ss.good() && temp.at(0) == 'v'){
				while(ss.good()){
					if(isdigit(ss.peek())){
						ss >> value;
						break;
					}else
						ss.ignore();
				}
				while(ss.good()){
					if(isdigit(ss.peek())){
						ss >> index;
						break;
					}else
						ss.ignore();
				}

				botArr[index].setVal(value);
				/*cout << index << endl
					 << botArr[index].getLoVal() << endl
					 << botArr[index].getHiVal() << endl;*/
			}

			do{
				moved = false;
				for(int i = 0; i < NUM_BOTS; ++i){
					/*if(botArr[i].getLoVal() == LO && botArr[i].getHiVal() == HI){
						cout << i << endl;
						return 0;
					}*/
					if(botArr[i].getLoVal() > 0 && botArr[i].getHiVal() > 0
					   && botArr[i].getLoIndex() < NUM_BOTS + NUM_OUTS - 1
					   && botArr[i].getHiIndex() < NUM_BOTS + NUM_OUTS - 1){
						botArr[botArr[i].getLoIndex()].setVal(botArr[i].getLoVal());
						botArr[botArr[i].getHiIndex()].setVal(botArr[i].getHiVal());
						botArr[i].resetVal();
						moved = true;
					}
				}
				//cout << ":\n"; //test
			}while(moved);
		}
	}
	inFile.close();

	cout << botArr[NUM_BOTS].getLoVal() * botArr[NUM_BOTS+1].getLoVal() * botArr[NUM_BOTS+2].getLoVal() << endl; 

	return 0;
}
