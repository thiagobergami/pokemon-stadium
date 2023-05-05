#include "../includes/pokemon.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

Pokemon::Pokemon(
    const int &index,
    const string &name,
    const vector<string> types,
    const map<string, double> multipliers,
    int hitPoints,
    const int attack,
    const int defense,
    const int special) : m_index(index),
                         m_name(name),
                         m_types(types),
                         m_hitPoints(hitPoints),
                         m_multipliers(multipliers),
                         m_attack(attack),
                         m_defense(defense),
                         m_special(special)
{
    m_isAlive = true;
}

Pokemon::~Pokemon(){};

void Pokemon::Print()
{
    cout << "ID: " << m_index << " - ";
    cout << "Name: " << m_name << " - ";
    cout << "Types: ";
    for (int i = 0; i < m_types.size(); ++i)
    {
        cout << m_types[i];
        if (i != m_types.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << " - ";
    cout << "Attack: " << m_attack << " - ";
    cout << "Defense: " << m_defense << " - ";
    cout << "Special: " << m_special;
    cout << "\n";
};
vector<string> Pokemon::GetTypes()
{
    return m_types;
};
void Pokemon::ressurrectPokemon()
{
    m_isAlive = true;
}
int Pokemon::GetAttack()
{
    return m_attack;
}
int Pokemon::GetDefense()
{
    return m_defense;
}
void Pokemon::takeDamage(int damage)
{
    cout << m_name << "Takes " << damage << endl;
    m_hitPoints = m_hitPoints - damage;

    if (m_hitPoints <= 0)
    {
        m_isAlive = false;
        cout << m_name << " Faited" << endl;
    }
}