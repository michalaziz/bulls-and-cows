
#include "calculate.hpp"
#include <string>
#include <iostream>

string bullpgia::calculateBullAndPgia(string choice, string guess)
{
    int c = 0, bull = 0, pgia = 0;
    if (choice.compare(guess)==0)

        return std::to_string(choice.length()) + " bull 0 pgia";

    else
    {
        while (c < choice.length())
        {
            if (choice[c] == guess[c])
                bull++;
            else
                for (int i = 0; i < guess.length(); i++)
                {
                    if (guess[i] == choice[c])
                        pgia++;
                }
            c++;
        }
    }
    return std::to_string(bull) + " bull" + std::to_string(pgia) + " pgia";
}