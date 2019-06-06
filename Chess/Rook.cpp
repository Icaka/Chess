#include "Rook.h"
#include <iostream>

Rook::Rook()
{
	owner = 'n';
	position = new char[1];
	position = '\0';
}

Rook::Rook(const char c)
{
	owner = c;
	position = new char[1];
	position = '\0';
}

bool Rook::checkIfValidMove(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
{
	int num1 = 22 + i1 * 10 + j1;
	int num2 = 22 + i2 * 10 + j2;
	for (int i = 1; i < 8; i++)
	{
		if ((num2 + i * movementNumber) == num1)
			if (!checkForCollisions(i1, j1, i2, j2, figures))
			{
				return true;
			}
			else {
				std::cout << "this figure can't jump over others" << std::endl;
				return false;
			}

		if ((num2 - i * movementNumber) == num1)
			if (!checkForCollisions(i1, j1, i2, j2, figures))
			{
				return true;
			}
			else {
				std::cout << "this figure can't jump over others" << std::endl;
				return false;
			}
	}

	if ((num2 / 10) == (num1 / 10)) // now checking if it's on the same row as the rook
		if (!checkForCollisions(i1, j1, i2, j2, figures))
		{
			return true;
		}
		else {
			std::cout << "this figure can't jump over others" << std::endl;
			return false;
		}

	return false;
}

bool Rook::checkForCollisions(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
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
	return false;
}

void Rook::setEventuallyAttackingKing(bool)
{
}

const char* Rook::getType()
{
	return type;
}

const char Rook::getOwner()
{
	return owner;
}

char* Rook::getPosition() const
{
	return position;
}

void Rook::setPosition(const char* newPos)
{
	position = new char[strlen(newPos) + 1];
	strcpy_s(position, strlen(newPos) + 1, newPos);
}

void Rook::setOwner(const char newOwner)
{
	owner = newOwner;
}

char Rook::getLetter() const
{
	if (owner == 'b')
	{
		return 'r';
	}
	else {
		return 'R';
	}
}
