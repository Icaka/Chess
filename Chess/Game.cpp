#include "Game.h"

Game::Game()
{
	//Pawn *aPawn = new Pawn;
	//aPawn->setOwner('w');
	//theBoard.addFigure(aPawn, 1, 1);
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