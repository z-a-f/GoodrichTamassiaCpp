#ifndef MAP_INTERFACE_HPP
#define MAP_INTERFACE_HPP

// #include "MapEntry.hpp"
// #include "MapIterator.hpp"

template <typename K, typename V>
class Map {
public:
  class Entry;
  class Iterator;
  
  int size() const;
  bool empty() const;
  Iterator find(const K& k) const;
  Iterator put(const K& k, const V& v) const;
  void erase (const K& k) throw (NonexistentElement);
  void erase (const Iterator& p);
  Iterator begin();
  Iterator end();
};

tempalate <typename K, typename V>
class Map<K,V>::Entry {
public:
  Entry(const K& k = K(), const V& v = V()): // Constructor
    key(k), value(v) {}
  const K& key() const { return key; } // get key
  const V& value() const { return value; } // get value
  void setKey(const K& k) { key = k; }	   // set key
  void setValue(const V& v) { value = v; } // set value
private:
  K key;
  V value;
};

class Iterator<K,V>::Iterator {
public:
  Map<K,V>::Entry& operator*() {  }
};
  
#endif
  
// map interface
// a (key,value) pair
// an iterator (and position)
// number of entries in the map // is the map empty?
// find entry with key k
// insert/replace pair (k,v)
// remove entry with key k
// erase entry at p
// iterator to first entry // iterator to end entry
