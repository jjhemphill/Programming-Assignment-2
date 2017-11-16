#include <iostream>
#include "list.cpp"
using namespace std;

int main(){
  string s = "(((x+3)*(x-6))-(x/2))";
  Node* t = makeTree(s);
  t = t->get_left();
  t = t->get_right();
  t = t->get_right();
  int a = t->get_int();
  
  cout << a << endl;
 
  return 0;
}
