#ifndef CPU_H
#define CPU_H

#include "genericPlayer.h"
#include "pokemon.h"

class Cpu : public GenericPlayer
{

public:
    Cpu(const string &name);

    virtual ~Cpu();

    Pokemon *ChangePokemon();

    int giveDamageToPlayer(Pokemon *myPokemon, Pokemon *playerPokemon);

private:
};

#endif