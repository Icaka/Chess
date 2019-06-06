#include "King.h"
#include <iostream>

King::King(const char newOwner)
{
	owner = newOwner;

	position = new char[1];
	position = '\0';
}

bool King::checkIfValidMove(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
{
	int num1 = 22 + i1 * 10 + j1;
	int num2 = 22 + i2 * 10 + j2;
	for (int i = 0; i < 8; i++)
	{
		if ((num1 + movementNumbers[i]) == num2)
		{
			if (!checkIfCanBeKilled(i2, j2, figures))
				return true;
			return false;
		}
	}
	return false;
}

bool King::checkIfCanBeKilled(const short i2, const short j2, Figure*** figures)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(figures[i][j] != nullptr)
				if (figures[i][j]->getOwner() != owner)
				{
					if (!strcmp(figures[i][j]->getType(), "pawn"))
					{
						figures[i][j]->setEventuallyAttackingKing(true);
					}
					if (figures[i][j]->checkIfValidMove(i, j, i2, j2, figures))
					{
						std::cout << "The king will be killed there!" << std::endl;
						return true;
					}
				}
		}
	}
	return false;
}

void King::setEventuallyAttackingKing(bool)
{
}

const char* King::getType()
{
	return type;
}

const char King::getOwner()
{
	return owner;
}

char* King::getPosition() const
{
	return position;
}

void King::setPosition(const char* newPos)
{
	position = new char[strlen(newPos) + 1];
	strcpy_s(position, strlen(newPos) + 1, newPos);
}

void King::setOwner(const char newOwner)
{
	owner = newOwner;
}

char King::getLetter() const
{
	if (owner == 'b')
	{
		return 'k';
	}
	else {
		return 'K';
	}
}