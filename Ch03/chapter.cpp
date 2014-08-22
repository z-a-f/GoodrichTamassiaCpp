
#include <iostream>
#include <new>
#include <typeinfo>
using namespace std;

/****************************************************************
 * Exceptions
 ****************************************************************/
class RuntimeException {
private:
  string errorMsg;
public:
  RuntimeException(const string& err) { errorMsg = err; }
  string getMessage() const { return errorMsg; }
};

class IndexOutOfBounds : public RuntimeException {
public:
  IndexOutOfBounds(const string& err = "Index out of bounds!")
    : RuntimeException(err) {}
};

/****************************************************************
 * Chapter 3.1 - Game Entries
 *
 ****************************************************************/
// Game entry data structure:
class GameEntry {		// Stores the game scores
public:
  GameEntry(const string& n = "", int s = 0); // Constructor
  string getName() const;		      // Get player name
  int getScore() const;			      // Get player score
private:
  string name;			// Player's name
  int score;			// Player's score
};
// Definitions for Game entry
GameEntry::GameEntry(const string& n, int s)
  : name(n), score(s) {}
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

ostream& operator<<(ostream& out, const GameEntry& obj) {
  out << '{' << obj.getName() << ',' << obj.getScore() << '}';
  return out;
}

// Scores data structure
class Scores {
public:
  Scores(int maxEnt = 10);	// Constructor
  ~Scores();			// Destructor
  void add (const GameEntry& e); // add an entry
  GameEntry remove(int i)	 // Remove a single entry
    throw (IndexOutOfBounds);
  // Operators:
  GameEntry& operator[](size_t i) {
    return entries[i];
  };	// Access to game entries
  friend ostream& operator<<(ostream& out, const Scores& obj);
private:
  int maxEntries;		// maximum number of entries
  int numEntries;		// actual number of entries
  GameEntry* entries;		// array of game entries
};
// Definitions for Scores
Scores::Scores(int maxEnt) {
  maxEntries = maxEnt;
  entries = new GameEntry[maxEnt];
  numEntries = 0;
}
Scores::~Scores() {
  delete [] entries;
}
void Scores::add(const GameEntry& e) { // Add a game entry
  int newScore = e.getScore();	       // Score to add
  if (numEntries == maxEntries){       // The array is full
    if (newScore <= entries[maxEntries-1].getScore())
      return;			// not high enough
  }
  else
    numEntries++;

  int i = numEntries - 2;	// Start with the next to last
  while (i >= 0 && newScore > entries[i].getScore()) {
    entries[i+1] = entries[i];
    i--;
  }
  entries[i+1] = e;
}
/*
GameEntry& Scores::operator[](size_t i) const{ 
  // cout << typeid(entries).name() << endl;
  return (*this).entries[i]; 
}
*/
ostream& operator<<(ostream& out, const Scores& obj){
  for (int i = 0; i < obj.numEntries; i++) {
    out << obj.entries[i] << ' ';
  }
  return out;
}


int main() {
  GameEntry *e0 = new GameEntry("Zafar", 10);
  GameEntry *e1 = new GameEntry("Zafa", 11);

  // Scores *s = new Scores(5);
  Scores s(5);
  s.add(*e0);
  s.add(*e1);
  // cout << *s << endl;
  cout << typeid(s[0]).name() << endl;
  cout << s[0] << endl;
}
