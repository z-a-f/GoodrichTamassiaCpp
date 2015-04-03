#ifndef _SKIP_LIST_NODE_HPP_
#define _SKIP_LIST_NODE_HPP_

template<class T>
class SkipListNode {
public:
  SkipListNode();
  SkipListNode(const T& item);
  T data;
  // access to the other nodes
  SkipListNode<T>* top() { return _top; }
  SkipListNode<T>* bottom() { return _bottom; }
  SkipListNode<T>* left() { return _left; }
  SkipListNode<T>* right() { return _right; }
private:
  SkipListNode<T>* _top;
  SkipListNode<T>* _bottom;
  SkipListNode<T>* _left;
  SkipListNode<T>* _right;
};

#endif
