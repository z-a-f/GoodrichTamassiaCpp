/**
 * @file HashMap.hpp
 * @author Zafar Takhirov
 * @date Feb. 28, 2015
 *
 * @brief This file contains description of the Hash Map using separate chaining
 *
 * This file contains hash map ADT using separate chaining.
 * It contains full working example from the book by
 * Goodrich and Tamassia "Data Structures and Algorithms
 * in C++.
 */

#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <list>
#include <vector>

#include "MapEntry.hpp"

/**
 * @brief HashMap class with separate chaining
 *
 * The hash map is templated with 3 parameters:
 * @param K Key data type
 * @param V Value data type
 * @param H Hash comparator
 */
template <typename K, typename V, typename H>
class HashMap {
public:
  /** @typedef key-value pair entry */
  typedef Entry<K,V> Entry;
  /** @brief iterator/position class */
  class Iterator;
public:
  /** @brief Default constructor sets the capacity of the map 
   * @param capacity Sets the capacity of the hash map
   */
  HashMap(int capacity = 100);
  /** @brief Number of entries 
   * @return int
   */
  int size() const;
  /** @brief Check if the map is empty
   * @return bool
   */
  bool empty() const;
  /** @brief Find key
   * @param k Key of type 'const K&'
   * @return bool
   */
  Iterator find(const K& k);
  /** @brief Add/Replace key-value pair
   * @param k Key to be added
   * @param v Value to be added
   * @retval Iterator Position of the added/replaced pair
   */
  Iterator put(const K& k, const V& v);
  /** @brief Remove using key
   * @param k Key to be found and removed
   */
  void erase(const K& k);		// Remove key 'k'
  /** @brief Remove using Iterator
   * @param p Iterator/position to be removed
   */
  void erase(const Iterator& p);
  /** @brief First position
   * @retval Iterator Position of the first entry
   */
  Iterator begin();
  /** @brief End position
   * @retval Iterator Position after the last entry
   */
  Iterator end();
protected:
  /** @typedef Bucket of entries */
  typedef std::list<Entry> Bucket;
  /** @typedef Bucket array */
  typedef std::vector<Bucket> BktArray;
protected:
  /** @brief Find utility
   * @param k Key to be found
   * @retval Iterator Position of the found entry
   */
  Iterator finder(const K& k);	// find utility
  Iterator inserter(const Iterator& p, const Entry& e);
  void eraser(const Iterator& p);	     // erase utility
  typedef typename BktArray::iterator BItor; // Bucket iterator
  typedef typename Bucket::iterator EItor;   // Entry iterator
  static void nextEntry(Iterator& p)	     // bucket's next entry
  { ++p.ent; }
  static bool endOfBkt(const Iterator& p)    // end of bucket????
  { return p.ent == p.bkt->end(); }
private:
  int n;			// Number of entries
  H hash;			// the hash comparator;
  BktArray B;			// bucket array
public:				// TYPES:
  class Iterator {
  private:
    EItor ent;			// which entry
    BItor bkt;			// which bucket
    const BktArray* ba;		// which bucket array
  public:
    Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
      : ent(q), bkt(b), ba(&a) { }
    Entry& operator*() const;		      // get entry
    Entry& operator*();			      // get entry
    bool operator==(const Iterator& p) const; // are iterators equal?
    Iterator& operator++();		      // next iterator
    Iterator& operator--();		      // previous iterator
    friend class HashMap;
  };
};

// Iterator methods:
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() const {
  return *ent;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() {
  return *ent;
}

template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const {
  if (ba != p.ba || bkt != p.bkt) return false;
  else if (bkt == ba->end()) return true;
  else return ent == p.ent;
}

template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Iterator&
HashMap<K,V,H>::Iterator::operator++() {
  ++ent;			// Advance to the next entry in the bucket
  if (endOfBkt(*this)) {	// Is it the end of bucket?
    ++bkt;			// Go to next bucket
    while (bkt != ba->end() && bkt->empty) ++bkt; // find non-empty bucket
    if (bkt == ba->end()) return *this;		  // If the end of bucket array
    ent = bkt.begin();				  // first non empty bucket
  }
  return *this;  
}

#endif
