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

bool Pawn::checkIfValidMove(const short i1, const short j1, const short i2, const short j2, Figure*** figures)
{
	if (owner == 'b')
	{
		if ((i2 - 1) == i1)
		{
			if(j1 == j2)
				if(figures[i2][j2] == nullptr)
					return true;
			if ((j1 == j2 - 1) || (j1 == j2 + 1))
				if (figures[i2][j2] != nullptr)
					return true;
		}
	}
	else {
		if ((i2 + 1) == i1)
		{
			if (j1 == j2)
				if (figures[i2][j2] == nullptr)
					return true;
			if ((j1 == j2 - 1) || (j1 == j2 + 1))
				if (figures[i2][j2] != nullptr)
					return true;
		}
	}
	return false;
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
