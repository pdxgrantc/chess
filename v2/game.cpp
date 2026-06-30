#ifndef GAME_CPP
#define GAME_CPP

#include <iostream>
#include <string>
#include <regex>

using namespace std;

#include "game.h"
#include "helpers.h"

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

void Game::startGame()
{
    takeInput(player_to_move);
}



#endif
