#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T>
using PS = vector<vector<T> >;

// Non recursive:
template <typename T>
PS<T> nrPowerSet(set<T> I) {
  // Max number of combinations:
  unsigned long long num;
  // Get the number of elements in the set:
  size_t elems = I.size();
  // Set the element switches:
  num = 2^elems;
  // Iterate through the elements:
  PS<T> S;
  for (unsigned long long i = 0; i < num; i++) {
    vector<T> temp = vector<T>();
    for (size_t j = 0; j < elems; j++) {
      if ( (1<<(j+1)) ^ i ) {
	temp.push_back(*(I.begin()+j));
      }
    }
    S.push_back(temp);
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

  S = nrPowerSet(initial);

  // Print results:
  cout << "Set: [ ";
  for (set<int>::iterator i = initial.begin(); i != initial.end(); ++i) {
    cout << *i << ' ';
  }
  cout << ']' << endl;

  cout << "Power set: [ ";
  for (PS<int>::iterator i = S.begin(); i != S.end(); ++i) {
    cout << "( ";
    for (vector<int>::iterator j = i->begin(); j != i->end(); ++j) {
      cout << *j << ' ';
    }
    cout << ") ";
  }
  cout << ']' << endl;
}
