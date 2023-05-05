#include "../includes/pokedex.h"
#include "../includes/PokemonType.h"
#include "../includes/pokemon.h"
#include "../includes/player.h"

int main()
{
    Pokedex *pokedex = new Pokedex();
    Player *player = new Player("Thiago", 3);
    player->addPokemon(pokedex->getPokemon(1));
    player->activatePokemon(1);
    player->ChangePokemon();

    return 0;
}