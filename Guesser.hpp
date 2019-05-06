#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia
{

class Guesser
{
public:
    unsigned int  length;
    string bp; //how many bull and pgia
    virtual void startNewGame(uint length) { this->length = length; };
    virtual string guess() = 0;
    virtual void learn(string result) { this->bp = result; };
};
} // namespace bullpgia