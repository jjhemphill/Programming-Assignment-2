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


 private:
  Node* head;
};
  
#endif
