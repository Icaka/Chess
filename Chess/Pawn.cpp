#include "Pawn.h"
#include <iostream>

Pawn::Pawn()
{
	owner = 'n';
	position = new char[1];
	position = '\0';
}

Pawn::Pawn(const char newOwner)
{
	owner = newOwner;

	position = new char[1];
	position = '\0';
}

Pawn::Pawn(const char c, const char* pos)
{
	owner = c;

	position = new char[strlen(pos) + 1];
	strcpy_s(position, strlen(pos) + 1, pos);
}

/*
Pawn& Pawn::operator=(const Pawn& other)
{
	if (this != &other)
	{

	}
}
*/

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
	//std::cout << "yo" << std::endl;
	return type;
}

const char Pawn::getOwner()
{
	return owner;
}

char* Pawn::getPosition() const
{
	return position;
}

void Pawn::setPosition(const char* newPos)
{
	position = new char[strlen(newPos) + 1];
	strcpy_s(position, strlen(newPos) + 1, newPos);
}

void Pawn::setOwner(const char newOwner)
{
	owner = newOwner;
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
