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
	myBoard.PrettyPrinting();
	myBoard.outputFigures();
	return 0;
}
