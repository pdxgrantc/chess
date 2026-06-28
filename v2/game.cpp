#ifndef GAME_CPP
#define GAME_CPP

#include <iostream>

using namespace std;

#include "game.h"

Game::Game()
{
    this->player_to_move = 0;
    this->turn = 0;

    gameBoard = new Board;
}

Game::~Game()
{
    delete gameBoard;
}

void Game::startGame() {}

#endif
