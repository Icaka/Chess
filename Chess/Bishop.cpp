#include "Bishop.h"
#include <iostream>

Bishop::Bishop()
{
	owner = 'n';
	position = new char[1];
	position = '\0';
}

Bishop::Bishop(const char c)
{
	owner = c;
	position = new char[1];
	position = '\0';
}

bool Bishop::checkIfValidMove(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
{
	int num1 = 22 + i1 * 10 + j1;
	int num2 = 22 + i2 * 10 + j2;
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((num1 + i * movementNumbers[j]) == num2)
				if (!checkForCollisions(i1, j1, i2, j2, figures))
				{
					return true;
				}
				else {
					std::cout << "this figure can't jump over others" << std::endl;
					return false;
				}
		}
	}
	return false;
}

bool Bishop::checkForCollisions(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
{
	if (i2 > (i1 + 1))
	{
		int i = 1;
		if (j2 > j1)
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
	return false;
}

void Bishop::setEventuallyAttackingKing(bool)
{
}

const char* Bishop::getType()
{
	return type;
}

const char Bishop::getOwner()
{
	return owner;
}

char* Bishop::getPosition() const
{
	return position;
}

void Bishop::setPosition(const char* newPos)
{
	position = new char[strlen(newPos) + 1];
	strcpy_s(position, strlen(newPos) + 1, newPos);
}

void Bishop::setOwner(const char newOwner)
{
	owner = newOwner;
}

char Bishop::getLetter() const
{
	if (owner == 'b')
	{
		return 'b';
	}
	else {
		return 'B';
	}
}