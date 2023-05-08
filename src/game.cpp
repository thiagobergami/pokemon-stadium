#include "../includes/game.h"

Game::Game(){};

Game::~Game(){};

void Game::AddPlayer(Player *player)
{
    m_player = player;
}

void Game::Play()
{
    /* 
    1 - Apresentar adversário para o jogador.
    2 - Jogador escolhe um pokemon para iniciar a luta
    3 - CPU escolhe seu pokemon
    4 - São apresentados os 4 golpes dos pokemons
    5 - Combate acontece
        5.1 - P1 dá dano no P2.
        5.2 - P2 está vivo?
            5.2.1 - sim - continua
            5.2.2 - não - troca pokemon
                5.2.2.1 - Possui pokemons? - continua
                5.2.2.2 - Não possui pokemons? 
                    5.2.2.2.1 - É o player? - Gameover
                    5.2.2.2.2 - nextCpu()
                        5.2.2.2.2.1 - Possui cpu - Passo 1.
                        5.2.2.2.2.2 - Vitória
        5.3 - Troca a ordem de ataque.
        5.4 - Repete combate
    */
}