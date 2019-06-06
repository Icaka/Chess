#pragma once
#include "Square.h"
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

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
	FiguresPtr** figures;

public:
	Board();
	~Board();

	void visualise();
	void makeBlackSquare();
	void makeWhiteSquare();
	void moveFigure(const char*, const char*);
	//bool checkForCollisions(const short, const short, const short, const short);
	void addFigure(FiguresPtr, int, int);
	void viewSquareNumbers();
	void testPrinting();
	void PrettyPrinting();
	void outputFigures();
	bool squareColor(int, int); // will return true if black square and false if white square
};
