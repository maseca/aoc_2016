#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int COLUMNS = 50; 
const int ROWS = 6; 

void rect(const string& buf, char scr[ROWS][COLUMNS]);
void rotate(const string& buf, char scr[ROWS][COLUMNS]);
void display(const char scr[ROWS][COLUMNS]);

int main(){
	ifstream inFile;
	string buffer;
	char screen[ROWS][COLUMNS];
	int count = 0;

	for(int i = 0; i < ROWS; ++i)
		for(int j = 0; j < COLUMNS; ++j)
			screen[i][j] = '.';

	inFile.open("input.txt");
	
	while(inFile.good()){
		getline(inFile, buffer);

		if(buffer.length() > 1)
			switch(buffer.at(1)){
				case 'e':
					rect(buffer, screen);
					break;
				case 'o':
					rotate(buffer, screen);
			}
	}

	for(int i = 0; i < ROWS; ++i)
		for(int j = 0; j < COLUMNS; ++j)
			if(screen[i][j] == '#')
				++count;

	display(screen);
	cout << count << endl;

	return 0;
}

void rect(const string& buf, char scr[ROWS][COLUMNS]){
	stringstream ss(buf.substr(5));
	int col, row;

	ss >> col;
	ss.ignore();
	ss >> row;
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			scr[i][j] = '#';
}

void rotate(const string& buf, char scr[ROWS][COLUMNS]){
	stringstream ss;
	char* shift;
	char* swap;
	int which, by;
	
	if(buf.at(7) == 'r'){
		ss.str(buf.substr(13));
		ss >> which;
		ss.ignore(3);
		ss >> by;
		
		shift = new char [COLUMNS - by];
		swap = new char [by];

		for(int j = 0; j < COLUMNS - by; ++j)
			shift[j] = scr[which][j];
		for(int j = COLUMNS - by; j < COLUMNS; ++j)
			swap[j - COLUMNS + by] = scr[which][j];

		for(int j = 0; j < by; ++j)
			scr[which][j] = swap[j];
		for(int j = by; j < COLUMNS; ++j)
			scr[which][j] = shift[j - by];
	}else{
		ss.str(buf.substr(16));
		ss >> which;
		ss.ignore(3);
		ss >> by;

		shift = new char [ROWS - by];
		swap = new char [by];

		for(int i = 0; i < ROWS - by; ++i)
			shift[i] = scr[i][which];
		for(int i = ROWS - by; i < ROWS; ++i)
			swap[i - ROWS + by] = scr[i][which];

		for(int i = 0; i < by; ++i)
			scr[i][which] = swap[i];
		for(int i = by; i < ROWS; ++i)
			scr[i][which] = shift[i - by];
	}
}

void display(const char scr[ROWS][COLUMNS]){
	for(int i = 0; i < ROWS; ++i){
		cout << endl;
		for(int j = 0; j < COLUMNS; ++j)
			cout << scr[i][j];
	}

	cout << endl;
}
