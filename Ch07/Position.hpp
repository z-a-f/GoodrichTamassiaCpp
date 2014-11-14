#ifndef POSITION_HPP
#define POSITION_HPP

template <typename T>
class Position {
public:
  Position() : p(NULL), l(NULL), r(NULL), value(0) {};
  Position(T v) : p(NULL), l(NULL), r(NULL), value(v) {};
  Position(Position<T>* par): p(par), l(NULL), r(NULL), value(0) {};
  Position(Position<T>* par, T v): p(par), l(NULL), r(NULL), value(v) {};
  Position(Position<T>* lef, Position<T>* rig): p(NULL), l(lef), r(rig), value(0) {};
  Position(Position<T>* lef, Position<T>* rig, T v): p(NULL), l(lef), r(rig), value(v) {};
  Position(Position<T>* par, Position<T>* lef, Position<T>* rig, T v): p(par), l(lef), r(rig), value(v) {};
  
public:
  T& operator*();
  Position<T>* left();
  Position<T>* right();
  Position<T>* parent();
  bool isRoot() const;
  bool isExternal() const;

private:
  Position<T>* p;
  Position<T>* l;
  Position<T>* r;
  T value;
};

template <typename T>
T& Position<T>::operator*() {
  return value;
}

template <typename T>
Position<T>* Position<T>::left() {
  return l;
}

template <typename T>
Position<T>* Position<T>::right() {
  return r;
}

template <typename T>
Position<T>* Position<T>::parent() {
  return p;
}

template <typename T>
bool Position<T>::isRoot() const {
  return parent() == NULL;
}

template <typename T>
bool Position<T>::isExternal() const {
  return (left() == NULL && right() == NULL);
}
 

#endif
