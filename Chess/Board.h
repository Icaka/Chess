#pragma once
#include "Square.h"

class Board
{
private:
	Square squares[8][8];

public:
	Board();

	void visualise();
	void makeBlackSquare();
	void makeWhiteSquare();
	void moveFigure(const char*, const char*);//
	void viewSquareNumbers();
};
