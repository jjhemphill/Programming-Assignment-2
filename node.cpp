#include <iostream>
#include <string>
#include "node.h"
using namespace std;



Node::Node(char var){
  data.var = var;
  node_t = VARIABLE;
}

Node::Node(operator_type op, Node* operand1, Node* operand2){
  data.op = op;
  node_t = EXPRESSION;
  this->operand1 = operand1;
  this->operand2 = operand2;
}

Node::Node(int val){
  data.val = val;
  node_t = INTEGER;
}

void Node::set_left(Node* n){
  operand1 = n;
}

void Node::set_right(Node* n){
  operand2 = n;
}

void Node::set_op(operator_type op){
  data.op = op;
}

void Node::set_parent(Node* p){
  parent = p;
}
int Node::get_int(){
  return data.val;
}

char Node::get_char(){
  return data.var;
}

operator_type Node::get_op(){
  return data.op;
}

char Node::print_operator() const {
  if (data.op == PLUS)
    return '+';
  else if (data.op == MINUS)
    return '-';
  else if (data.op == MULT)
    return '*';
  else if (data.op == DIVIDE)
    return '/';
}

string Node::print_infix() const {
  string infix = "(";
  infix.append( operand1->data.var + to_string(data.op) + (to_string(operand2->data.val)) + ")");
  return infix;
}


  
