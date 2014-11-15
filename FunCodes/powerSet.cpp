#include <iostream>
#include <set>
#include <vector>

using namespace std;

/* THIS IS JUST FOR CONVENIENCE */
template <typename T>
using PS = set<set<T> >;	// Now PS is the datatype for double set

/* ALGO
powerset(string) {
  1. add string to set;
  2. for each char in string {
  3.  let substring = string excluding char,
  4.  add powerset(substring) to set
     }
  5. return set;      
}
*/

// Just to merge two sets:
template <typename T>
PS<T> merge (PS<T> S0, PS<T> S1) {
  for (typename PS<T>::iterator it = S1.begin(); it != S1.end(); ++it) {
    S0.insert(*it);
  }
  return S0;
}

// Algo implementation:
template <typename T>
PS<T> powerSet (set<T> I) {
  PS<T> temp;
  set<T> I2;
  // 1:
  temp.insert(I);
  // 2:
  for (typename set<T>::iterator it = I.begin(); it != I.end(); ++it) {
    // 3: I2 is the substring
    I2 = I;
    I2.erase(I2.find(*it));
    // 4:
    temp = merge(powerSet(I2), temp);
  }
  // 5:
  return temp;
}


int main() {
  PS<int> S;			// This is the final set
  set<int> initial;		// Initial set

  /* Populate the set */
  for (int i = 0; i < 3; i++) {
    initial.insert(i);
  }

  /* THIS IS THE ALGO TESTING*/
  S = powerSet(initial);

  // Another test:
  PS<char> C;
  set<char> initialC;
  for (char i = 'a'; i < 'e'; i++) {
    initialC.insert(i);
  }
  C = powerSet(initialC);
 
  

  /* THESE ARE JUST FOR PRINTING */
  // Print results:
  cout << "Set: [ ";
  for (set<int>::iterator i = initial.begin(); i != initial.end(); ++i) {
    cout << *i << ' ';
  }
  cout << ']' << endl;

  cout << "Power set: [ ";
  for (PS<int>::iterator i = S.begin(); i != S.end(); ++i) {
    cout << "( ";
    for (set<int>::iterator j = i->begin(); j != i->end(); ++j) {
      cout << *j << ' ';
    }
    cout << ") ";
  }
  cout << ']' << endl;


  // Print results:
  cout << "Set: [ ";
  for (set<char>::iterator i = initialC.begin(); i != initialC.end(); ++i) {
    cout << *i << ' ';
  }
  cout << ']' << endl;

  cout << "Power set: [ ";
  for (PS<char>::iterator i = C.begin(); i != C.end(); ++i) {
    cout << "( ";
    for (set<char>::iterator j = i->begin(); j != i->end(); ++j) {
      cout << *j << ' ';
    }
    cout << ") ";
  }
  cout << ']' << endl;

}
