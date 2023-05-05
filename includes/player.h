#ifndef PLAYER_H
#define PLAYER_H

#include "genericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const string &name, const int &totalPokemons);

    virtual ~Player();

    Pokemon *ChangePokemon();
    void FullRevivePokemon();
};

#endif