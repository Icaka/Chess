#include "Board.h"
#include <iostream>

Board::Board()
{
	int squareNumber = 22;
	char* givenPosition = new char[3];
	givenPosition[2] = '\0';
	char givenColor;
	for (int i = 0; i < rows; i++)
	{
		givenPosition[1] = pos2[rows - (i + 1)];
		for (int j = 0; j < cols; j++)
		{
			givenPosition[0] = pos1[j];
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
			//givenPosition[2] = '\0';
			Square temp(givenPosition, squareNumber, givenColor);
			squares[i][j] = temp;
			squareNumber++;
		}
		squareNumber = squareNumber + 2;
	}
	delete[] givenPosition;
}

void Board::visualise()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
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

void Board::viewSquarePositions()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << " " << squares[i][j].getPosition() << " ";
		}
		std::cout << std::endl;
	}
}

void Board::PrettyPrinting()
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squares[i][j].getColor() == 'b')
			{
				std::cout << "* * * * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;

		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squares[i][j].getColor() == 'b')
			{
				std::cout << "* * * * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;

		std::cout << "  " << rows - i << "  ";
		for (int j = 0; j < cols; j++) // this "for" will be checking for the occupacy
		{
			if (squares[i][j].getColor() == 'b')
			{
				std::cout << "* * * * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;
		
		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squares[i][j].getColor() == 'b')
			{
				std::cout << "* * * * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;

		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squares[i][j].getColor() == 'b')
			{
				std::cout << "* * * * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "         ";
	for (int j = 0; j < cols; j++)
	{
		std::cout << pos1[j] << "        ";
	}
	std::cout << std::endl;
}
