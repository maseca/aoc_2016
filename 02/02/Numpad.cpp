#include "Numpad.h"

Numpad::Numpad(){
	padX = 1;
	padY = 3;
}

void Numpad::setNum(char dir){
	switch(dir){
		case 'U':
			padY--;
			if(getNum() == '-')
				padY++;
			break;
		case 'D':
			padY++;
			if(getNum() == '-')
				padY--;
			break;
		case 'R':
			padX++;
			if(getNum() == '-')
				padX--;
			break;
		case 'L':
			padX--;
			if(getNum() == '-')
				padX++;
			break;
	}
}

char Numpad::getNum(){
	return PAD[padY][padX];
}
