#ifndef VECTOR_CH06_HPP
#define VECTOR_CH06_HPP

#include <memory>
#include "exceptions.hpp"

/* Chapter 6.1 - GR C++ */
template <typename T> class ArrayVector;
template <typename T> std::ostream& operator<<(std::ostream&, const ArrayVector<T>&);


template <typename T>
class ArrayVector {
public:
  ArrayVector();		// Construct
  ArrayVector(size_t N);
  ArrayVector(const ArrayVector<T>& AV);
  size_t size() const;
  bool empty() const;
  T& operator[](int i);
  T& at(int i) throw (IndexOutOfBounds);
  void reserve(int N);
  void erase(int i);
  void insert(int i, const T& e);
  void insertBack(const T& e);	// Insert in the end
  void insertFront(const T& e);	// Insert in the front
  // housekeeping
  void debug();
public:				// friends
  friend std::ostream& operator<< <T>(std::ostream&, const ArrayVector<T>&);
private:
  size_t capacity;
  size_t n;
  size_t front;
  std::unique_ptr<T[]> A;
};

template <typename T>
ArrayVector<T>::ArrayVector()
  : capacity(0), n(0), front(0) {		// , A(NULL) {}
  A = NULL;
}

template <typename T>
ArrayVector<T>::ArrayVector(size_t N) 
  : capacity(N), n(0), front(0) {
  if (N < 2) N = 2;
  A = std::unique_ptr<T[]>(new T[N]);
}


template <typename T>
ArrayVector<T>::ArrayVector(const ArrayVector<T>& AV) {
  capacity = AV.capacity;
  n = AV.n;
  front = AV.front;
  std::unique_ptr<T[]> B = std::unique_ptr<T[]>(new T[AV.capacity]);
  for (int j = 0; j < AV.n; j++) {
    B[j] = AV.A[j];
  }
  A = std::move(B);
}


template <typename T>
size_t ArrayVector<T>::size() const {
  return n;
}

template <typename T>
bool ArrayVector<T>::empty() const {
  return (size() == 0);
}

template <typename T>
T& ArrayVector<T>::operator[] (int i) {
  return A[i];
}

template <typename T>
T& ArrayVector<T>::at(int i) throw (IndexOutOfBounds) {
  if (i < 0 || i >= size())
    throw IndexOutOfBounds("Illegal index in function at()");
  return A[i];
}

template <typename T>
void ArrayVector<T>::reserve(int N) {
  if (capacity >= N) return;
  std::unique_ptr<T[]> B = std::unique_ptr<T[]>(new  T[N]);
  for (int j = 0; j < n; j++)
    B[j] = A[(j+front) % capacity];
  A = std::move(B);
  capacity = N;
  front = 0;
}

template <typename T>
void ArrayVector<T>::erase(int i) {
  for (int j = i + 1; j < n; j++)
    A[j-1] = A[j];
  n--;
}

template <typename T>
void ArrayVector<T>::insert(int i, const T& e) {
  if (n >= capacity){
    int c = 2*capacity;
    (1 > c) ? reserve(1) : reserve(c);
  }
  for (int j = n - 1; j >= i; j--)
    A[j+1] = A[j];
  A[i] = e;
  n++;
}

template <typename T>
void ArrayVector<T>::insertBack(const T& e) { // Insert in the end
  if (n >= capacity) {
    int c = 2*capacity;
    (1 > c) ? reserve (1) : reserve (c);
  }
  A[(front+n)%capacity] = e;
  n++;
}

template <typename T>
void ArrayVector<T>::insertFront(const T& e) {
  if (n >= capacity) {
    int c = 2*capacity;
    (1 > c) ? reserve (1) : reserve (c);
  }
  if (front == 0) front = capacity - 1;
  else front--;
  A[front] = e;
  n++;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ArrayVector<T>& AV) {
  if (AV.capacity == 0) {
    os << "[ Zero Capacity! ]";
    return os;
  }
  // size_t end = (AV.front + AV.n) % AV.capacity;
  os << "[ ";
  
  for (size_t i = 0; i < AV.n; i++) {
    size_t index = (i+AV.front) % AV.capacity;
    os << index << ":";
    os << AV.A[index] << ' ';
  }
  os << ']';
  return os;
}

template <typename T>
void ArrayVector<T>::debug() {
  std::cout << "[ Capacity: " << capacity << "; ";
  std::cout << "Front: " << front << "; ";
  std::cout << "n: " << n << "; ";
  for (int i = 0; i < capacity; i++) {
    std::cout << A[i] << ' ';
  }
  std::cout << "]" << std::endl;
}

#endif
