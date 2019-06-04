#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;
	Board myBoard;
	Pawn test2('w', "np");
	myBoard.addFigure(&test2, 2, 3);
	cout << "yo" << endl;
	//myBoard.visualise();
	//myBoard.viewSquareNumbers();
	cout << endl;
	//myBoard.viewSquarePositions();
	cout << endl;
	Rook rook('w');
	Bishop bishop('b');
	myBoard.addFigure(&bishop, 0, 2);
	myBoard.addFigure(&rook, 0, 5);
	
	myBoard.moveFigure("c8", "b7");
	myBoard.moveFigure("b7", "c6");
	myBoard.moveFigure("f8", "f4");
	myBoard.moveFigure("a2", "a3");
	myBoard.moveFigure("a3", "a4");
	myBoard.moveFigure("b4", "b5");
	myBoard.moveFigure("g1", "f3");
	myBoard.testPrinting();
	myBoard.PrettyPrinting();
	return 0;
}
