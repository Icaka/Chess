#pragma once
#include "Figure.h"

class King : public Figure
{
private:
	const short movementNumbers[8] = { 1, -1, 9, -9, 10, -10, 11, -11 };
	const char* type = "king";
	char owner;
	char* position;
public:
	King();
	King(const char);

	bool checkIfValidMove(const short, const short, const short, const short, Figure***) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
	char* getPosition() const override;
	void setPosition(const char*) override;
	void setOwner(const char) override;
	bool checkIfCanBeKilled(const short, const short, Figure***);
	void setEventuallyAttackingKing(bool);
};