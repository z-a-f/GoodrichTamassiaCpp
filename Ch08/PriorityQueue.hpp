#ifndef PRIORITY_QUEUE_ADT
#define PRIORITY_QUEUE_ADT

#include <list>

template <typename E, typename C> // element and comparator
class PriorityQueueADT {
public:
  int size() const;
  bool isEmpty() const;
  void insert (const E& e);
  const E& min() const throw(QueueEmpty);		// Minimum element
  void removeMin() throw(QueueEmpty);
  
  /*
    private:
    std::list<E> L;
    C isLess;
  */
};

#endif
