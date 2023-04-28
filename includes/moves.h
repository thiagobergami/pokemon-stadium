#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <iostream>

using namespace std;

class Moves
{
public:
    Moves(const string m_name, const string m_type, const int power);
    ~Moves();
    string getMoveName();
    int getPower();

private:
    string m_name;
    string m_type;
    int m_power;
};

#endif