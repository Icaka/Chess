#pragma once

class Figure
{
private:

public:
	virtual bool checkIfValidMove(const char*) = 0;
	virtual const char* getType() = 0;
};
