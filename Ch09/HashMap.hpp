/************************************************************
 * @file HashMap.hpp
 * @author Zafar Takhirov
 * @date Feb. 28, 2015
 *
 * @brief This file contains description of the Hash Map using separate chaining.
 *
 * This file contains hash map ADT using separate chaining.
 * It contains full working example from the book by
 * Goodrich and Tamassia "Data Structures and Algorithms
 * in C++.
 ***********************************************************/

#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <list>
#include <vector>

#include "MapEntry.hpp"

/**
 * HashMap class with separate chaining.
 * The hash map is templated with 3 parameters:
 * @param K Key data type
 * @param V Value data type
 * @param H Hash comparator
 */
template <typename K, typename V, typename H>
class HashMap {
public:
  typedef Entry<K,V> Entry;	//!< @typedef key-value pair entry
  /** Iterator/Position class */
  class Iterator;		
public:
  HashMap (		     
    int capacity = 100		//!< Initial capacity of the hash map.
  );				//!< Default constructor
  int size() const;		//!< Number of entries @returns Integer
  bool empty() const;		//!< Check if empty @returns Boolean
  Iterator find(const K& k);	//!< Find key @param k Key to be found @retval Iterator Position of the found key
  Iterator put(
	       const K& k,	//!< @param[in] Key to be added
	       const V& v	//!< @param[in] Value to be added
	       );		//!< Add/Replace key-value pair @retval Iterator Position of the added/replaced pair 
  void erase(const K& k /**< [in] Key to be removed */ );	//!< Remove usign key
  void erase(const Iterator& p /**< [in] Position to be removed */);  //!< Remove using position iterator
  Iterator begin();		//!< First position @retval Iterator Position of the first entry
  Iterator end();		//!< End position @retval Iterator Position after the last entry
protected:
  /**
   * @typedef std::list<Entry>
   * @typedef std::vector<Bucket>
   */
  typedef std::list<Entry> Bucket;      //!< Bucket of entries
  typedef std::vector<Bucket> BktArray; //!< Bucket array
protected:
  Iterator finder(const K& k /**< [in] Key */);	//!< Find utility @retval Iterator Found position
  Iterator inserter(
    const Iterator& p,		//!< [in] Position to be inserted at
    const Entry& e		//!< [in] Value to be inserted
  );				//!< Insert utility @retval Iterator Position of the value in the hash map
  void eraser(const Iterator& p);	     // erase utility
  /**
   * @typedef typename BktArray::iterator
   * @typedef typename Bucket::iterator
   */
  typedef typename BktArray::iterator BItor; //!< Bucket iterator
  typedef typename Bucket::iterator EItor;   //!< Entry iterator
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
