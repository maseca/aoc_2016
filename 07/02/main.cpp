#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool isSSL(const string& str1, const string& str2);

int main(){
	ifstream inFile;
	stringstream buffer;
	string input, first, second, third, fourth, fifth, sixth, seventh;
	size_t found;
	int numIPs = 0;
	int numBrackets = 0;

	inFile.open("input.txt");
	
	while(inFile.good()){
		first = second = third = fourth = fifth = sixth = seventh = "";
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
				break;
			case 2:
				getline(buffer, first, '[');
				getline(buffer, second, ']');
				getline(buffer, third, '[');
				getline(buffer, fourth, ']');
				getline(buffer, fifth);
				break;
			case 3:
				getline(buffer, first, '[');
				getline(buffer, second, ']');
				getline(buffer, third, '[');
				getline(buffer, fourth, ']');
				getline(buffer, fifth, '[');
				getline(buffer, sixth, ']');
				getline(buffer, seventh);
		}

		first += "-" + third + "-" + fifth + "-" + seventh;
		second += "-" + fourth + "-" + sixth;

		if(inFile.good() && isSSL(first, second))
			++numIPs;
	}

	cout << numIPs << endl;

	return 0;
}

bool isSSL(const string& str1, const string& str2){
	bool success = false;
	int str1len = str1.length() - 2;
	int str2len = str2.length() - 2;
	char substr1[4], substr2[4];
	substr1[3] = substr2[3] = '\0';
	
	for(int i = 0; i < str1len; ++i){
		substr1[0] = str1.at(i);
		substr1[1] = str1.at(i+1);
		substr1[2] = str1.at(i+2);

		if(substr1[0] == substr1[2] && substr1[0] != substr1[1]){
			substr2[0] = substr2[2] = substr1[1];
			substr2[1] = substr1[0];

			for(int i = 0; i < str2len; ++i)
				if(strcmp(str2.substr(i,3).c_str(), substr2) == 0)
					success = true;
		}
	}

	return success;
}
