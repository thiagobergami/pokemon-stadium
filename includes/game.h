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
#include <memory>

using namespace std;

class Game
{
public:
    Game();
    ~Game();
    void calculateDamage(int attackerIndex, int defenserInde);
    bool isGameOver();
    void Play();
    bool ValidadeActivatedCPU();
    void ChangePokemonBattle();
    void AddPlayer(shared_ptr<Player> player);
    void GenerateCPUs(shared_ptr<Pokedex> pokedex);
    // function to validate if player wins;

private:
    shared_ptr<Player> m_player;
    vector<shared_ptr<Cpu>> m_cpus;
};

#endif