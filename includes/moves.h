#ifndef MOVES_H
#define MOVES_H

#include <string>
#include <iostream>

using namespace std;

class Moves
{
public:
    Moves(const string name, const string type, const int power, const string class_name);
    ~Moves();
    string getMoveName();
    int getPower();

private:
    string m_name;
    string m_type;
    int m_power;
    string m_class;
};

#endif