#include <iostream>
#include <vector>

#include "./exceptions.hpp"
#include "./projects.hpp"

using namespace std;


int main() {
  ArrayVector<int> A(3);
  cout << A << endl;
  A.insertFront(20);
  A.debug();
  cout << A << endl;
  A.insertFront(10);
  A.debug();
  cout << A << endl;
  A.insertFront(1);
  A.debug();
  cout << A << endl;
  A.insertFront(-10);
  A.debug();
  cout << A << endl;
  A.insertFront(-20);
  A.debug();
  cout << A << endl;
  A.insertFront(-30);
  A.debug();
  cout << A << endl;
  A.insertFront(-40);
  A.debug();
  cout << A << endl;

  A.insertBack(30);
  A.debug();
  cout << A << endl;
  
  A.insertFront(-50);
  A.debug();
  cout << A << endl;
  
}
