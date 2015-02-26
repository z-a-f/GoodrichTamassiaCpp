#ifndef MAP_ENTRY_HPP
#define MAP_ENTRY_HPP

template <typename K, typename V> // key and value types
class Entry {			  // a (key, value) pair 
public:				  // public functions 
  Entry(const K& k = K(), const V& v = V()) : // Constructor
    key(k), value(v) { }
  const K& key() const { return key; } // get key
  const V& value() const { return value; } // get value
  void setKey(const K& k) { key = k; }	   // set key
  void setValue(const V& v) { value = v; } // set value
private:				   // private data
  K key;				   // key
  V value;				   // value
}
  
#endif
