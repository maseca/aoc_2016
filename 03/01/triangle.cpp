#include <fstream>
#include <iostream>
using namespace std;

bool isTriangle(short a, short b, short c);

int main(){
	ifstream inFile;
	short A, B, C;
	short numTriangles = 0;
	
	inFile.open("input.txt");
	while(inFile.good()){
		inFile >> A >> B >> C;
		if(isTriangle(A, B, C))
			numTriangles++;
	}

	cout << numTriangles << endl;

	return 0;
}

bool isTriangle(short a, short b, short c){
	if(a + b > c && b + c > a && a + c > b)
		return true;
	else
		return false;
}

