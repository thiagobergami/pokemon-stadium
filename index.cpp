#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PokemonType
{
public:
    PokemonType(const string &name, PokemonType *strongType, PokemonType *weakType) : m_name(name),
                                                                                      m_strongType(strongType),
                                                                                      m_weakType(weakType) {}
    ~PokemonType() {}
    string getName() const
    {
        return m_name;
    }
    PokemonType *getStrongType() const
    {
        return m_strongType;
    }

    PokemonType *getWeakType() const
    {
        return m_weakType;
    }

private:
    string m_name;
    PokemonType *m_strongType;
    PokemonType *m_weakType;
};

class Pokemon
{
public:
    Pokemon(const string &name,
            const vector<PokemonType *> &types,
            int hitPoints,
            const int attack, const int defense) : m_name(name),
                                                   m_types(types),
                                                   m_hitPoints(hitPoints),
                                                   m_attack(attack),
                                                   m_defense(defense) {}
    ~Pokemon(){};

    string getName() const
    {
        return m_name;
    }
    void print() const
    {
        cout << "Name: " << m_name << " - ";
        cout << "Types: ";
        for (size_t i = 0; i < m_types.size(); ++i)
        {
            cout << m_types[i]->getName();
            if (i != m_types.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << " - ";
        cout << "Attack: " << m_attack << " - ";
        cout << "Defense: " << m_defense;
        cout << "\n";
    }
    vector<PokemonType *> getTypes() const
    {
        return m_types;
    }

    int getAttack() const
    {
        return m_attack;
    }

    int getDefense() const
    {
        return m_defense;
    }

private:
    string m_name;
    vector<PokemonType *> m_types;
    int m_hitPoints;
    int m_attack;
    int m_defense;
};

class Party
{
public:
    Party(const int totalParty);

    virtual ~Party();

    void addPokemon(Pokemon *aPokemon);
    void Clear();

    void printParty();

protected:
    vector<Pokemon *> m_pokemons;
};

Party::Party(const int totalParty)
{
    m_pokemons.reserve(totalParty);
};

Party::~Party(){};

void Party::addPokemon(Pokemon *aPokemon)
{
    m_pokemons.push_back(aPokemon);
};

void Party::printParty()
{
    for (const auto &pokemon : m_pokemons)
    {
        pokemon->print();
    }
};

class Pokedex : public Party
{
public:
    Pokedex(const int totalPokemons);

    virtual ~Pokedex(){};

    void Populate();

    const Pokemon *getPokemon();
};

Pokedex::Pokedex(const int totalPokemons) : Party(totalPokemons)
{
    m_pokemons.reserve(totalPokemons);
}

int main()
{
    Pokedex pokedex(2);

    // A good way to solve nullptr is creating a class for every pokemon type
    PokemonType *normal = new PokemonType("Normal", nullptr, nullptr);
    PokemonType *fire = new PokemonType("Fire", nullptr, normal);
    PokemonType *water = new PokemonType("Water", fire, nullptr);
    PokemonType *grass = new PokemonType("Grass", water, fire);
    PokemonType *flying = new PokemonType("Flying", grass, nullptr);

    vector<PokemonType *> charizardType = {fire, flying};
    Pokemon *charizard = new Pokemon("Charizard",
                                     charizardType,
                                     150, 100, 120);
    Pokemon *venusaur = new Pokemon("Venusaur", vector<PokemonType *>{grass, normal}, 80, 82, 83);

    pokedex.addPokemon(charizard);
    pokedex.addPokemon(venusaur);

    pokedex.printParty();
    return 0;
}