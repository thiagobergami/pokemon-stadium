#ifndef GENERICPLAYER_H
#define GENERICPLAYER_H

#include "party.h"

class GenericPlayer : public Party
{
public:
    GenericPlayer(const string &name = "");

    virtual ~GenericPlayer();



private:
    string m_Name;

};

#endif