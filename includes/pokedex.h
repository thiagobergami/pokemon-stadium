#ifndef POKEDEX_H
#define POKEDEX_H

#include "party.h"
#include "pokemon.h"

class Pokedex : public Party
{
public:
    Pokedex(const int totalPokemons);

    virtual ~Pokedex();

    void Populate();

    const Pokemon *getPokemon();
};

#endif