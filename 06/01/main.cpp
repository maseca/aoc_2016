#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const char ALPHA[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
					  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					  'u', 'v', 'w', 'x', 'y', 'z'};

void countLetters(char in, int* ary);
char findMax(int* chary);

int main(){
	ifstream inFile;
	string input, output;
	int char0[26] = {0};
	int char1[26] = {0};
	int char2[26] = {0};
	int char3[26] = {0};
	int char4[26] = {0};
	int char5[26] = {0};
	int char6[26] = {0};
	int char7[26] = {0};

	inFile.open("input.txt");
	
	while(inFile.good()){
		getline(inFile, input);

		if(inFile.good()){
			countLetters(input.at(0), char0);
			countLetters(input.at(1), char1);
			countLetters(input.at(2), char2);
			countLetters(input.at(3), char3);
			countLetters(input.at(4), char4);
			countLetters(input.at(5), char5);
			countLetters(input.at(6), char6);
			countLetters(input.at(7), char7);
		}
	}

	output.append(1, findMax(char0));
	output.append(1, findMax(char1));
	output.append(1, findMax(char2));
	output.append(1, findMax(char3));
	output.append(1, findMax(char4));
	output.append(1, findMax(char5));
	output.append(1, findMax(char6));
	output.append(1, findMax(char7));

	cout << output << endl;

	return 0;
}

void countLetters(char in, int* ary){
	switch(in){
		case 'a':
			ary[0]++;
			break;
		case 'b':
			ary[1]++;
			break;
		case 'c':
			ary[2]++;
			break;
		case 'd':
			ary[3]++;
			break;
		case 'e':
			ary[4]++;
			break;
		case 'f':
			ary[5]++;
			break;
		case 'g':
			ary[6]++;
			break;
		case 'h':
			ary[7]++;
			break;
		case 'i':
			ary[8]++;
			break;
		case 'j':
			ary[9]++;
			break;
		case 'k':
			ary[10]++;
			break;
		case 'l':
			ary[11]++;
			break;
		case 'm':
			ary[12]++;
			break;
		case 'n':
			ary[13]++;
			break;
		case 'o':
			ary[14]++;
			break;
		case 'p':
			ary[15]++;
			break;
		case 'q':
			ary[16]++;
			break;
		case 'r':
			ary[17]++;
			break;
		case 's':
			ary[18]++;
			break;
		case 't':
			ary[19]++;
			break;
		case 'u':
			ary[20]++;
			break;
		case 'v':
			ary[21]++;
			break;
		case 'w':
			ary[22]++;
			break;
		case 'x':
			ary[23]++;
			break;
		case 'y':
			ary[24]++;
			break;
		case 'z':
			ary[25]++;
			break;
		}
}

char findMax(int* chary){
	int maxIndex = 0;
	int maxCount = 0;

	for(int i = 0; i < 26; ++i){
		if(chary[i] > maxCount){
			maxIndex = i;
			maxCount = chary[i];
		}
	}

	return ALPHA[maxIndex];
}
