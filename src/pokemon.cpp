#include "../includes/pokemon.h"

Pokemon::Pokemon(
    const int &index,
    const string &name,
    const vector<string> types,
    const map<string, double> multipliers,
    int hitPoints,
    const int attack,
    const int defense,
    const int special,
    const vector<Move> moves) : m_index(index),
                                m_name(name),
                                m_types(types),
                                m_hitPoints(hitPoints),
                                m_multipliers(multipliers),
                                m_attack(attack),
                                m_defense(defense),
                                m_special(special),
                                m_moves(moves)
{
    m_isAlive = true;
    printPartyFormat();
}

Pokemon::~Pokemon(){};
string Pokemon::GetName() const
{
    return m_name;
}
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
void Pokemon::TakeDamage(int damage)
{
    cout << m_name << "Takes " << damage << endl;
    m_hitPoints = m_hitPoints - damage;

    if (m_hitPoints <= 0)
    {
        m_isAlive = false;
        cout << m_name << " Faited" << endl;
    }
}

void Pokemon::printPartyFormat()
{
    string isAlive;
    if (m_isAlive == false)
    {
        isAlive = "Defeated";
    }
    else
    {
        isAlive = "Health";
    }
    cout << m_index << " - " << m_name << " - " << isAlive << endl;
}

int Pokemon::GetIndex()
{
    return m_index;
}

int Pokemon::GetSpecial()
{
    return m_special;
};

double Pokemon::GetMultiplier(const string &type)
{
    double dmg_multiplier = m_multipliers[type];
    return dmg_multiplier;
}
vector<Move> Pokemon::GetMoves()
{
    return m_moves;
}