#include <iostream>
#include "list.cpp"
using namespace std;

int main(){
  string s = "(((x+3)*(x+5))-(x/2))";
  Node* t = makeTree(s);
  t = t->get_left();
  t = t->get_left();
  t = t->get_left();
  char a = t->get_char();
  
  cout << a << endl;
 
  return 0;
}
