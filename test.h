#include <iostream>
using namespace std;

class box{
 public:
  box(int a = 0) {x=a;}
  box(int a = 1, int b = 1){x=a;y=b;}
  getX(){return x;}
  getY(){return y;}
 private:
  int x;
  int y;
};
