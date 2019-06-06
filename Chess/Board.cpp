#include "Board.h"
#include <iostream>


Board::Board()
{
	figures = new FiguresPtr*[rows];
	for (int i = 0; i < rows; i++)
		figures[i] = new FiguresPtr[cols];

	for (int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			figures[i][j] = nullptr;

	//--------------------------------------------------------------------------
	/*
	Knight *whiteKnights = new Knight[2];
	whiteKnights[0].setOwner('b');
	whiteKnights[1].setOwner('b');

	Pawn *whitePawns = new Pawn[8];

	short whitePawnRow = 6;
	for (int i = 0; i < 8; i++)
	{
		whitePawns[i].setOwner('b');
		//whitePawns[i].setPosition(squares[whitePawnRow][i].getPosition());
		figures[whitePawnRow][i] = &whitePawns[i];
	}
	testPrinting();
	PrettyPrinting();
	figures[7][1] = &whiteKnights[0];
	figures[7][6] = &whiteKnights[1];
	figures[0][7] = new Pawn;
	figures[0][7]->setOwner('b');
	*/
}

Board::~Board()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] figures[i];
	}
	delete[] figures;
}

void Board::visualise()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (squareColor(i, j))
			{
				std::cout << "  1  ";
			}
			else {
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

void Board::moveFigure(const char* p1, const char* p2)
{

	int letterIndex1, numberIndex1, letterIndex2, numberIndex2;
	int movementNumber1, movementNumber2;

	for (int i = 0; i < 8; i++) //letters
	{
		if (p1[0] == pos1[i])
			letterIndex1 = i;
		if (p2[0] == pos1[i])
			letterIndex2 = i;
	}
	for (int i = 0; i < 8; i++) //numbers
	{
		if (p1[1] == pos2[i])
			numberIndex1 = i;
		if (p2[1] == pos2[i])
			numberIndex2 = i;
	}

	if (figures[7 - numberIndex1][letterIndex1] == nullptr)
	{
		std::cout << "position " << pos1[letterIndex1] << pos2[numberIndex1] << " is empty" << std::endl;
	}
	else {
	
		if (figures[7 - numberIndex1][letterIndex1]->checkIfValidMove(7 - numberIndex1, letterIndex1, 7 - numberIndex2, letterIndex2, figures))
		{
			if (figures[7 - numberIndex2][letterIndex2] == nullptr)
			{
				std::cout << "from " << pos1[letterIndex1] << pos2[numberIndex1] << ", " << figures[7 - numberIndex1][letterIndex1]->getType() << " goes to " << pos1[letterIndex2] << pos2[numberIndex2] << std::endl;
				figures[7 - numberIndex2][letterIndex2] = figures[7 - numberIndex1][letterIndex1];
				figures[7 - numberIndex1][letterIndex1] = nullptr;
			}
			else {
				if (figures[7 - numberIndex2][letterIndex2]->getOwner() != figures[7 - numberIndex1][letterIndex1]->getOwner())
				{
					std::cout << "from " << pos1[letterIndex1] << pos2[numberIndex1] << ", " << figures[7 - numberIndex1][letterIndex1]->getType() << " goes to " << pos1[letterIndex2] << pos2[numberIndex2] << std::endl;
					figures[7 - numberIndex2][letterIndex2] = figures[7 - numberIndex1][letterIndex1];
					figures[7 - numberIndex1][letterIndex1] = nullptr;
				}
				else {
					std::cout << "friendly fire is off" << std::endl;
				}
			}
		}
		else {
			std::cout << "invalid move" << std::endl;
		}
	}
}



void Board::viewSquareNumbers()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << " " << 22 + (i * 10) + j << " ";
		}
		std::cout << std::endl;
	}
}

void Board::testPrinting()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (figures[i][j] != nullptr)
			{
				std::cout << figures[i][j]->getLetter() << "  ";
			}
			else {
				std::cout << "0  ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::PrettyPrinting()
{
	std::cout << "whoa" << std::endl;
	for (int i = 0; i < rows; i++)
	{
		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squareColor(i, j))
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
			if (squareColor(i, j))
			{
				std::cout << "* *   * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;

		std::cout << "  " << rows - i << "  ";
		for (int j = 0; j < cols; j++) // this "for" will be checking for the occupacy
		{
			if (figures[i][j] == nullptr)
			{
				if (squareColor(i, j))
				{
					std::cout << "*       *";
				}
				else {
					std::cout << "         ";
				}
			}
			else {
				if (squareColor(i, j))
				{
					std::cout << "*   " << figures[i][j]->getLetter() << "   *";
				}
				else {
					std::cout << "    " << figures[i][j]->getLetter() << "    ";
				}
			}
		}
		std::cout << std::endl;
		
		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squareColor(i, j))
			{
				std::cout << "* *   * *";
			}
			else {
				std::cout << "         ";
			}
		}
		std::cout << std::endl;

		std::cout << "     ";
		for (int j = 0; j < cols; j++)
		{
			if (squareColor(i, j))
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

void Board::outputFigures()
{
	std::cout << "Figures:" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figures[i][j] != nullptr)
			{
				std::cout << figures[i][j]->getType() << ": " << figures[i][j]->getPosition() << std::endl;
			}
		}
	}
}

void Board::addFigure(FiguresPtr fPtr, int pos1, int pos2)
{
	if (figures[pos1][pos2] == nullptr)
	{
		figures[pos1][pos2] = fPtr;
	}
	else {
		std::cout << "Position [" << pos1 << "][" << pos2 << "] is taken" << std::endl;
	}
}

bool Board::squareColor(int i, int j)
{
	if (i % 2 == 0)
	{
		if (j % 2 == 0)
		{
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (j % 2 == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}
}