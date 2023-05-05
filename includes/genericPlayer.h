#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "party.h"
#include "pokemon.h"
class GenericPlayer : public Party
{

public:
    GenericPlayer(const string &name = "", const int &totalPokemons = 6);

    virtual ~GenericPlayer();

    bool IsDefeated() const;
    void Win() const;
    void Loss();
    Pokemon activatePokemon(int index) const;

private:
    string m_Name;
    bool m_isDefeated;
};

#endif