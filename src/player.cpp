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

void Player::PrintCombat() const
{
    vector<Move> activated_pokemon_move = m_activated_pokemon->GetMoves();
    int index = 1;
    cout << "Choose attack by index: \n";
    for (const Move &move : activated_pokemon_move)
    {
        cout << index << " - " << move.name << " - " << move.type << " - " << move.power << endl;
        index++;
    }
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