#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

const char ALPHA[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
					  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					  'u', 'v', 'w', 'x', 'y', 'z'};

bool isGood(short* ary, char* lets);
int checkName(stringstream& name);

int main(){
	ifstream inFile;
	string input;
	int sumTotal = 0;
	short totLines = 0;

	inFile.open("input.txt");
	
	while(inFile.good()){
		getline(inFile, input);
		//cout << input;
		stringstream currLine(input);
		sumTotal += checkName(currLine);
		totLines++;
	}

	cout << sumTotal << endl << totLines << endl;
	
	return 0;
}

bool isGood(short* ary, char* lets){
	short currMax, maxIndex, i;
	char five[6];
	bool yesGood = true;

	for(short j = 0; j < 5; j++){
		currMax = 0;
		maxIndex = 0;

		for(i = 0; i < 26; i++){
			if(ary[i] > currMax){
				currMax = ary[i];
				maxIndex = i;
			}
		}
		
		ary[maxIndex] = -1;
		five[j] = ALPHA[maxIndex];
	}

	five[5] = '\0';

	for(short j = 0; j < 5; j++){
		//cout << five[j] << lets[j];
		if(five[j] != lets[j]){
			yesGood = false;
			break;
		}
	}

	return yesGood;
}

int checkName(stringstream& name){
	short numAlphas[26] = {0};
	char currChar;
	int sum;
	char letters[6];

	while(name.good()){
		name.get(currChar);

		switch(currChar){
			case 'a':
				numAlphas[0]++;
				break;
			case 'b':
				numAlphas[1]++;
				break;
			case 'c':
				numAlphas[2]++;
				break;
			case 'd':
				numAlphas[3]++;
				break;
			case 'e':
				numAlphas[4]++;
				break;
			case 'f':
				numAlphas[5]++;
				break;
			case 'g':
				numAlphas[6]++;
				break;
			case 'h':
				numAlphas[7]++;
				break;
			case 'i':
				numAlphas[8]++;
				break;
			case 'j':
				numAlphas[9]++;
				break;
			case 'k':
				numAlphas[10]++;
				break;
			case 'l':
				numAlphas[11]++;
				break;
			case 'm':
				numAlphas[12]++;
				break;
			case 'n':
				numAlphas[13]++;
				break;
			case 'o':
				numAlphas[14]++;
				break;
			case 'p':
				numAlphas[15]++;
				break;
			case 'q':
				numAlphas[16]++;
				break;
			case 'r':
				numAlphas[17]++;
				break;
			case 's':
				numAlphas[18]++;
				break;
			case 't':
				numAlphas[19]++;
				break;
			case 'u':
				numAlphas[20]++;
				break;
			case 'v':
				numAlphas[21]++;
				break;
			case 'w':
				numAlphas[22]++;
				break;
			case 'x':
				numAlphas[23]++;
				break;
			case 'y':
				numAlphas[24]++;
				break;
			case 'z':
				numAlphas[25]++;
				break;
			case '-':
				if(isdigit(name.peek())){
					name >> sum;
					name.ignore();
					for(short i = 0; i < 5; i++)
						name.get(letters[i]);
					letters[5] = '\0';
					name.ignore();
				}
		}
	}
	if(isGood(numAlphas, letters)){
		//cout << sum << endl;
		return sum;
	}else
		return 0;
}
