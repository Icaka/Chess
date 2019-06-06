#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;
	int numberOfTurns = 0;

	char firstName[128];
	char secondName[128];
	cout << "Input Player1: ";
	cin >> firstName;
	cout << "Input Player2: ";
	cin >> secondName;

	Game myGame(firstName, secondName);
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
