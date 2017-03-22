#include "Numpad.h"

Numpad::Numpad(){
	padX = padY = 1;
}

void Numpad::setNum(char dir){
	switch(dir){
		case 'U':
			if(padY > 0)
				padY--;
			break;
		case 'D':
			if(padY < SIZE - 1)
				padY++;
			break;
		case 'R':
			if(padX < SIZE - 1)
				padX++;
			break;
		case 'L':
			if(padX > 0)
				padX--;
			break;
	}
}

char Numpad::getNum(){
	return PAD[padY][padX];
}
