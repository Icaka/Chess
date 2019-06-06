#pragma once
#include "Figure.h"

class Queen : public Figure
{
private:
	const short movementNumber = 10;
	const short movementNumbers[4] = { 9, -9, 11, -11 };
	const char* type = "queen";
	char owner;
	char* position;
public:
	Queen();
	Queen(const char);

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