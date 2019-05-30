#include "Rook.h"

Rook::Rook(const char c)
{
	owner = c;
}

bool Rook::checkIfValidMove(const short num1, const short num2)
{
	for (int i = 1; i < 8; i++)
	{
		if ((num2 + i * movementNumber) == num1)
			return true;

		if ((num2 - i * movementNumber) == num1)
			return true;
	}

	if ((num2 / 10) == (num1 / 10)) // now checking if it's on the same row as the rook
		return true;

	return false;
}

const char* Rook::getType()
{
	return type;
}

const char Rook::getOwner()
{
	return owner;
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
