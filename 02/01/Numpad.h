#ifndef NUMPAD_H
#define NUMPAD_H
const short SIZE = 3;
const char PAD[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

class Numpad{
	private:
		short padX, padY;
	public:
		Numpad();
		void setNum(char dir);
		char getNum();
};
#endif
