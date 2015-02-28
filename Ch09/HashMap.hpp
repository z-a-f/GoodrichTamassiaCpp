/*
 * Hash Map 
 * Separate Chaining
 */

#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <list>
#include <vector>

#include "MapEntry.hpp"

template <typename K, typename V, typename H> // <key, value, hash comparator>
class HashMap {
public:				// TYPES:
  typedef Entry<K,V> Entry;	// key-value pair
  class Iterator;		// iterator/position
public:				// METHODS:
  HashMap(int capacity = 100);	// Default constructor
  int size() const;		// Number of entries
  bool empty() const;		// is the map empty?
  Iterator find(const K& k);	// find key 'k'
  Iterator put(const K& k, const V& v); // Add/Replace 'k'-'v' pair
  void erase(const K& k);		// Remove key 'k'
  void erase(const Iterator& p);	// Remove position 'p'
  Iterator begin();			// First position
  Iterator end();			// Last positon
protected:				// TYPES:
  typedef std::list<Entry> Bucket;	// a bucket of entries
  typedef std::vector<Bucket> BktArray; // a bucket array
protected:				// HASHMAP UTILITIES:
  Iterator finder();			// find utility
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
  class Itertor {
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
