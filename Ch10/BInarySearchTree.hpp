#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

/** Node element. The tree will be templated to this element. */
template <typename K, typename V> // Key and Value types
class Entry {
public:							// Just to keep everything standard
  typedef K Key;
  typedef V Value;
public:
  /** Default constructor */
  Entry (const K& k = K(), const V& v = V())
	: _key(k), _value(v) {}
  const K& key() { return _key; } /**< Key getter @returns K(key) */
  const V& value() { return _value; } /**< Value getter @returns V(value) */
  void key(const K& k) { _key = k; } /**< Key setter \param[in] K(key) */
  void value(const V& v) { _value = v; } /**< Value setter \param[in] V(value)*/
};

#endif
