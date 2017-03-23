#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool isTLS(const string& str);

int main(){
	ifstream inFile;
	stringstream buffer;
	string input, first, second, third, fourth, fifth, sixth, seventh;
	size_t found;
	int numIPs = 0;
	int numBrackets = 0;

	inFile.open("input.txt");
	
	while(inFile.good()){
		numBrackets = 0;
		getline(inFile, input);
		stringstream buffer(input);

		found = input.find("[");
		if(found != string::npos){
			++numBrackets;
			found = input.find("[", found+1, 1);
				if(found != string::npos){
					++numBrackets;
					found = input.find("[", found+1, 1);
					if(found != string::npos)
						++numBrackets;
				}
		}

		switch(numBrackets){
			case 1:
				getline(buffer, first, '[');
				getline(buffer, second, ']');
				getline(buffer, third);

				if(inFile.good() && !isTLS(second))
					if(isTLS(first) || isTLS(third))
						++numIPs;
				break;
			case 2:
				getline(buffer, first, '[');
				getline(buffer, second, ']');
				getline(buffer, third, '[');
				getline(buffer, fourth, ']');
				getline(buffer, fifth);

				if(inFile.good() && !isTLS(second) && !isTLS(fourth))
					if(isTLS(first) || isTLS(third) || isTLS(fifth))
						++numIPs;
				break;
			case 3:
				getline(buffer, first, '[');
				getline(buffer, second, ']');
				getline(buffer, third, '[');
				getline(buffer, fourth, ']');
				getline(buffer, fifth, '[');
				getline(buffer, sixth, ']');
				getline(buffer, seventh);

				if(inFile.good() && !isTLS(second) && !isTLS(fourth) && !isTLS(sixth))
					if(isTLS(first) || isTLS(third) || isTLS(fifth) || isTLS(seventh))
						++numIPs;
		}
	}

	cout << numIPs << endl;

	return 0;
}

bool isTLS(const string& str){
	bool success = false;
	int strlen = str.length() - 3;
	char cmp[3];
	
	cmp[2] = '\0';

	for(int i = 0; i < strlen; ++i){
		cmp[1] = str.at(i+2);
		cmp[0] = str.at(i+3);

		if(cmp[1] != cmp[0] && strcmp(str.substr(i,2).c_str(), cmp) == 0)
			success = true;
	}

	return success;
}
