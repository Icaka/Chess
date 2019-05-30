#pragma once
#include "Figure.h"

class Bishop : public Figure
{
private:
	const short movementNumbers[4] = { 9, -9, 11, -11 };
	const char* type = "bishop";
	char owner;
public:
	Bishop(const char);

	bool checkIfValidMove(const short, const short) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
};