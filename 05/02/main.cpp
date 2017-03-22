#include <openssl/md5.h>
//#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

const string DOOR_ID = "uqwqemis";

/* a char to integer function */
int ctoi(char c) {
    return c-'0';
}

int main(){
	bool already[] = {false, false, false, false, 
					  false, false, false, false};
	char pw[9]; 
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

		buffer = mdStr;

		if(strcmp(buffer.substr(0,5).c_str(), "00000") == 0 && 
		   ctoi(buffer.at(5)) >= 0 && ctoi(buffer.at(5)) < 8 && 
		   !already[ctoi(buffer.at(5))]){

			already[ctoi(buffer.at(5))] = true;
			pw[ctoi(buffer.at(5))] = buffer.at(6);
			++count;
			printf("%i  ", count);
			printf("%c  ", buffer.at(5));
			printf("%c\n", buffer.at(6));
		}

		i++;
	}
	pw[8] = '\0';

	puts(pw);

	return 0;
}
