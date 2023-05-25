#include "../includes/pokedex.h"
#include "../includes/pokemon.h"
#include "../includes/player.h"
#include "../includes/game.h"

int main()
{
    Pokedex *pokedex = new Pokedex();
    Game *game = new Game();
    char isCorrect;
    string trainerName;
    do
    {
        cout << "\t\tWelcome to pokemon Stadium\n\n";
        cout << "Tell me your name: ";
        cin >> trainerName;
        cout << "\n\nOk, your name will be :" << trainerName;
        cout << "\n\nIs that correct?(Y/N): ";
        cin >> isCorrect;
    } while (isCorrect != 'Y' && isCorrect != 'y');

    Player *player = new Player(trainerName, 3);

    pokedex->printPokedex();
    cout << "\n\nNow, choose or 3 pokemons by index: ";
    int counter = 1;
    do
    {
        int index;
        bool validate;
        cout << "\nChoose pokemon number " << counter << ": ";
        cin >> index;
        validate = pokedex->validateIndex(index);
        if (validate == true)
        {
            ++counter;
            player->addPokemon(pokedex->getPokemon(index, 300));
        }
        else
        {
            cout << "\nInvalid Option. Try again";
        }
    } while (counter <= 3);

    player->ChangePokemon();
    game->AddPlayer(player);

    // generate CPU
    game->GenerateCPUs(pokedex);
    game->Play();

    return 0;
}