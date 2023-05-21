#ifndef PLAYER_H
#define PLAYER_H

#include "genericPlayer.h"
#include "pokemon.h"
#include "move.h"

class Player : public GenericPlayer
{
public:
    Player(const string &name, const int &totalPokemons);

    virtual ~Player();

    void ChangePokemon();
    void FullRevivePokemon();
    void GiveDamage(Pokemon *cpu_pokemon);
};

#endif