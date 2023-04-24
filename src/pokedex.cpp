#include "../includes/pokedex.h"

Pokedex::Pokedex(const int totalPokemons) : Party(totalPokemons)
{
    m_pokemons.reserve(totalPokemons);
}