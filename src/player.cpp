#include "../includes/player.h"

Player::Player(const string &name, const int &totalPokemons) : GenericPlayer(name, totalPokemons){};

Player::~Player(){};

void Player::ChangePokemon()
{
    int index;
    printParty();
    do
    {
        cout << "Choose the pokemon you want: ";
        cin >> index;
        cout << "\n";
    } while (!validatePartyPokemon(index));

    Pokemon *pokemon = activatePokemon(index);
    m_activated_pokemon = pokemon;
}

void Player::FullRevivePokemon()
{
    for (auto &pokemon : m_pokemons)
    {
        pokemon->ressurrectPokemon();
    }
}

void Player::GiveDamage(Pokemon *cpu_pokemon)
{
}