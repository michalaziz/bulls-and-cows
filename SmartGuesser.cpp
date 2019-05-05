#include "SmartGuesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <string>
using std::string;
using namespace std;
using namespace bullpgia;

/*create a list that contins all the option of combination that we have with our length of choose
and than run on the option and ask if its the right string we stop when left only one combination
or that we guess it befor while its not the right guess we remove it from the list.*/


string SmartGuesser::guess() //take one combination from list that contain all the option we have
{
    list<string>::iterator it = combination.begin();
    if (combination.size() == 0) //no combination in the list so fill it by the function newList
        newList();
    if (combination.size() > 1) //choose some combination from all the option randomal
    {
        std::advance(it, rand() % (combination.size() - 1));
        this->temp = *it; //now in temp we have the combination that we got randomal
    }
    else if (combination.size() == 1) //we have only one combination so we take it
        this->temp = *combination.begin();
    return temp;
}

//create new list with all the combination that can be in this length
void SmartGuesser::newList()
{
    int size = pow(10, length);//calculate the number of the option to combination
    for (size_t i = 0; i < size; i++)
    {
        stringstream sin;
        sin << setw(length) << setfill('0') << i;//filiing the list 
        string str = sin.str();
        combination.push_front(str);
    }
}

//remove the combination that we dont need.
void SmartGuesser::removeComb(string result)
{
    list<string>::iterator it2 = combination.begin();
    while (it2 != combination.end())//pass on the list 
    {
        string pre = calculateBullAndPgia(*it2, temp);//calculate the bull and pgia for previus 
        if (pre.compare(result) != 0)//compar the previus and the result and if its diff we erase the comb from the list 
        {
            it2 = combination.erase(it2);
        }
        else//if its not diff we dont erase this comb and go to the next one 
        {
            ++it2;
        }
    }
    this->combination.remove(temp);
}

//starting a new game so we reset all.
void SmartGuesser::startNewGame(uint length)
{
    combination.clear();//clear the list 
    this->length=length;//set a new length of the choose
    newList();//create a new list 
}

void SmartGuesser::learn(string result)
{
    removeComb(result);
}


