/****************************************************************/
/*                     RPNCalculator Class                      */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

#pragma once
#include <iostream>

struct Operand
{
    float number;
    Operand* next;
};

class RPNCalculator
{
private:
  Operand* stackHead; // pointer to the top of the stack

public:
  RPNCalculator();
  ~RPNCalculator();
  bool isEmpty();
  void push(float num);
  void pop();
  Operand* peek();
  Operand* getStackHead() { return stackHead; }
  bool compute(std::string symbol);
};
