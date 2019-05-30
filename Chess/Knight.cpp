#include "Knight.h"

Knight::Knight(const char c)
{
	owner = c;
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