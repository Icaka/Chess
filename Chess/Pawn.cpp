#include "Pawn.h"

Pawn::Pawn(const char c)
{
	owner = c;
}

bool Pawn::checkIfValidMove(const short num1, const short num2)
{
	if (owner == 'b')
	{
		if ((num2 - movementNumber) == num1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if ((num2 + movementNumber) == num1)
		{
			return true;
		}
		else {
			return false;
		}
	}
}

const char* Pawn::getType()
{
	return type;
}

const char Pawn::getOwner()
{
	return owner;
}

char Pawn::getLetter() const
{
	if (owner == 'b')
	{
		return 'p';
	}
	else {
		return 'P';
	}
}
