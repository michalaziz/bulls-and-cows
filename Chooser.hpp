#pragma once
#include <iostream>
#include <stdlib.h>
using std::string;

//generic class of chooser
namespace bullpgia
{
    class Chooser
    {
    public:

        virtual string choose(uint length)=0;//pure virtual 
    };
}