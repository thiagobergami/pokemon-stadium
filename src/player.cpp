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
    vector<string> cpu_types = cpu_pokemon->GetTypes();
    double modifier;
    if (cpu_types.size() > 1)
    {
        double modifier_1 = m_activated_pokemon->GetMultiplier(cpu_types[0]);
        double modifier_2 = m_activated_pokemon->GetMultiplier(cpu_types[1]);
        modifier = (modifier_1 > modifier_2) ? modifier_1 : modifier_2;
    }
    else
    {
        modifier = m_activated_pokemon->GetMultiplier(cpu_types[0]);
    }
    cout << modifier;

    double damage = CalculateDamage(move, m_activated_pokemon, cpu_pokemon, modifier);
    cout << damage;
    cpu_pokemon->TakeDamage(damage);
}