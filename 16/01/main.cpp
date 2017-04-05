#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string checksum(const string& in){
	string checksum = in;
	string temp = "";
	int len = checksum.length();

	while(len % 2 == 0){
		for(int i = 0; i < len-1; i += 2){
			if(checksum.at(i) == checksum.at(i+1))
				temp.append(1, '1');
			else
				temp.append(1, '0');
		}

		checksum = temp;
		temp.clear();
		len = checksum.length();
	}

	return checksum;
}

int main(){
	string input = "10010000000110000";
	string also = "";

	bitset<17> bits17(input);
	bits17 =~ bits17;
	input.append(1, '0');
	also = bits17.to_string();
	reverse(also.begin(), also.end());
	input.append(also);
	also.clear();

	bitset<35> bits35(input);
	bits35 =~ bits35;
	input.append(1, '0');
	also = bits35.to_string();
	reverse(also.begin(), also.end());
	input.append(also);
	also.clear();

	bitset<71> bits71(input);
	bits71 =~ bits71;
	input.append(1, '0');
	also = bits71.to_string();
	reverse(also.begin(), also.end());
	input.append(also);
	also.clear();

	bitset<143> bits143(input);
	bits143 =~ bits143;
	input.append(1, '0');
	also = bits143.to_string();
	reverse(also.begin(), also.end());
	input.append(also);
	also.clear();

	input = input.substr(0,272);

	cout << checksum(input) << endl;
	return 0;
}
