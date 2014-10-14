#include <iostream>
#include <vector>

#include "./exceptions.hpp"
#include "./projects.hpp"

using namespace std;


int main() {
  ArrayVector<int> A;
  cout << A << endl;
  A.insertFront(10);
  cout << A << endl;
  A.insertFront(6);
  cout << A << endl;
}
