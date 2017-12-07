#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include "list.h"
using namespace std;

class Expression {
 public:
  Expression(Node* head);
  
  string infixString();
  string prefixString();
  string postfixString();

  int Evaluate();
  char Compare(Expression& ex);
  int stoi(string s);


 private:
  Node* head;
};
  
#endif
