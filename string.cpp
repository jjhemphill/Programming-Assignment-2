#ifndef STRING_CPP
#define STRING_CPP

#include <iostream>
#include <string>
#include "string.h"
using namespace std;

int prompt(){
  int x;
  cout << "Enter 1 for Expression Evaluation, 2 for Expression Comparison, 3 to Exit: " << endl;
  cin.ignore();
  cin >> x;
  return x;
}
  

int E_or_C(int x){
  
  string s, temp;
  
  if (x == 1){
    cout << "Enter infix expression: ";
    cin.ignore();
    std::getline(cin, s);
    Node* head = makeTree(s);
    Expression ex = Expression(head);
    return ex.Evaluate();
  }
  else if (x == 2){
    cout << "Enter two infix expressions separated by a comma: ";
    cin.ignore();
    std::getline(cin, temp);
    int i = 0;
    string s, s2;
    while (temp[i] != ','){
      s += temp[i];
      i++;
    }
    Node* head = makeTree(s);
    Expression ex = Expression(head);
    i++;
    while (i != temp.size()){
      s2 += temp[i];
      i++;
    }
    head = makeTree(s2);
    Expression ex2 = Expression(head);
    return ex.Compare(ex2);
  }
}

int main(){
  int x = 0;
  cout << "Enter 1 for Expression Evaluation, 2 for Expression Comparison: ";
  cin >> x;
  
  E_or_C(x);
  int xx = prompt();
  while (xx != 3){
    E_or_C(xx);
    xx = prompt();
    if (xx == 3)
      break;
  }
  return 0;
}

#endif
