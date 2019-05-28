#include "Board.h"
#include <iostream>

Board::Board()
{
	int squareNumber = 1;
	char givenColor;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//squareNumber = i + 1;
			if ((squareNumber % 10 != 0) && (squareNumber % 10 != 1) && (squareNumber > 20) && (squareNumber < 100))
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0)
					{
						givenColor = 'b';
					}
					else {
						givenColor = 'w';
					}
				}
				else {
					if (j % 2 == 0)
					{
						givenColor = 'w';
					}
					else {
						givenColor = 'b';
					}
				}
				Square temp("no", squareNumber, true, givenColor);
				squares[i][j] = temp;
			}
			squareNumber++;
		}
	}
}

void Board::visualise()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (squares[i][j].ifVisible())
			{
				if (squares[i][j].getColor() == 'b')
				{
					std::cout << " 1 ";
				}
				if (squares[i][j].getColor() == 'w')
				{
					std::cout << " 0 ";
				}
			}
		}
		std::cout << std::endl;
	}
}

void Board::makeBlackSquare()
{
	for (int i = 0; i < 5; i++)
		std::cout << "* * * * *" << std::endl;
}

void Board::makeWhiteSquare()
{
	std::cout << "* * * * *" << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << "*       *" << std::endl;
	std::cout << "* * * * *" << std::endl;
}