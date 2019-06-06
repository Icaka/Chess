#pragma once
#include "Figure.h"

class Pawn : public Figure
{
private:
	const short movementNumber = 10;
	const char* type = "pawn";
	char owner;
	char* position;
	bool eventuallyAttackingKing = false;

public:
	Pawn();
	Pawn(const char);
	Pawn(const char, const char*);

	bool checkIfValidMove(const short, const short, const short, const short, Figure***) override;
	const char* getType() override;
	const char getOwner() override;
	char getLetter() const override;
	char* getPosition() const override;
	void setPosition(const char*) override;
	void setOwner(const char) override;
	void setEventuallyAttackingKing(bool);
};
