#pragma once
#include <iostream>
#include <stdlib.h>
using std::string;


namespace bullpgia
{
    class Chooser
    {
    public:

        virtual string choose(uint lenght)=0;//pure virtual 
    };
    



}