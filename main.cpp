#include "vector.cpp"

#include <iostream>
using namespace std;

int main() {

  Vector<double> a;

  a.push_back(1.1);
  a.push_back(2.2);
  a.push_back(3.3);

  cout << a[0] << endl;
  cout << a[1] << endl;
  cout << a[2] << endl;

  return 0;
}
