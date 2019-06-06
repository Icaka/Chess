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
	int num1 = 22 + (7 - i1) * 10 + j1;
	int num2 = 22 + (7 - i2) * 10 + j2;
	for (int i = 0; i < 8; i++)
	{
		if ((num1 + movementNumbers[i]) == num2)
			return true;
	}
	return false;
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