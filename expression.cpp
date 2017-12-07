#ifndef EXPRESSION_CPP
#define EXPRESSION_CPP

#include <iostream>
#include "expression.h"
#include "node.h"
#include "list.h"
#include <stack>
#include <sstream>

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

int Expression::stoi(string s){
  stringstream ss(s);
  int x;
  ss >> x;
  return x;
}

int Expression::Evaluate(){
  string exp = this->head->print_postfix();
  stack<int> integers;
  for (int i = 0; i<exp.size(); i++){
    char ch = exp[i];
    if (isdigit(ch)){
      integers.push(ch-'0');
    }
    else{
      int second = integers.top();
      integers.pop();
      int first = integers.top();
      integers.pop();
      if (ch == '+')
	integers.push(first + second);
      else if (ch== '-')
	integers.push(first - second);
      else if (ch == '*')
	integers.push(first * second);
      else if (ch == '/')
	integers.push(first / second);
    }
  }
  return integers.top();
}

char Expression::Compare(Expression& ex){
  int y = ex.Evaluate();
  int x = Evaluate();
  if (x > y){
    cout << '>' << endl;
    return '>';
  }
  else if (x < y){
    cout << '<' << endl;
    return '<';
  }
  else if (x == y){
    cout << '=' << endl;
    return '=';
  }
}

  

#endif
