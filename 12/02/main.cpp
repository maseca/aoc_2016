#include <stdio.h>
#include <ctype.h>

using namespace std;

const unsigned char NUM_INST = 23;
const unsigned char NUM_CHARS = 10;

int ctoi(char c){
	return c - '0';
} 

int main(){
	FILE* inFile;
	char inst[NUM_INST][NUM_CHARS];
	int a, b, c, d, tgt, dst;
	unsigned char line, pos;
	bool isNeg;
	//char test;

	a = b = d = 0;
	c = 1;

	inFile = fopen("input.txt", "r");
	if(inFile == NULL) perror("File Read Error");
	else{
		for(unsigned char i = 0; i < NUM_INST; ++i){
			fgets(inst[i], NUM_CHARS, inFile);
			//puts(inst[i]);
		}
		
		for(line = 0; line < NUM_INST; ++line){
			//test = getchar();
			//printf("a: %d b: %d c: %d d: %d\n",a,b,c,d);
			switch(inst[line][0]){
				case 'c':
					//puts(inst[line]);
					tgt = 0;
					if(isalpha(inst[line][4])){
						switch(inst[line][4]){
							case 'a':
								switch(inst[line][6]){
									case 'b': b = a; break;
									case 'c': c = a; break;
									case 'd': d = a; 
								}
								break;
							case 'b':
								switch(inst[line][6]){
									case 'a': a = b; break;
									case 'c': c = b; break;
									case 'd': d = b;
								}
								break;
							case 'c':
								switch(inst[line][6]){
									case 'b': b = c; break;
									case 'a': a = c; break;
									case 'd': d = c;
								}
								break;
							case 'd':
								switch(inst[line][6]){
									case 'b': b = d; break;
									case 'c': c = d; break;
									case 'a': a = d;
								}
						}
					}else{
						for(unsigned char j=4;j<NUM_CHARS;++j){
							if(isdigit(inst[line][j]))
								tgt = tgt * 10 + ctoi(inst[line][j]);
							else if(isalpha(inst[line][j])){
								pos = j;
								break;
							}
						}
						switch(inst[line][pos]){
							case 'a': a = tgt; break;
							case 'b': b = tgt; break;
							case 'c': c = tgt; break;
							case 'd': d = tgt;
						}
					}
					break;
				case 'j':
					//puts(inst[line]);
					tgt = dst = 0;
					isNeg = false;
					if(isalpha(inst[line][4]))
						switch(inst[line][4]){
							case 'a':
								if(a == 0)
									dst = 1;
								else
									for(unsigned char j=6;j<NUM_CHARS;++j){
										if(inst[line][j] == '-')
											isNeg = true;
										else if(isdigit(inst[line][j]))
											dst = dst * 10 + ctoi(inst[line][j]);
									}
								break;
							case 'b':
								if(b == 0)
									dst = 1;
								else
									for(unsigned char j=6;j<NUM_CHARS;++j){
										if(inst[line][j] == '-')
											isNeg = true;
										else if(isdigit(inst[line][j]))
											dst = dst * 10 + ctoi(inst[line][j]);
									}
								break;
							case 'c':
								if(c == 0)
									dst = 1;
								else
									for(unsigned char j=6;j<NUM_CHARS;++j){
										if(inst[line][j] == '-')
											isNeg = true;
										else if(isdigit(inst[line][j]))
											dst = dst * 10 + ctoi(inst[line][j]);
									}
								break;
							case 'd':
								if(d == 0)
									dst = 1;
								else
									for(unsigned char j=6;j<NUM_CHARS;++j){
										if(inst[line][j] == '-')
											isNeg = true;
										else if(isdigit(inst[line][j]))
											dst = dst * 10 + ctoi(inst[line][j]);
									}
						}
					else{
						for(unsigned char j=6;j<NUM_CHARS;++j){
							if(inst[line][j] == '-')
								isNeg = true;
							else if(isdigit(inst[line][j]))
								dst = dst * 10 + ctoi(inst[line][j]);
						}
					}
					if(isNeg) dst *= -1;
					line += dst - 1;
					break;
				case 'i':
					//puts(inst[line]);
					switch(inst[line][4]){
						case 'a': ++a; break;
						case 'b': ++b; break;
						case 'c': ++c; break;
						case 'd': ++d;
					}
					break;
				case 'd':
					//puts(inst[line]);
					switch(inst[line][4]){
						case 'a': --a; break;
						case 'b': --b; break;
						case 'c': --c; break;
						case 'd': --d;
					}
			}
		}
		fclose(inFile);
		printf("register a: %d \n", a);
	}

	return 0;
}
