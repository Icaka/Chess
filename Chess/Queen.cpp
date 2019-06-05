#include "Queen.h"
#include <iostream>
Queen::Queen(const char newOwner)
{
	owner = newOwner;

	position = new char[1];
	position = '\0';
}

bool Queen::checkIfValidMove(const short num1, const short num2)
{
	for (int i = 1; i < 8; i++)
	{
		if ((num2 + i * movementNumber) == num1)
			return true;

		if ((num2 - i * movementNumber) == num1)
			return true;
	}

	if ((num2 / 10) == (num1 / 10))
		return true;

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