#pragma once
#include "Figure.h"

class Rook : public Figure
{
private:
	const short movementNumber = 10;
	const char* type = "rook";
	char owner;
public:
	Rook(const char);

	bool checkIfValidMove(const short, const short) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
};