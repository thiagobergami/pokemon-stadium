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

Cpu::~Cpu()
{
    cout << m_Name << " was defeated";
    cout << "\n\n";
};

void Cpu::GiveDamageToPlayer(Pokemon *my_pokemon, Pokemon *player_pokemon)
{
    vector<Move> myMoves = myPokemon->GetMoves();
    double player_pokemon_multiplier = 0.0;
    Move attacker_move = chosenMove[0];
    for (const auto &move : myMoves)
    {
        double pokemon_type = playerPokemon->GetMultiplier(move.type);
        if (pokemon_type = > player_pokemon_multiplier)
        {
            player_pokemon_multiplier = pokemon_type;
            if (move.power = > chosen_move.power)
            {
                attacker_move = move;
            }
        }
    }
    double damage = CalculateDamageCalculateDamage(attacker_move,
                                                   attack_pokemon = my_pokemon,
                                                   defenser_pokemon = player_pokemon,
                                                   modifier = player_pokemon_multiplier);

    player_pokemon->takeDamage(damage);
}