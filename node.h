#include <iostream>
using namespace std;

class Node{
 public:
  Node();
  void set_op(char);
  void set_left(char);
  void set_right(char);
  char get_op();
  char get_left();
  char get_right();
 private:
  char op;
  char left;
  char right;
};


class PointerNode{
 public:
  PointerNode();
  void set_op(char);
  void set_left(Node*);
  void set_right(Node*);
  char get_op();
 private:
  char op;
  Node* left;
  Node* right;
};
