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

Pokemon *GenericPlayer::activatePokemon(int index)
{
    for (const auto &pokemon : m_pokemons)
    {
        if (index == pokemon->GetIndex())
        {
            return pokemon;
        }
    }
    cout << "Pokemon not found" << endl;
    return nullptr;
}
/*

Improve later

*/
bool GenericPlayer::validatePartyPokemon(int index)
{
    for (const auto &pokemon : m_pokemons)
    {
        if (index == pokemon->GetIndex())
        {
            return true;
        }
    }

    cout << "Pokemon not found ";
    cout << "\n\n";
    return false;
}

double GenericPlayer::CalculateDamage(Move attacker_move, Pokemon *attacker_pokemon, Pokemon *defenser_pokemon, double modifier)
{
    int A = 42; // considering all pokemons have level 100
    int P = attacker_move.power;
    int A_D;
    if (attacker_move.move_class == "physical")
    {
        A_D = attacker_pokemon->GetAttack() / defenser_pokemon->GetDefense();
    }
    else
    {
        A_D = attacker_pokemon->GetSpecial() / defenser_pokemon->GetSpecial();
    }

    int bdmg = ((A * P * A_D) / 50) + 2; // base damage
    double stab = 1.0;

    for (const auto &type : attacker_pokemon->GetTypes())
    {
        if (type == attacker_move.name)
        {
            stab = 1.5;
        }
    }
    srand(time(nullptr));
    int randomNumber = rand() % 39 + 217;
    
    double damage = (bdmg * stab * modifier) / randomNumber;

    return damage;
}