#include "../includes/pokedex.h"
#include "../includes/PokemonType.h"
#include "../includes/pokemon.h"
#include "../includes/genericPlayer.h"

int main()
{
    Pokedex *pokedex = new Pokedex();
    GenericPlayer *player = new GenericPlayer("Thiago", 1);
    Pokemon *newPokemon = pokedex->getPokemon(1);
    player->addPokemon(newPokemon);
    player->printParty();
    player->activatePokemon(1);

    return 0;
}