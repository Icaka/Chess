#include "Bishop.h"
#include <iostream>
Bishop::Bishop(const char c)
{
	owner = c;
	position = new char[1];
	position = '\0';
}

bool Bishop::checkIfValidMove(const short num1, const short num2)
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((num1 + i * movementNumbers[j]) == num2)
				return true;
		}
	}
	return false;
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