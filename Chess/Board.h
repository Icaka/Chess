#pragma once
#include "Square.h"

const char pos1[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
const char pos2[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };

class Board
{
private:
	static const int rows = 8;
	static const int cols = 8;
	Square squares[rows][cols];

public:
	Board();

	void visualise();
	void makeBlackSquare();
	void makeWhiteSquare();
	void moveFigure(const char*, const char*);//
	void viewSquareNumbers();
	void viewSquarePositions();
	void PrettyPrinting();
};
