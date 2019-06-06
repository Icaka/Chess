#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;
	/*
	Board myBoard;
	Pawn test2('w', "np");
	myBoard.addFigure(&test2, 2, 3);
	cout << "yo" << endl;
	//myBoard.visualise();
	myBoard.viewSquareNumbers();
	cout << endl;
	//myBoard.viewSquarePositions();
	cout << endl;
	Rook rook('w');
	Bishop bishop('w');
	Queen queen('w');
	King king('b');
	Pawn lil('w');
	Rook rook1('w');
	Bishop bish1('w');
	Queen queen1('w');
	myBoard.addFigure(&king, 0, 4);
	myBoard.addFigure(&queen, 7, 3);
	myBoard.addFigure(&bishop, 0, 2);
	//myBoard.addFigure(&queen1, 1, 1);
	myBoard.addFigure(&rook, 7, 4);
	myBoard.addFigure(&lil, 7, 5);
	//myBoard.addFigure(&rook1, 1, 2);
	//myBoard.addFigure(&bish1, 1, 0);
	
	myBoard.moveFigure("e8", "f7");
	myBoard.moveFigure("d8", "e7");
	myBoard.moveFigure("c8", "b7");
	myBoard.moveFigure("b7", "c6");
	myBoard.moveFigure("f8", "f4");
	myBoard.moveFigure("a2", "a3");
	myBoard.moveFigure("a3", "a4");
	myBoard.moveFigure("b4", "b5");
	myBoard.moveFigure("g1", "f3");
	
	//myBoard.moveFigure("h8", "g8");
	//myBoard.moveFigure("e1", "f2");
	////myBoard.moveFigure("e1", "f1");
	//myBoard.moveFigure("g1", "e2");
	//myBoard.moveFigure("e1", "e2");
	//myBoard.moveFigure("d1", "c1");
	//myBoard.moveFigure("c1", "a3");
	myBoard.moveFigure("a8", "a5");
	//myBoard.moveFigure("e8", "f8");
	myBoard.moveFigure("f1", "g2");
	myBoard.moveFigure("f8", "f7");
	myBoard.moveFigure("e8", "e7");
	myBoard.testPrinting();
	myBoard.PrettyPrinting();
	*/

	int numberOfTurns = 0;

	char firstName[128];
	char secondName[128];
	cout << "Input Player1: ";
	cin >> firstName;
	cout << "Input Player2: ";
	cin >> secondName;

	Game myGame(firstName, secondName);
	//myGame.inputPlayers(firstName, secondName);
	myGame.startingFigureLayout();
	myGame.Print();
	myGame.outputPlayers();
	char po1[3];
	char po2[3];
	while (true)
	{
		if (numberOfTurns % 2 == 0)
		{
			cout << myGame.getPlayer1() << " input positions: ";
		}
		else {
			cout << myGame.getPlayer2() << " input positions: ";
		}
		cin >> po1;
		if (!strcmp(po1, "ex")) // using this to exit the loop
			break;
		cin >> po2;

		if (numberOfTurns % 2 == 0)
		{
			if (!myGame.isFigureWhite(po1))
			{
				cout << "wrong figures" << endl;
				continue;
			}
		}
		else {
			if (myGame.isFigureWhite(po1))
			{
				cout << "wrong figures" << endl;
				continue;
			}
		}
		//cout << "pos1: " << po1 << endl;
		//cout << "pos2: " << po2[0] << endl;
		if (!myGame.move(po1, po2))
			continue;
		myGame.Print();
		numberOfTurns++;
		if (myGame.isTheGameOver())
		{
			cout << "We have a winner" << endl;
			break;
		}
	}
	cout << "Bye" << endl;
	return 0;
}
