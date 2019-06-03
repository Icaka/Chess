#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;
	Board myBoard;
	myBoard.visualise();
	myBoard.viewSquareNumbers();
	cout << endl;
	myBoard.viewSquarePositions();
	cout << endl;
	//myBoard.PrettyPrinting();
	myBoard.outputFigures();
	myBoard.PrettyPrinting();
	myBoard.moveFigure("a2", "a3");
	myBoard.moveFigure("a3", "a4");
	myBoard.moveFigure("b4", "b5");
	myBoard.PrettyPrinting();
	return 0;
}
