#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;
	//cout << "\u25A0" << endl;
	Board myBoard;
	myBoard.makeBlackSquare();
	myBoard.makeWhiteSquare();
	myBoard.makeBlackSquare();
	myBoard.visualise();
	return 0;
}
