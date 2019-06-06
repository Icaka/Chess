#include "Game.h"
#include <iostream>

Game::Game(const char* name1, const char* name2)
{
	player1 = new char[strlen(name1) + 1];
	strcpy_s(player1, strlen(name1) + 1, name1);

	player2 = new char[strlen(name2) + 1];
	strcpy_s(player2, strlen(name2) + 1, name2);
}

void Game::startingFigureLayout()
{
	Pawn* whitePawns = new Pawn[8];
	for (int i = 0; i < 8; i++)
	{
		whitePawns[i].setOwner('w');
		theBoard.addFigure(&whitePawns[i], 6, i);
	}

	Pawn* blackPawns = new Pawn[8];
	for (int i = 0; i < 8; i++)
	{
		blackPawns[i].setOwner('b');
		theBoard.addFigure(&blackPawns[i], 1, i);
	}

	King *blackKing = new King('b');
	theBoard.addFigure(blackKing, 0, 4);

	Queen* blackQueen = new Queen('b');
	theBoard.addFigure(blackQueen, 0, 3);

	Rook *bRook1 = new Rook('b');
	Rook* bRook2 = new Rook('b');
	theBoard.addFigure(bRook1, 0, 0);
	theBoard.addFigure(bRook2, 0, 7);

	Knight* bKnight1 = new Knight('b');
	Knight* bKnight2 = new Knight('b');
	theBoard.addFigure(bKnight1, 0, 1);
	theBoard.addFigure(bKnight2, 0, 6);

	Bishop *bBishop1 = new Bishop('b');
	Bishop* bBishop2 = new Bishop('b');
	theBoard.addFigure(bBishop1, 0, 2);
	theBoard.addFigure(bBishop2, 0, 5);

	King* whiteKing = new King('w');
	theBoard.addFigure(whiteKing, 7, 4);

	Queen* whiteQueen = new Queen('w');
	theBoard.addFigure(whiteQueen, 7, 3);

	Rook* wRook1 = new Rook('w');
	Rook* wRook2 = new Rook('w');
	theBoard.addFigure(wRook1, 7, 0);
	theBoard.addFigure(wRook2, 7, 7);

	Knight* wKnight1 = new Knight('w');
	Knight* wKnight2 = new Knight('w');
	theBoard.addFigure(wKnight1, 7, 1);
	theBoard.addFigure(wKnight2, 7, 6);

	Bishop* wBishop1 = new Bishop('w');
	Bishop* wBishop2 = new Bishop('w');
	theBoard.addFigure(wBishop1, 7, 2);
	theBoard.addFigure(wBishop2, 7, 5);
}

void Game::Print()
{
	theBoard.PrettyPrinting();
}

bool Game::move(const char* p1, const char* p2)
{
	if(theBoard.moveFigure(p1, p2))
		return true;
	return false;
}

void Game::inputPlayers(const char* name1, const char* name2)
{
	player1 = new char[strlen(name1) + 1];
	strcpy_s(player1, strlen(name1) + 1, name1);

	player2 = new char[strlen(name2) + 1];
	strcpy_s(player2, strlen(name2) + 1, name2);
}

void Game::outputPlayers() const
{
	std::cout << "Player1: " << player1 << " - whites" << std::endl << "Player2: " << player2  << " - blacks" << std::endl;
}

char* Game::getPlayer1() const
{
	return player1;
}

char* Game::getPlayer2() const
{
	return player2;
}

bool Game::isFigureWhite(const char* p1)
{
	if (theBoard.getColorByPosition(p1) == 'w')
		return true;
	return false;
}

bool Game::isTheGameOver()
{
	if (!theBoard.isThereBlackKing())
	{
		writeDownPlayer(player1, 1);
		writeDownPlayer(player2, 0);
		return true;
	}
	if (!theBoard.isThereWhiteKing())
	{
		writeDownPlayer(player2, 1);
		writeDownPlayer(player1, 0);
		return false;
	}
	return false;
}

void Game::writeDownPlayer(const char* name, const short point)
{
	std::ofstream myFile;
	myFile.open("file.txt", std::ios::app);
	if (!myFile.is_open())
	{
		std::cout << "can't open file" << std::endl;
	}
	else {
		myFile << name;
		myFile << ": " << point << " \n";

		myFile.close();
	}
}