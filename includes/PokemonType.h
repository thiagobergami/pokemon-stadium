#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H

#include <string>

using std::string;

class PokemonType
{
public:
    PokemonType(const string &name, PokemonType *strongType, PokemonType *weakType);
    ~PokemonType();
    string GetName() const;
    PokemonType *GetStrongType() const;
    PokemonType *GetWeakType() const;

private:
    string m_name;
    PokemonType *m_strongType;
    PokemonType *m_weakType;
};

#endif