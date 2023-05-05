#ifndef GAME_H
#define GAME_H

#include "pokemon.h"

class Game
{
public:
    Game();
    ~Game();
    void calculateDamage(int attackerIndex, int defenserInde);

private:
    Pokemon m_battles[2];
}

#endif