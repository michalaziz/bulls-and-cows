#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <list>

namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
private:
  list<string> combination;
  string temp;

public:
  string guess() override;
  void learn(string);
  void startNewGame(uint);
  void newList();
  void removeComb(string);
};

} // namespace bullpgia