#include <iostream>
#include <string>
#include <openssl/md5.h>

using namespace std;

const string DOOR_ID = "uqwqemis";

int main(){
	string pw = "";
	int count = 0;
	char* index = const_cast<char*>(DOOR_ID.c_str());;

	//while(count < 8){}
	//
	//test stuff
	unsigned char digest[16];
	char str[] = index; 
	char mdString[33];

	MD5((unsigned char*)&str, strlen(str), (unsigned char*)&digest);
	return 0;
}
