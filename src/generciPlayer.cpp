#include "../includes/genericPlayer.h"
#include "../includes/party.h"
GenericPlayer::GenericPlayer(const string &name, const int &totalPokemons)
    : Party(totalPokemons), m_Name(name)
{
    m_isDefeated = false;
};
GenericPlayer::~GenericPlayer(){};

void GenericPlayer::Win() const
{
    cout << m_Name << " is the winner!" << endl;
}

void GenericPlayer::Loss()
{
    cout << m_Name << " was defeated" << endl;
    m_isDefeated = true;
}

bool GenericPlayer::IsDefeated() const
{
    return m_isDefeated;
}

Pokemon GenericPlayer::activatePokemon(int index) const
{
    for (const auto &pokemon : m_pokemons)
    {
        pokemon->Print();
    }
}