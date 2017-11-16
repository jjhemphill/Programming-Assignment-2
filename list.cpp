#include "list.h"
using namespace std;

operator_type s_to_operator(char c) {
  if (c == '+')
    return PLUS;
  else if (c == '-')
    return MINUS;
  else if (c == '*')
    return MULT;
  else if (c == '/')
    return DIVIDE;
}


Node* makeTree(string s){
  Node* current = new Node(PLUS,NULL,NULL);
  Node* top = current;
  int i = 1;
  char cursor = s[i];
  while (i != s.size()){
    if (cursor == '('){
      Node* n = new Node(PLUS);
      if (current->get_left() == NULL){
       	current->set_left(n);
      }
      else
	current->set_right(n);
      n->set_parent(current);
      current = n;
    }
    if ((cursor == '+')||(cursor=='-')||(cursor=='*')||(cursor=='/'))
      current->set_op(s_to_operator(cursor));
    if (cursor == 'x'){
      Node* b = new Node(cursor);
      current->set_left(b);
    }
    if ((cursor == '1')||(cursor == '2')||(cursor == '3')||(cursor == '4')||(cursor == '5')||(cursor == '6')||(cursor == '7')||(cursor == '8')||(cursor == '9')){
      Node* a = new Node(cursor-'0');
      current->set_right(a);}
    if (cursor == ')'){
      current = current->get_parent();
    }
    i++;
    cursor = s[i];
  }
  return top;
}
      
