#pragma once

class Figure
{
private:

public:
	virtual bool checkIfValidMove(const short, const short) = 0;
	virtual const char* getType() = 0;
	virtual const char getOwner() = 0;
	virtual char getLetter() const = 0;
	virtual char* getPosition() const = 0;
	virtual void setPosition(const char*) = 0;
	virtual void setOwner(const char) = 0;
};
