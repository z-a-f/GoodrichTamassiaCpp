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
	       const K& k,	//!< [in] Key to be added
	       const V& v	//!< [in] Value to be added
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
  void eraser(const Iterator& p /**< [in] Position */); //!< Eraser utility
  /**
   * @typedef typename BktArray::iterator
   * @typedef typename Bucket::iterator
   */
  typedef typename BktArray::iterator BItor; //!< Bucket iterator
  typedef typename Bucket::iterator EItor;   //!< Entry iterator
  static void nextEntry(Iterator& p	/**< [in] Current position */)
  { ++p.ent; }				//!< Bucket's next entry
  static bool endOfBkt(const Iterator& p /**< [in] Current position */)
  { return p.ent == p.bkt->end(); }	 //!< end of bucket????
private:
  int n;			//!< @var Number of entries
  H hash;			//!< @var the hash comparator;
  BktArray B;			//!< @var bucket array
public:
  /** Iterator class identifies the position of an entry in a HashMap. */
  class Iterator {
  private:
    EItor ent;			//!< @var which entry
    BItor bkt;			//!< @var which bucket
    const BktArray* ba;		//!< @var which bucket array
  public:
    /** Default Iterator constructor.
     * @param a Bucket array
     * @param b Bucket itself
     * @param q Current entry, defaults to Entry iterator
     */
    Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
      : ent(q), bkt(b), ba(&a) { }
    Entry& operator*() const;		      
    Entry& operator*();			      
    bool operator==(const Iterator& p) const;
    Iterator& operator++();		      
    friend class HashMap;		      //!< Hash Map has to be a friend class to have access to internals
  };
};

/** Iterator indirection operator (const).
 * @returns Entry
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() const {
  return *ent;
}

/** Iterator indirection operator.
 * @returns Entry
 */
template <typename K, typename V, typename H>
typename HashMap<K,V,H>::Entry&
HashMap<K,V,H>::Iterator::operator*() {
  return *ent;
}

/** Iterator equality operator overloading.
 * @returns Boolean
 */
template <typename K, typename V, typename H>
bool HashMap<K,V,H>::Iterator::operator==(const Iterator& p) const {
  if (ba != p.ba || bkt != p.bkt) return false;
  else if (bkt == ba->end()) return true;
  else return ent == p.ent;
}

/** Iterator position increment operator overloading.
 * @returns Iterator
 */
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
