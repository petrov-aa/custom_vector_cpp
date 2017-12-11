#include "vector1.cpp"

#include <iostream>
using namespace std;

int main() {

  Vector<double> a, b;

  // a.push_back(1.1);
  // a.push_back(2.2);
  // a.push_back(3.3);
  //
  // cout << a[0] << endl;
  // cout << a[1] << endl;
  // cout << a[2] << endl;
  //
  // a[2] = 5.5;
  //
  // cout << a[2] << endl;

  a.push_back(1.1);
  b.push_back(1.1);
  cout << (a == b) << endl; // >>  1

  b.push_back(2.2);
  cout << (a == b)  << endl; // >> 0

  return 0;
}
