#pragma once
#include "Figure.h"

class Bishop : public Figure
{
private:
	const short movementNumbers[4] = { 9, -9, 11, -11 };
	const char* type = "bishop";
	char owner;
	char* position;

public:
	Bishop(const char);

	bool checkIfValidMove(const short, const short, const short, const short, Figure***) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
	char* getPosition() const override;
	void setPosition(const char*) override;
	void setOwner(const char) override;
	bool checkForCollisions(const short, const short, const short, const short, Figure***);
	void setEventuallyAttackingKing(bool);
};