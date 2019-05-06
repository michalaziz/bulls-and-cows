#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <list>

namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
private:
  list<std::string> combination;
  std::string temp;

public:
  string guess() override;
  void learn(string result)override;
  void startNewGame(uint length)override;
  void newList();
  void removeComb(string result);
};

} // namespace bullpgia