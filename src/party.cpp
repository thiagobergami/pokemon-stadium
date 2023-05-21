#include "../includes/party.h"

Party::Party(const int totalParty = 6)
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
        cout << "Pokemon: ";
        pokemon->printPartyFormat();
    }
};

void Party::RemovePokemon(Pokemon *aPokemon)
{
    for (int i = 0; m_pokemons.size(); i++)
    {
        if (aPokemon == m_pokemons[i])
        {
            m_pokemons.erase(m_pokemons.begin() + i);
            // m_pokemons[i]->~Pokemon();
        }
    }
    cout << aPokemon->GetName() << " was removed from CPU party" << endl;
}

Pokemon *Party::GetActivatedPokemon() const
{
    return m_activated_pokemon;
}