#ifndef GAME_H
#define GAME_H

#include "pokemon.h"
#include "player.h"
#include "cpu.h"

#include <vector>
#include <iostream>

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
    // function to validate if player wins;

private:
    vector<Pokemon *> m_battlePokemons;
    Player *m_player;
    vector<Cpu *> m_cpus;
};

#endif