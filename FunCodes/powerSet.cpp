#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
using PS = vector<vector<T> >;

template <typename T>
PS<T> powerSet(set<T> I) {
  vector<T> V;
  PS<T> S;
  T pullOut;

  if (I.empty()) {
    S.push_back(V);
  } else {
    pullOut = *(I.begin());
    I.erase(I.begin());
    S = powerSet(I);
    cout << PS<T>.size() << endl;
    for (typename PS<T>::iterator i = S.begin(); i != S.end(); ++i) {
      // Add pullout to all elements of the PS
      i->push_back(pullOut);
    }
   
  }
  return S;
}

int main() {
  PS<int> S;			// This is the final set
  set<int> initial;		// Initial set

  // Populate the set:
  for (int i = 0; i < 3; i++) {
    initial.insert(i);
  }

  S = powerSet(initial);

  // Print results:
  cout << "Set: [ ";
  for (set<int>::iterator i = initial.begin(); i != initial.end(); ++i) {
    cout << *i << ' ';
  }
  cout << ']' << endl;

  cout << "Power set: [ ";
  for (PS<int>::iterator i = S.begin(); i != S.end(); ++i) {
    cout << "(";
    for (vector<int>::iterator j = i->begin(); j != i->end(); ++j) {
      cout << *j << ' ';
    }
    cout << ") ";
  }
  cout << ']' << endl;
}
