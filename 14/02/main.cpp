#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

//const string DOOR_ID = "jlmsuwbz";
const string DOOR_ID = "abc"; //test data

char* getMD5(char mdStr[33], unsigned long i){
	string index;
	string i2Str;
	unsigned char md[16];
	unsigned char* inMD5;
	unsigned char* recMD5;
	unsigned long inLen;
	char* inStr;
	//int test = 0;
	
	i2Str = to_string(i);
	index = DOOR_ID; index.append(i2Str);
	inLen = index.length();
	inStr = const_cast<char*>(index.c_str());
	inMD5 = new unsigned char[inLen];
	recMD5 = new unsigned char[33];

	strcpy((char*)inMD5, inStr);
	//puts(inStr);

	MD5(inMD5, inLen, md);
	for(int j = 0; j < 16; ++j)
		sprintf(&mdStr[j*2], "%02x", (unsigned int)md[j]);

	//puts(mdStr);
	
	strcpy((char*)recMD5, mdStr);
	for(int z = 0; z < 2016; ++z){
		MD5(recMD5, 32, md);
		for(int j = 0; j < 16; ++j)
			sprintf(&mdStr[j*2], "%02x", (unsigned int)md[j]);

		//scanf("%d",&test);
		//puts(mdStr);
		strcpy((char*)recMD5, mdStr);
	}

	//scanf("%d",&test);
	//puts(mdStr);
	return mdStr;
}

bool find5tuplet(char emDee[33], char check, unsigned long j, unsigned long& q){
	char* myMD;

	//printf("%c\n",check);
	for(unsigned short k = 1; k < 1001; ++k){
		myMD = getMD5(emDee,j+k);

		for(unsigned char i = 0; i < 28; ++i)
			if(check == myMD[i] && check == myMD[i+1] && check == myMD[i+2] && 
			   check == myMD[i+3] && check == myMD[i+4]){
				//puts(myMD);
				//puts("");
				q = j + k;
				//printf("%lu\n%lu\n", j, q);
				return true;
			}
	}
	//puts(myMD);

	return false;
}

void findTriplet(char str[33], unsigned char& cnt, unsigned long x, unsigned long& y){
	for(unsigned char i = 0; i < 30; ++i)
		if(str[i] == str[i+1] && str[i] == str[i+2]){
			//puts(str);
			if(find5tuplet(str, str[i], x, y)){
				++cnt;
				break;
			}
		}
}

int main(){
	unsigned char count = 0;
	unsigned long it = 0;
	unsigned long iq = 0;
	char mds[33];
	
	while(count < 64){
		findTriplet(getMD5(mds, it), count, it, iq);
		++it;
		//printf("%lu\n", iq);
	}
	printf("%lu\n", iq);

	return 0;
}
