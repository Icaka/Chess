#pragma once
#include "Figure.h"

class Pawn : public Figure
{
private:
	const char* type = "pawn";
	short direction;
public:
	bool checkIfValidMove(const char*) override;
	const char* getType() override;
};
