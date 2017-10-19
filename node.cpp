#include <iostream>
#include "node.h"
using namespace std;

//define Node functions
Node::Node(){
  op='+';
  left='x';  //always initialize to x
  right='0';
}
void Node::set_op(char oper){
  op=oper;
}
void Node::set_left(char var){  //DO WE NEED THIS IF ALWAYS INITIALIZING TO X???
  left=var;
}
void Node::set_right(char num){
  right=num;
}
char Node::get_op(){
  return op;
}
char Node::get_left(){
  return left;
}
char Node::get_right(){
  return right;
}


//define PointerNode functions
PointerNode::PointerNode(){
  op='+';
  left=NULL;
  right=NULL;
}
void PointerNode::set_op(char oper){
  op=oper;
}
void PointerNode::set_left(Node* p1){
  left=p1;
}
void PointerNode::set_right(Node* p2){
  right=p2;
}
char PointerNode::get_op(){
  return op;
}
