#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

const char ALPHA[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
					  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					  'u', 'v', 'w', 'x', 'y', 'z'};

int yankSum(stringstream& name);
string shift(stringstream& name, const int& sum);

int main(){
	ifstream inFile;
	ofstream outFile;
	string input;
	int currSum = 0;
	short totLines = 0;

	inFile.open("new-in.txt");
	outFile.open("new-out.txt");

	while(inFile.good()){
		getline(inFile, input);
		stringstream currLine(input);
		currSum = yankSum(currLine);

		stringstream sameLine(input);
		outFile << shift(sameLine, currSum);
		totLines++;
	}

	return 0;
}

int yankSum(stringstream& name){
	char currChar;
	int sum;

	while(name.good()){
		name.get(currChar);

		if(currChar == '-')
			if(isdigit(name.peek())){
				name >> sum;
				name.ignore(999);
			}
	}

	return sum;
}

string shift(stringstream& name, const int& sum){
	char currChar;
	string charStr;
	string outString;
	
	while(name.good()){
		name.get(currChar);
		if(!isalpha(currChar))
			currChar = ' ';
		else
			currChar = ((currChar + sum - 97) % 26) + 97;

		charStr = currChar;
		outString.append(charStr);
	}
	outString.append("\n");

	return outString;
}
