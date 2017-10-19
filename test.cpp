#include <iostream>
#include "node.h"
using namespace std;
int main(){
  PointerNode pnode1 = PointerNode();
  Node node1 = Node();
  Node* p1= &node1;
  pnode1.set_left(p1);
  
  node1.set_right('5');
  char x = p1->get_right();
  cout<<x<<endl;
  return 0;
}
