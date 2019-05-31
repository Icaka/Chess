#pragma once
#include "Square.h"
#include "Pawn.h"

const char pos1[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
const char pos2[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };
const int maxFigures = 32;

typedef Figure* FiguresPtr;

class Board
{
private:
	static const int rows = 8;
	static const int cols = 8;
	Square squares[rows][cols];
	FiguresPtr* figures;

public:
	Board();

	void visualise();
	void makeBlackSquare();
	void makeWhiteSquare();
	void moveFigure(const char*, const char*);//
	void viewSquareNumbers();
	void viewSquarePositions();
	void PrettyPrinting();
	void outputFigures();
};
