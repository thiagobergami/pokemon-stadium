#include "../includes/cpu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

using namespace std;

Cpu::Cpu(const string &name) : GenericPlayer(name, 0)
{
    srand(time(NULL));
    int random_number = rand() % 4 + 3;
    totalPokemons = random_number;
};
void Cpu::DefineActivatePokemon()
{
    m_activated_pokemon = m_pokemons[0];
}
Cpu::~Cpu()
{
    cout << m_Name << " was defeated";
    cout << "\n\n";
};

void Cpu::GiveDamageToPlayer(Pokemon *my_pokemon, Pokemon *player_pokemon)
{
    vector<Move> my_moves = my_pokemon->GetMoves();
    double player_pokemon_multiplier = 0.0;
    Move attacker_move = my_moves[0];
    for (const Move &move : my_moves)
    {
        double pokemon_type = player_pokemon->GetMultiplier(move.type);
        if (pokemon_type >= player_pokemon_multiplier)
        {
            player_pokemon_multiplier = pokemon_type;
            if (move.power >= attacker_move.power)
            {
                attacker_move = move;
            }
        }
    }
    double damage = CalculateDamage(attacker_move,
                                    my_pokemon,
                                    player_pokemon,
                                    player_pokemon_multiplier);

    player_pokemon->TakeDamage(damage);
}
