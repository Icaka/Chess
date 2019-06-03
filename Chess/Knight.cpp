#include "Knight.h"
#include <iostream>

Knight::Knight()
{
	owner = 'n';
	position = new char[3];
	strcpy_s(position, strlen("no") + 1, "no");
}

Knight::Knight(const char c, const char* pos)
{
	owner = c;
	position = new char[3];
	strcpy_s(position, strlen(pos) + 1, pos);
}

bool Knight::checkIfValidMove(const short num1, const short num2)
{
	for (int i = 0; i < 8; i++)
	{
		if ((num1 + movementNumbers[i]) == num2)
		{
			return true;
		}
	}
	return false;
}

const char* Knight::getType()
{
	return type;
}

const char Knight::getOwner()
{
	return owner;
}

char* Knight::getPosition() const
{
	return position;
}

void Knight::setPosition(const char* newPos)
{
	position = new char[strlen(newPos) + 1];
	strcpy_s(position, strlen(newPos) + 1, newPos);
}

void Knight::setOwner(const char newOwner)
{
	owner = newOwner;
}

char Knight::getLetter() const
{
	if (owner == 'b')
	{
		return 'n';
	}
	else {
		return 'N';
	}
}