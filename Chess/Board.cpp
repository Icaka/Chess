#include "Board.h"
#include <iostream>


Board::Board()
{
	figures = new FiguresPtr*[8];
	for (int i = 0; i < 8; i++)
		figures[i] = new FiguresPtr[8];

	for (int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			figures[i][j] = nullptr;


	int squareNumber = 22;
	char* givenPosition = new char[3];
	givenPosition[2] = '\0';
	for (int i = 0; i < rows; i++)
	{
		givenPosition[1] = pos2[rows - (i + 1)];
		for (int j = 0; j < cols; j++)
		{
			givenPosition[0] = pos1[j];
			//givenPosition[2] = '\0';
			Square temp(givenPosition, squareNumber);
			squares[i][j] = temp;
			squareNumber++;
		}
		squareNumber = squareNumber + 2;
	}
	delete[] givenPosition;

	//--------------------------------------------------------------------------

	Pawn *whitePawns = new Pawn[8];
	short whitePawnRow = 6;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "created" << std::endl;
		whitePawns[i].setOwner('w');
		whitePawns[i].setPosition(squares[whitePawnRow][i].getPosition());
		figures[whitePawnRow][i] = &whitePawns[i];
	}
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

	//std::cout << letterIndex1 << ", " << numberIndex1 << std::endl;
	//std::cout << 7 - numberIndex1 << ", " << letterIndex1 << std::endl;
	//std::cout << 7 - numberIndex2 << ", " << letterIndex2 << std::endl;
	//std::cout << figures[7 - numberIndex1][letterIndex1]->getType() << std::endl;
	if (figures[7 - numberIndex1][letterIndex1] == nullptr)
	{
		std::cout << "position " << pos1[letterIndex1] << pos2[numberIndex1] << " is empty" << std::endl;
	}
	else {
		movementNumber1 = 22 + (7 - numberIndex1) * 10 + letterIndex1;
		movementNumber2 = 22 + (7 - numberIndex2) * 10 + letterIndex2;
		//std::cout << movementNumber1 << ", " << movementNumber2 << std::endl;
		if (figures[7 - numberIndex1][letterIndex1]->checkIfValidMove(movementNumber1, movementNumber2))
		{
			std::cout << "from " << pos1[letterIndex1] << pos2[numberIndex1] << ", " << figures[7 - numberIndex1][letterIndex1]->getType() << " goes to " << pos1[letterIndex2] << pos2[numberIndex2] << std::endl;
			figures[7 - numberIndex2][letterIndex2] = figures[7 - numberIndex1][letterIndex1];
			//std::cout << figures[7 - numberIndex2][letterIndex2]->getType() << std::endl;
			figures[7 - numberIndex1][letterIndex1] = nullptr;
		}
		else {
			std::cout << "invalid move" << std::endl;
		}
		//figures[7 - numberIndex2][letterIndex2] = figures[7 - numberIndex1][letterIndex1];
		//std::cout << figures[7 - numberIndex2][letterIndex2]->getType() << std::endl;
		//figures[7 - numberIndex1][letterIndex1] = nullptr;
	}
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