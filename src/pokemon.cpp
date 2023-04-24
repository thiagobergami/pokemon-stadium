#include "../includes/pokemon.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

Pokemon::Pokemon(const string &name,
                 const vector<PokemonType *> &types,
                 int hitPoints,
                 const int attack, const int defense) : m_name(name),
                                                        m_types(types),
                                                        m_hitPoints(hitPoints),
                                                        m_attack(attack),
                                                        m_defense(defense) {}

Pokemon::~Pokemon(){};

void Pokemon::Print()
{
    cout << "Name: " << m_name << " - ";
    cout << "Types: ";
    for (size_t i = 0; i < m_types.size(); ++i)
    {
        cout << m_types[i]->GetName();
        if (i != m_types.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << " - ";
    cout << "Attack: " << m_attack << " - ";
    cout << "Defense: " << m_defense;
    cout << "\n";
};
vector<PokemonType *> Pokemon::GetTypes()
{
    return m_types;
};

int Pokemon::GetAttack()
{
    return m_attack;
}
int Pokemon::GetDefense()
{
    return m_defense;
}