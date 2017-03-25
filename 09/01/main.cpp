#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ifstream inFile;
	stringstream ss;
	string comp, decomp; 
	char current;
	char* buffer;
	int length, repeat;

	inFile.open("input.txt");
	if(inFile.good())
		getline(inFile, comp);
	inFile.close();

	ss.str(comp);

	while(ss.good()){
		current = ss.get();

		switch(current){
			case '(':
				ss >> length;
				ss.ignore();
				ss >> repeat;
				ss.ignore();
				buffer = new char[length];

				ss.getline(buffer, length+1);
				ss.clear();

				for(int i = 0; i < repeat; ++i)
					decomp.append(buffer);

				break;
			default:
				decomp.append(1,current);
		}
	}
	delete buffer;

	cout << decomp.length() - 1 << endl;
	return 0;
}
