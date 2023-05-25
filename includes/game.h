#ifndef GAME_H
#define GAME_H

#include "pokemon.h"
#include "player.h"
#include "cpu.h"
#include "pokedex.h"

#include <vector>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    void calculateDamage(int attackerIndex, int defenserInde);
    bool isGameOver();
    void Play();
    void ChangePokemonBattle();
    void AddPlayer(Player *player);
    void GenerateCPUs(Pokedex *pokedex);
    // function to validate if player wins;

private:
    Player *m_player;
    vector<Cpu *> m_cpus;
};

#endif