#pragma once
#include "Figure.h"

class Rook : public Figure
{
private:
	const short movementNumber = 10;
	const char* type = "rook";
	char owner;
	char* position;

public:
	Rook(const char);

	bool checkIfValidMove(const short, const short) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
	char* getPosition() const override;
	void setPosition(const char*) override;
	void setOwner(const char) override;
};