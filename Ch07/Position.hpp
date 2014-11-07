#ifndef POSITION_HPP
#define POSITION_HPP

/*
 * An informal interface for a position in a tree
 */

template <typename T>
class Position <E> {
public:
  E& operator*();		 // Get element
  PositionList children() const; // get the node children
  bool isRoot() const;		 // root?
  bool isExternal() const;	 // external node?
}


#endif
