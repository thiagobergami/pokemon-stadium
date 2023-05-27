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

int Player::ChooseCombatOption()
{
    vector<Move> activated_pokemon_move = m_activated_pokemon->GetMoves();
    int index = 1;
    int choosed_index;
    cout << "Choose attack by index: \n";
    for (const Move &move : activated_pokemon_move)
    {
        cout << index << " - " << move.name << " - " << move.type << " - " << move.power << endl;
        index++;
    }
    cout << "99 - Change Pokemon" << endl;
    cin >> choosed_index;
    return choosed_index;
}

void Player::FullRevivePokemon()
{
    for (auto &pokemon : m_pokemons)
    {
        pokemon->ressurrectPokemon();
    }
}

void Player::GiveDamage(Pokemon *cpu_pokemon, int move_index)
{

    Move move = m_activated_pokemon->GetMoveByIndex(move_index);

    cout << m_activated_pokemon->GetName()
         << " used "
         << move.name << "\n"
         << endl;

    vector<string> cpu_types = cpu_pokemon->GetTypes();
    double modifier = cpu_pokemon->GetMultiplier(move.type);
    int damage = CalculateDamage(move, m_activated_pokemon, cpu_pokemon, modifier);

    cpu_pokemon->TakeDamage(damage);
}