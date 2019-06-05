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
	Knight *whiteKnights = new Knight[2];
	whiteKnights[0].setOwner('b');
	whiteKnights[1].setOwner('w');

	Pawn *whitePawns = new Pawn[8];

	short whitePawnRow = 6;
	for (int i = 0; i < 8; i++)
	{
		whitePawns[i].setOwner('w');
		//whitePawns[i].setPosition(squares[whitePawnRow][i].getPosition());
		figures[whitePawnRow][i] = &whitePawns[i];
	}
	testPrinting();
	PrettyPrinting();
	figures[7][1] = &whiteKnights[0];
	figures[7][6] = &whiteKnights[1];
	figures[0][7] = new Pawn;
	figures[0][7]->setOwner('b');
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
		movementNumber1 = 22 + (7 - numberIndex1) * 10 + letterIndex1;
		movementNumber2 = 22 + (7 - numberIndex2) * 10 + letterIndex2;
		
		if (figures[7 - numberIndex1][letterIndex1]->checkIfValidMove(movementNumber1, movementNumber2))
		{
			if (checkForCollisions(7 - numberIndex1, letterIndex1, 7 - numberIndex2, letterIndex2)) // returns true if it encounters collisions
			{
				std::cout << "this figure can't jump over others" << std::endl;
			}
			else {
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
		}
		else {
			std::cout << "invalid move" << std::endl;
		}
	}
}

bool Board::checkForCollisions(const short i1, const short j1, const short i2, const short j2)
{
	if (!strcmp(figures[i1][j1]->getType(), "pawn") || !strcmp(figures[i1][j1]->getType(), "knight") || !strcmp(figures[i1][j1]->getType(), "king"))
	{
		return false;
	}

	if (!strcmp(figures[i1][j1]->getType(), "rook") || !strcmp(figures[i1][j1]->getType(), "queen")) // checking the rook and queen collisions
	{
		if (i2 > (i1 + 1))
		{
			for (int i = i2 - 1; i > i1; i--)
				if (figures[i][j1] != nullptr)
					return true;
		}
		if (i2 < (i1 - 1))
		{
			for (int i = i2 + 1; i < i1; i++)
				if (figures[i][j1] != nullptr)
					return true;
		}
		if (j2 > (j1 + 1))
		{
			for (int j = j2 - 1; j > j1; j--)
				if (figures[i1][j] != nullptr)
					return true;
		}
		if (j2 < (j1 - 1))
		{
			for (int j = j2 + 1; j < j1; j++)
				if (figures[i1][j] != nullptr)
					return true;
		}
	}

	if (!strcmp(figures[i1][j1]->getType(), "bishop") || !strcmp(figures[i1][j1]->getType(), "queen")) // checking the bishop and queen collisions
	{
		if (i2 > (i1 + 1))
		{
			int i = 1;
			if(j2 > j1)
			{
				while (i1 < (i2 - i))
				{
					if (figures[i2 - i][j2 - i] != nullptr)
						return true;
					i++;
				}
			}
			else {
				while (i1 < (i2 - i))
				{
					if (figures[i2 - i][j2 + i] != nullptr)
						return true;
					i++;
				}
			}
		}
		if (i2 < (i1 - 1))
		{
			int i = 1;
			if (j2 > j1)
			{
				while (i1 > (i2 + i))
				{
					if (figures[i2 + i][j2 - i] != nullptr)
						return true;
					i++;
				}
			}
			else {
				while (i1 > (i2 + i))
				{
					if (figures[i2 + i][j2 + i])
						return true;
					i++;
				}
			}
		}
	}

	return false;
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