#pragma once
#include "Figure.h"

class Pawn : public Figure
{
private:
	const short movementNumber = 10;
	const char* type = "pawn";
	char owner;
public:
	Pawn(const char);

	bool checkIfValidMove(const short, const short) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
};
