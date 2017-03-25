#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

string decompress(string& in);

int main(){
	ifstream inFile;
	string comp;

	inFile.open("input.txt");
	if(inFile.good())
		getline(inFile, comp);
	inFile.close();

	cout << decompress(comp).length() << endl;
	return 0;
}

string decompress(string& in){
	char current;
	char* buffer;
	string decomp;
	stringstream ss;
	ss.str(in);
	int length, repeat;
	int numPar = 0;

	while(ss.good()){
		current = ss.get();

		switch(current){
			case '(':
				++numPar;
				ss >> length;
				ss.ignore();
				ss >> repeat;
				ss.ignore();
				buffer = new char[length+1];

				ss.getline(buffer, length+1);
				ss.clear();

				for(int i = 0; i < repeat; ++i)
					decomp.append(buffer);
				delete buffer;

				break;
			default:
				if(ss.good())
					decomp.append(1,current);
		}
	}
	if(numPar)
		return decompress(decomp);
	else
		return decomp; 
}
