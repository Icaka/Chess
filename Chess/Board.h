#pragma once
#include "Square.h"

class Board
{
private:
	Square squares[12][10];

public:
	Board();

	void visualise();
	void makeBlackSquare();
	void makeWhiteSquare();
	void moveFigure(const char*, const char*);//
};
