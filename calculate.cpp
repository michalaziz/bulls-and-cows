#include "calculate.hpp"
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia{

string calculateBullAndPgia(string choice, string guess)
{
    int c = 0, bull = 0, pgia = 0;
    if (choice.compare(guess)==0)

        return to_string(choice.length()) + "," + to_string(0)  ;

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
    return to_string(bull) + "," + to_string(pgia) ;
}
}