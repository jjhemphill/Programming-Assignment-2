#ifndef EXPRESSION_CPP
#define EXPRESSION_CPP

#include <iostream>
#include "expression.h"
#include "node.h"
#include "list.h"

using namespace std;

Expression::Expression(Node* head){
  this->head = head;
}

string Expression::infixString(){
  return this->head->print_infix();
}

string Expression::prefixString(){
  return this->head->print_prefix();
}

string Expression::postfixString(){
  return this->head->print_postfix();
}

#endif
