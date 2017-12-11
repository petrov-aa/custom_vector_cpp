#ifndef VECTOR_H
#define VECTOR_H

template <class T> class Vector
{
  private:
  T* arr;  // pointer to the first element of this Vector
  int capacity; // number of elements arr can hold (i.e. size of underlying array)
  int n;        // size of this Vector
  void increase_capacity(int sz);

  public:

  // create an empty vector
  Vector();
  int size() const;
  void push_back(T x);
  void set(int i, T val);
  T get(int i);
  T& operator[](int i);
  const T& operator[](int i) const;
  void insert(T x, int i);
  ~Vector();

};

#endif
