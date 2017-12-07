#ifndef NODE_CPP
#define NODE_CPP

#include <iostream>
#include <string>
#include <sstream>
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
  if (operand1->node_t == EXPRESSION){
    string infix = operand1->print_infix();
    if (operand2->node_t == EXPRESSION){
      string infix2 = operand2->print_infix();
      infix = "(" + infix + print_operator() + infix2 + ")";
      return infix;
    }
  }
  else {
    int i = operand2->data.val;
    char d = (i+'0');
    stringstream ss,dd,cc;
    string target,target1,target2;
  
    ss << d;
    ss >> target;
    dd << (print_operator());
    dd >> target1;
    if (operand1->node_t == VARIABLE){
      cc << (operand1->get_char());
      cc >> target2;
    }
    else if (operand1->node_t == INTEGER){
      cc << (operand1->get_int());
      cc >> target2;
    }
    string node = "(" + target2 + target1 + target + ")";
    return node;
  }
}
    
string Node::print_prefix() const {
  if (operand1->node_t == EXPRESSION){
    string prefix = operand1->print_prefix();
    if (operand2->node_t == EXPRESSION){
      string prefix2 = operand2->print_prefix();
      prefix = print_operator() + prefix + prefix2;
      return prefix;
    }
  }
  else {
    int i = operand2->data.val;
    char d = (i+'0');
    stringstream ss,dd,cc;
    string target,target1,target2;
  
    ss << d;
    ss >> target;
    dd << (print_operator());
    dd >> target1;
    if (operand1->node_t == VARIABLE){
      cc << (operand1->get_char());
      cc >> target2;
    }
    else if (operand1->node_t == INTEGER){
      cc << (operand1->get_int());
      cc >> target2;
    }
    
    string node = target1 + target2 + target;
    return node;
  }
}
  
string Node::print_postfix() const {
  if (operand1->node_t == EXPRESSION){
    string postfix = operand1->print_postfix();
    if (operand2->node_t == EXPRESSION){
      string postfix2 = operand2->print_postfix();
      postfix =  postfix + postfix2 + print_operator();
      return postfix;
    }
  }
  else {
    int i = operand2->data.val;
    char d = (i+'0');
    stringstream ss,dd,cc;
    string target,target1,target2;
  
    ss << d;
    ss >> target;
    dd << (print_operator());
    dd >> target1;
    if (operand1->node_t == VARIABLE){
      cc << (operand1->get_char());
      cc >> target2;
    }
    else if (operand1->node_t == INTEGER){
      cc << (operand1->get_int());
      cc >> target2;
    }
    
    string node = target2 + target + target1;
    return node;
  }
}
  
#endif
