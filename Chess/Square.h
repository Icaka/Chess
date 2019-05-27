#pragma once

class Square
{
private:
	char* position;
	short number;
public:
	//Square();
	Square(const char*, short);

	char* getPosition() const;
	short getNumber() const;
};
