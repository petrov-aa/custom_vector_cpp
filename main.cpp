#include <iostream>

#include "vector.cpp"

using namespace std;

int main() {

  {
    std::cout << "Test:" << '\n';

    Vector<double> a, b;

    a.push_back(1.1);
    a.push_back(2.2);
    a.push_back(3.3);

    cout << a[0] << endl; // >> 1.1
    cout << a[1] << endl; // >> 2.2
    cout << a[2] << endl; // >> 3.3

    a[2] = 5.5;

    cout << a[2] << endl; // >> 5.5
  }

  {
    cout << endl;
    cout << "Test of == operator:" << endl;

    Vector<double> a, b;

    a.push_back(1.1);
    b.push_back(1.1);
    cout << (a == b) << endl; // >>  1

    b.push_back(2.2);
    cout << (a == b)  << endl; // >> 0
  }

  {
    cout << endl;
    cout << "Test of iterator:" << endl;

    Vector<int> a;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    for (Vector<int>::Iterator it = a.begin(); it != a.end(); it++) {
      cout << *it << endl; // >> 1, 2, 3, 4, 5
    }

  }

  return 0;
}
