#include "Board.h"
#include <iostream>

Board::Board()
{
	int squareNumber = 22;
	char givenColor;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					givenColor = 'w';
				}
				else {
					givenColor = 'b';
				}
			}
			else {
				if (j % 2 == 0)
				{
					givenColor = 'b';
				}
				else {
					givenColor = 'w';
				}
			}
			Square temp("no", squareNumber, true, givenColor);
			squares[i][j] = temp;
			squareNumber++;
		}
		squareNumber = squareNumber + 2;
	}
}

void Board::visualise()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (squares[i][j].ifVisible())
			{
				if (squares[i][j].getColor() == 'b')
				{
					std::cout << "  1  ";
				}
				if (squares[i][j].getColor() == 'w')
				{
					std::cout << "  0  ";
				}
			}
		}
		std::cout << std::endl << std::endl;
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

void Board::viewSquareNumbers()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << " " << squares[i][j].getNumber() << " ";
		}
		std::cout << std::endl;
	}
}
