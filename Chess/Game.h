#pragma once
#include "Board.h"
#include <fstream>

class Game
{
private:
	Board theBoard;
	char* player1;
	char* player2;
public:
	Game();
	Game(const char*, const char*);

	void Print();
	void startingFigureLayout();
	bool move(const char*, const char*);
	void inputPlayers(const char*, const char*);
	void outputPlayers() const;

	char* getPlayer1() const;
	char* getPlayer2() const;
	bool isFigureWhite(const char*);

	bool isTheGameOver();
	void writeDownPlayer(const char*, const short);
};