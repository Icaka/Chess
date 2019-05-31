#include "Bishop.h"

Bishop::Bishop(const char c)
{
	owner = c;
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