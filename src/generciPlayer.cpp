#include "../includes/genericPlayer.h"
#include "../includes/party.h"

GenericPlayer::GenericPlayer(const string &name, const int &totalPokemons)
    : Party(totalPokemons), m_Name(name)
{
    m_isDefeated = false;
};
GenericPlayer::~GenericPlayer()
{
    for (Pokemon *pokemon : m_pokemons)
    {
        cout << "Deleting " << pokemon->GetName() << endl;
        delete pokemon;
    }
};

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

int GenericPlayer::GetTotalPokemonsAlive()
{
    int totalPokemons = 0;
    for (const auto *pokemon : m_pokemons)
    {
        if (pokemon->IsAlived())
        {
            ++totalPokemons;
        }
    }
    return totalPokemons;
}

string GenericPlayer::GetName() const
{
    return m_Name;
}

Pokemon *GenericPlayer::activatePokemon(int index)
{
    Pokemon *chosen_pokemon;
    for (const auto &pokemon : m_pokemons)
    {
        if (index == pokemon->GetIndex())
        {
            chosen_pokemon = pokemon;
        }
    }

    return chosen_pokemon;
}
/*

Improve later

*/
bool GenericPlayer::validatePartyPokemon(int index)
{
    for (const auto &pokemon : m_pokemons)
    {
        if (index == pokemon->GetIndex() && pokemon->IsAlived())
        {
            cout << pokemon->GetIndex() << endl;
            return true;
        }
    }

    cout << "Pokemon not found ";
    cout << "\n\n";
    return false;
}

int GenericPlayer::CalculateDamage(
    Move attacker_move,
    Pokemon *attacker_pokemon,
    Pokemon *defenser_pokemon,
    double modifier)
{

    if (modifier >= 2.0)
    {
        cout << "It's super effective!\n"
             << endl;
    }
    int A = 10; // considering all pokemons have level 20
    int P = attacker_move.power;
    int A_D;
    if (attacker_move.move_class == "physical")
    {
        A_D = ceil(attacker_pokemon->GetAttack() / defenser_pokemon->GetDefense());
    }
    else
    {
        A_D = ceil(attacker_pokemon->GetSpecial() / defenser_pokemon->GetSpecial());
    }
    A_D = A_D == 0 ? 1 : A_D;

    double bdmg = ((A * P * A_D) / 50) + 2; // base damage
    double stab = 1.0;

    for (const auto &type : attacker_pokemon->GetTypes())
    {
        if (type == attacker_move.type)
        {
            stab = 1.5;
        }
    }
    srand(time(nullptr));
    int randomNumber = rand() % 39 + 217;
    int damage = round((bdmg * stab * modifier) * randomNumber / 255) + 1;

    return damage;
}
int GenericPlayer::GetMaxAllowedPokemons() const
{
    return totalPokemons;
}
