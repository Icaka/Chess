#include "Square.h"
#include <iostream>

Square::Square()
{
	position = new char[1];
	position = '\0';

	number = 0;
	visible = false;
	color = 'b';
}

Square::Square(const char* pos, short num, bool vis, char c)
{
	position = new char[3];
	strcpy_s(position, 3, pos);
	
	number = num;
	visible = vis;
	color = c;
}

Square::~Square()
{
	delete[] position;
}

Square& Square::operator=(const Square& newSquare)
{
	if (this != &newSquare)
	{
		clear();
		copy(newSquare);
	}
	return *this;
}

void Square::copy(const Square& newSquare)
{
	position = new char[strlen(newSquare.getPosition()) + 1];
	strcpy_s(position, strlen(newSquare.getPosition()) + 1, newSquare.getPosition());

	number = newSquare.getNumber();
	visible = newSquare.ifVisible();
	color = newSquare.getColor();
}

void Square::clear()
{
	delete[] position;
}

char* Square::getPosition() const
{
	return position;
}

short Square::getNumber() const
{
	return number;
}

bool Square::ifVisible() const
{
	return visible;
}

char Square::getColor() const
{
	return color;
}