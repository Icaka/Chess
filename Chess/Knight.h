#pragma once
#include "Figure.h"

class Knight : public Figure
{
private:
	const short movementNumbers[8] = { 12, -12, 8, -8, 21, -21, 19, -19 };
	const char* type = "knight";
	char owner;
	char* position;

public:
	Knight(const char);

	bool checkIfValidMove(const short, const short) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
	char* getPosition() const override;
};