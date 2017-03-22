#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

const string DOOR_ID = "uqwqemis";

int main(){
	string pw = ""; 
	string index, buffer;
	unsigned char count = 0;
	unsigned long i = 0;
	string i2Str;
	unsigned char md[16];
	unsigned char* inMD5;
	unsigned long inLen;
	char mdStr[33];
	char* inStr;
	
	while(count < 8){
		i2Str = to_string(i);
		index = DOOR_ID; index.append(i2Str);
		inLen = index.length();
		inStr = const_cast<char*>(index.c_str());
		inMD5 = new unsigned char[inLen];

		strcpy((char*)inMD5, inStr);

		MD5(inMD5, inLen, md);

		for(int j = 0; j < 16; ++j)
			sprintf(&mdStr[j*2], "%02x", (unsigned int)md[j]);

		//printf("%s\n", mdStr);
		buffer = mdStr;
		//puts(buffer.substr(0,5).c_str());
		if(strcmp(buffer.substr(0,5).c_str(), "00000") == 0){
			++count;
			pw += buffer.at(5);
			printf("%i\n", count);
		}

		i++;
	}

	puts(pw.c_str());

	return 0;
}
