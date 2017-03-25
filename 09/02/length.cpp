#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

long decompress(string& in);

int main(){
	ifstream inFile;
	string comp;

	inFile.open("input.txt");
	if(inFile.good())
		getline(inFile, comp);
	inFile.close();

	cout << decompress(comp) << endl;
	return 0;
}

long decompress(string& in){
	long sl = 0;
	char current;
	char* buffer;
	string buffStr;
	stringstream ss;
	ss.str(in);
	int length, repeat;

	while(ss.good()){
		current = ss.get();

		switch(current){
			case '(':
				ss >> length;
				ss.ignore();
				ss >> repeat;
				ss.ignore();
				buffer = new char[length+1];
				ss.getline(buffer, length+1);
				ss.clear();
				buffStr = buffer;
				delete buffer;

				sl += (repeat * decompress(buffStr));
				break;
			default:
				if(ss.good())
					++sl;
		}
	}
	return sl; 
}
