#include "calculate.hpp"
#include <string>
#include "iostream"
using namespace std;
namespace bullpgia
{
/*
-moving the choice and the guess strings to temp strings
-first checking the bulls and every time we found bull we erase it from the string by putting 0 instad
-second we are checking the pgia by passing the guess string for every num in the choice string 
-if we found pgia we erase it from the both strings
*/

string calculateBullAndPgia(string choice, string guess)
{
    int tempC[10] = {0}, tempG[10] = {0}, bull = 0, pgia = 0;

    for (int i = 0; i < choice.length(); i++)//moving the strings to temp strings
    {
        tempC[i] = choice[i];
        tempG[i] = guess[i];
    }
    for (int i = 0; i < choice.length(); i++)//searching for bulls 
    {
        if (tempC[i] == tempG[i])
        {
            bull++;
            tempC[i] = tempG[i] = 0;//erase the bull by puting 0 instad
        }
    }
    int c = 0;
    while (c < choice.length())//searching for pgia
    {
        if (tempC[c] != 0)//0 means its erased so pass
        {
            for (int i = 0; i < guess.length(); i++)
            {
                if(tempG[i]!=0)
                if(tempG[i]==tempC[c])//pass all the guess string for each number in the choice string
                {
                    pgia++;
                    tempC[c]=0;//erase
                    tempG[i]=0;//erase
                }
            }
        }
        c++;
    }
    return std::to_string(bull)+","+std::to_string(pgia);//return the num of bull and pgia [bull,pgia]
}

} // namespace bullpgia