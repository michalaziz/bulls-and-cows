
#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
using std::string;

namespace bullpgia{

    class Guesser
    {
        
    public:
        uint length;
        virtual void startNewGame(uint length)
        {
             length=length;
        };
        virtual string guess()=0;
        void learn(string r){};

    };
}