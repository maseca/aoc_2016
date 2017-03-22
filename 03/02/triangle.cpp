#include <fstream>
#include <iostream>
using namespace std;

bool isTriangle(short a, short b, short c);

int main(){
	ifstream inFile;
	short A1, B1, C1;
	short A2, B2, C2;
	short A3, B3, C3;
	short numTriangles = 0;
	
	inFile.open("input.txt");
	while(inFile.good()){
		inFile >> A1 >> B1 >> C1 >> A2 >> B2 >> C2
			   >> A3 >> B3 >> C3;
		if(inFile.good() && isTriangle(A1, A2, A3))
			numTriangles++;
		if(inFile.good() && isTriangle(B1, B2, B3))
			numTriangles++;
		if(inFile.good() && isTriangle(C1, C2, C3))
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

