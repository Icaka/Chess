#include "Game.h"

Game::Game()
{
	Pawn *aPawn = new Pawn;
	aPawn->setOwner('w');
	theBoard.addFigure(aPawn, 1, 1);
}

void Game::figureLayout()
{

}

void Game::Print()
{
	theBoard.PrettyPrinting();
}