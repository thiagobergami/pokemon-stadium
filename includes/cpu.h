#ifndef CPU_H
#define CPU_H

#include "genericPlayer.h"
#include "pokemon.h"

class Cpu : public GenericPlayer
{

public:
    Cpu(const string &name);

    virtual ~Cpu();
    void DefineActivatePokemon();
    void GiveDamageToPlayer(Pokemon *playerPokemon);

private:
};

#endif