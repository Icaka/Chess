#include "Square.h"
#include <iostream>

Square::Square(const char* pos, short num)
{
	position = new char[3];
	strcpy_s(position, 3, pos);
	
	number = num;
}

char* Square::getPosition() const
{
	return position;
}

short Square::getNumber() const
{
	return number;
}
