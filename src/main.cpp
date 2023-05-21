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
            player->addPokemon(pokedex->getPokemon(index));
        }
        else
        {
            cout << "\nInvalid Option. Try again";
        }
    } while (counter <= 3);

    player->ChangePokemon();
    player->GetActivatedPokemon()->Print();
    /*  cout << "That's you party: \n";
     player->printParty();
     do
     {
         int index;
         cout << "\nOk. Choose your the pokemon that will start the battle by index";
         cin >> index;
         bool validate = pokedex->validateIndex(index);
         if (validate == true)
         {
             Pokemon *activated_pokemon = pokedex->getPokemon(index);
             player->activatePokemon(activated_pokemon);
         }
         else
         {
             cout << "\nInvalid Option. Try again";
         }
     } while (player->GetActivatedPokemon()->GetName().empty());

     cout << player->GetActivatedPokemon()->GetName();
     /* player->activatePokemon(1); */
    /*
    game->AddPlayer(player);
    player->ChangePokemon(); */

    return 0;
}