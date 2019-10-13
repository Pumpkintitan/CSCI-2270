#include "RPNCalculator.hpp"
using namespace std;

RPNCalculator::RPNCalculator() {
  stackHead = NULL;
}

RPNCalculator::~RPNCalculator() {
  Operand* temp = stackHead;
  while(temp != NULL) {
    delete temp;
    temp = temp->next;
  }
  stackHead = NULL;
}

bool RPNCalculator::isEmpty() {
  if (stackHead == NULL) {
    return true;
  }
  return false;
}

void RPNCalculator::push(float num) {
  Operand* temp = new Operand;
  temp->number = num;
  temp->next = stackHead;
  stackHead = temp;
}

void RPNCalculator::pop() {
  if (!isEmpty()) {
    Operand* temp = new Operand;
    temp = stackHead;
    stackHead = stackHead->next;
    delete temp;
  } else {
    cout << "Stack empty, cannot pop an item." << endl;
  }
}

Operand* RPNCalculator::peek() {
  if (!isEmpty()) {
    return stackHead;
  } else {
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
}

bool RPNCalculator::compute(std::string symbol) {
  if (stackHead != NULL && stackHead->next != NULL ) {
    if (symbol == "+") {
      float temp1 = stackHead->number;
      float temp2 = stackHead->next->number;
      pop();
      pop();
      push(temp1 + temp2);
      return true;
    } else if (symbol == "*") {
      float temp1 = stackHead->number;
      float temp2 = stackHead->next->number;
      pop();
      pop();
      push(temp1 * temp2);
      return true;
    } else {
      cout << "err: invalid operation" << endl;
      return false;
    }
  } else {
    cout << "err: not enough operands" << endl;
    return false;
  }
}
