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
  Node* current = new Node(PLUS);
  Node* top = current;
  int i = 1;
  char cursor = s[i];
  while (i != s.size()-1){
    if (cursor == '('){
      Node* n = new Node(PLUS);
      if (current->get_left() == NULL)
	current->set_left(n);
      else
	current->set_right(n);
      n->set_parent(current);
      current = n;
    }
    else if (cursor == '+' || '-' || '/' || '*')
      current->set_op(s_to_operator(cursor));
    else if (cursor == 'x'){
      Node* b = new Node(cursor);
      current->set_left(b);}
    else if (cursor == '0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9'){
      Node* a = new Node(cursor-'0');
      current->set_right(a);}
    else if (cursor == ')')
      current = current->get_parent();
    i++;
    cursor = s[i];
  }
  return top;
}
      
