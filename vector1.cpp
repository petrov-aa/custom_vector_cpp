
template <class T> class Vector
{

private:

  T* arr;  // pointer to the first element of this Vector
  int capacity; // number of elements arr can hold (i.e. size of underlying array)
  unsigned n;        // size of this Vector

  void increase_capacity(int sz) {
    if (sz <= capacity) return;

    T* new_arr = new T[sz];   // allocate a new array on the free store

    for(int i = 0; i < capacity; ++i) { // copy old vector into new one
      new_arr[i] = arr[i];
    }
    capacity = sz;                      // set the new capacity

    delete[] arr;                       // delete the old vector
    arr = new_arr;
  }

public:

  Vector() : capacity(10), n(0) {
    arr = new T[capacity];
  }

  int size() const {
    return n;
  }

  void push_back(T x) {
    if (n >= capacity) increase_capacity(2 * capacity);
    arr[n] = x;
    ++n;
  }

  void pop_back()
  {
    n--;
  }

  void set(int i, T val) {
    if (i < 0 || i >= n) throw "range error";
    arr[i] = val;
  }

  T get(int i) {
    if (i < 0 || i >= n) throw "range error";
    return arr[i];
  }

  T& operator[](int i) {
    if (i < 0 || i >= n) throw "range error";
    return arr[i];
  }

  // const T& operator[](int i) const {
  //   if (i < 0 || i >= n) throw "range error";
  //   return arr[i];
  // }

  void insert(T x, int i) {
    if (i < 0 || i > n) throw "range error";  // x can be inserted at location n,
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

  ~Vector() {       // destructor
    delete[] arr;
  }

  bool operator==(Vector &b) {
    if (n != b.size()) {
      return false;
    }
    for (int i = 0; i < b.size(); i++) {
      if (arr[i] != b[i]) {
        return false;
      }
    }
    return true;
  }

};
