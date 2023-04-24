#include "../includes/PokemonType.h"

using namespace std;

PokemonType::PokemonType(const string &name,
                         PokemonType *strongType,
                         PokemonType *weakType) : m_name(name),
                                                  m_strongType(strongType),
                                                  m_weakType(weakType) {}

PokemonType::~PokemonType() {}

string PokemonType::GetName() const
{
    return m_name;
}

PokemonType *PokemonType::GetStrongType() const
{
    return m_strongType;
}

PokemonType *PokemonType::GetWeakType() const
{
    return m_weakType;
}