#include "../includes/pokedex.h"
#include "../includes/PokemonType.h"
#include "../includes/pokemon.h"

int main()
{
    Pokedex *pokedex = new Pokedex();
    pokedex->printPokedex();

    Pokemon charizard = pokedex->getPokemon("charizard");

    charizard.Print();

    return 0;
}