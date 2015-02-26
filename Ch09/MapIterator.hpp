#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

template <typename Elem>
class Iterator {
public:
  Elem& operator*();
  bool operator==(const Iterator& p) const;
  bool operator!=(const Iterator& p) const;
  Iterator& operator++();
  Iterator& operator--();
  // Friend class here:
private:
  Iterator(/*Node name*/*u);
  /*Node name*/* v;
  
}

#endif
