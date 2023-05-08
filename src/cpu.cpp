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

int Cpu::giveDamageToPlayer(Pokemon *myPokemon, Pokemon *playerPokemon)
{
    vector<string> myType = myPokemon->GetTypes();
    map<string, double> cpuMultiplier;
    for (const string &type : myType)
    {
        if (type != "")
        {
            double pokemonType = playerPokemon->GetMultiplier(type);
            cpuMultiplier[type] = pokemonType;
        }
    }

    /*
    1 - Quais tipos do player pokemon?
    2 - Contra quais desses tipos eu dou mais dano?
    3 - Eu possuo golpes desse tipo?
    4 - Dar golpe do tipo que eu sou mais forte.
    */

    return 0;
}