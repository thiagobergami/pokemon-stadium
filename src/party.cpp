#include "../includes/party.h"

Party::Party(const int totalParty)
{
    m_pokemons.reserve(totalParty);
};

Party::~Party(){};

void Party::addPokemon(Pokemon *aPokemon)
{
    m_pokemons.push_back(aPokemon);
};

void Party::printParty()
{
    for (const auto &pokemon : m_pokemons)
    {
        pokemon->Print();
    }
};