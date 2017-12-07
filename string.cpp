#ifndef STRING_CPP
#define STRING_CPP

#include <iostream>
#include <string>
#include "string.h"
using namespace std;

int main(){
  string s;
  cout << "Enter infix expression: ";
  std::getline(cin,s);
  Node* head = makeTree(s);
  Expression ex = Expression(head);
  string infix = ex.infixString();
  string prefix = ex.prefixString();
  string postfix = ex.postfixString();
  string together = infix + "\n" + prefix + "\n" + postfix + "\n";
  cout << infix << endl << prefix << endl << postfix << endl;
  
  return 0;
}

#endif
