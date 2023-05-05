#include "../includes/player.h"

Player::Player(const string &name, const int &totalPokemons) : GenericPlayer(name, totalPokemons){};

Player::~Player(){};

Pokemon *Player::ChangePokemon()
{
    int index;
    printParty();
    do
    {
        cout << "Choose the pokemon you want to change: ";
        cin >> index;
        cout << "\n";
    } while (!validatePartyPokemon(index));

    Pokemon *pokemon = activatePokemon(index);
    return pokemon;
}

void Player::FullRevivePokemon()
{
    for (auto &pokemon : m_pokemons)
    {
        pokemon->ressurrectPokemon();
    }
}