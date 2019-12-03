/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.cpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator RPN;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    string input;
    getline(cin, input);
    if (isNumber(input)) {
      RPN.push(stof(input));
    } else if (input == "=") {
      break;
    } else if (!isNumber(input)) {
      RPN.compute(input);
    } else {
      cout << "Invalid expression" << endl;
    }
  }
  if (RPN.isEmpty()) {
    cout << "No operands: Nothing to evaluate" << endl;
  } else if (RPN.getStackHead()->next != NULL) {
    cout << "Invalid expression" << endl;
  } else {
    cout << RPN.peek()->number << endl;
  }

  return 0;
}
