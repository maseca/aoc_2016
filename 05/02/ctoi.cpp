#include <stdio.h>

int ctoi(char c) {
    return c-'0';
}

int main(){
	char test[] = {'0','1','2','3','4','5','6','7','8','9'};

	for(int i = 0; i < 10; ++i)
		printf("%i\n", ctoi(test[i]));
		
	return 0;
}
