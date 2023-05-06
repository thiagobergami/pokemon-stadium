#include "../includes/game.h"

Game::Game(){};

Game::~Game(){};

void Game::AddPlayer(Player *player)
{
    m_player = player;
}