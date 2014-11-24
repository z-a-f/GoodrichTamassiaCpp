#include <iostream>

#include "linkedTree.hpp"
// #include "Position.hpp"

using namespace std;

int main() {
  /*
  Position<int> p(5);
  cout << *p << endl;
  *p = 3;
  cout << *p << endl;

  Position<int> r(&p, 2);
  cout << *r <<endl;
  */
  LinkedBinaryTree<int> lbt;
  cout << lbt.empty() << endl;
  // lbt.expandExternal(lbt.root());
  cout << lbt.empty() << endl;

  lbt.addRoot();

  lbt.expandExternal(lbt.root());
  cout << lbt.empty() << endl;
}
