
#include <iostream>
#include <stdlib.h>
#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
      private:
        /* data */
      public:
        string guess()override;
    };
}
