#include "vector.h"

template <class T>
void Vector<T>::increase_capacity(int sz) {
  if (sz <= capacity) return;

  T* new_arr = new T[sz];   // allocate a new array on the free store

  for(int i = 0; i < capacity; ++i) { // copy old vector into new one
    new_arr[i] = arr[i];
  }
  capacity = sz;                      // set the new capacity

  delete[] arr;                       // delete the old vector
  arr = new_arr;
}

template <class T>
Vector<T>::Vector() : capacity(10), n(0) {
  arr = new T[capacity];
}

template <class T>
int Vector<T>::size() const {
  return n;
}

template <class T>
void Vector<T>::push_back(T x) {
  if (n >= capacity) increase_capacity(2 * capacity);
  arr[n] = x;
  ++n;
}

template <class T>
void Vector<T>::set(int i, T val) {
  if (i < 0 || i >= n) throw("range error");
  arr[i] = val;
}

template <class T>
T Vector<T>::get(int i) {
  if (i < 0 || i >= n) throw("range error");
  return arr[i];
}

template <class T>
T& Vector<T>::operator[](int i) {
  if (i < 0 || i >= n) throw("range error");
  return arr[i];
}

template <class T>
const T& Vector<T>::operator[](int i) const {
  if (i < 0 || i >= n) throw("range error");
  return arr[i];
}

template <class T>
void Vector<T>::insert(T x, int i) {
  if (i < 0 || i > n) throw("range error");  // x can be inserted at location n,
                                             // i.e. the very end of the vector

  push_back(0); // increase the size of the vector by 1

  // move all elements from i to end of vector up one position; note
  // that we must start at the right end of the vector to do this
  // correctly
  for(int j = n - 1; j > i; --j) {
    arr[j] = arr[j - 1];
  }

  // put x into the vector
  arr[i] = x;
}

template <class T>
Vector<T>::~Vector() {       // destructor
  delete[] arr;
}
