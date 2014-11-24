#ifndef P_7_1_HPP
#define P_7_1_HPP

#include "tree.hpp"

#endif


#include <iostream>

using namespace std;


int main() {
  // Test if tree works:
  LinkedBinaryTree lbt;
  cout << lbt.empty() << endl;
  lbt.addRoot();
  lbt.addRoot();
  cout << lbt.empty() << endl;
  cout << lbt.size() << endl;
  lbt.expandExternal(lbt.root());
  cout << lbt.empty() << endl;
  cout << lbt.size() << endl;
}
