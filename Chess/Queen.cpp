#include "Queen.h"
#include <iostream>
Queen::Queen(const char newOwner)
{
	owner = newOwner;

	position = new char[1];
	position = '\0';
}

bool Queen::checkIfValidMove(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
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

	if ((num2 / 10) == (num1 / 10))
		if (!checkForCollisions(i1, j1, i2, j2, figures))
		{
			return true;
		}
		else {
			std::cout << "this figure can't jump over others" << std::endl;
			return false;
		}

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

bool Queen::checkForCollisions(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
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

void Queen::setEventuallyAttackingKing(bool)
{
}

const char* Queen::getType()
{
	return type;
}

const char Queen::getOwner()
{
	return owner;
}

char* Queen::getPosition() const
{
	return position;
}

void Queen::setPosition(const char* newPos)
{
	position = new char[strlen(newPos) + 1];
	strcpy_s(position, strlen(newPos) + 1, newPos);
}

void Queen::setOwner(const char newOwner)
{
	owner = newOwner;
}

char Queen::getLetter() const
{
	if (owner == 'b')
	{
		return '1';
	}
	else {
		return 'Q';
	}
}