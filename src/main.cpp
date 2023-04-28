#include "../includes/pokedex.h"
#include "../includes/PokemonType.h"
#include "../includes/pokemon.h"

int main()
{
    Pokedex pokedex(2);

    // A good way to solve nullptr is creating a class for every pokemon type
    /* PokemonType *normal = new PokemonType("Normal", nullptr, nullptr);
    PokemonType *fire = new PokemonType("Fire", nullptr, normal);
    PokemonType *water = new PokemonType("Water", fire, nullptr);
    PokemonType *grass = new PokemonType("Grass", water, fire);
    PokemonType *flying = new PokemonType("Flying", grass, nullptr); */

    vector<string> charizardType = {"fire", "flying"};
    Pokemon *charizard = new Pokemon("Charizard",
                                     charizardType,
                                     150, 100, 120);
    Pokemon *venusaur = new Pokemon("Venusaur", vector<string>{"grass", "normal"}, 80, 82, 83);

    pokedex.addPokemon(charizard);
    pokedex.addPokemon(venusaur);

    pokedex.printParty();
    return 0;

    return 0;
}