#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

template <typename T>
void swap (T *A, T *B) {
	T temp = *A;
	*A = *B;
	*B = temp;
}

template <typename T>
void printArray (T ar[], int len) {
	for (int i = 0; i < len; i++) {
		cout << ar[i] << '\t';
	}
	cout << endl;
}

template <typename T>
void printVector (vector<T> v) {
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << '\t';
	}
	cout << endl;
}

class RuntimeException { // generic run-time exception 
private:
	string errorMsg; 
public:
	RuntimeException(const string& err = "Unknown Error!") { errorMsg = err; }
	string getMessage() const { return errorMsg; } 
};

class ParallelException : public RuntimeException {
public:
	ParallelException(const string& err) : RuntimeException(err) {}
};

// C-2.1
void C_2_1 () {
	cout << "// C-2.1\n \
void C_2_1 () {\n \
	cout << \"This program only outputs itself without the headers and stuff\";\n \
	cout << endl;\n \
}";
	cout << endl;
}

// C-2.3
void C_2_3 () {
	if (rand() % 100 > 100) {
		cout << "This is the part that might have something \"Useful\"";
	}
}

// C-2.4
class Line {
public:
	Line(double A = 1.0, double B = 0.0) : a(A), b(B) {}
	~Line() {};
	double intersect (const Line& l);
	void printParams();
public: // Easier access for now
	double a;
	double b;
};

void Line::printParams() {
	cout << a << ',' << b;
}

bool isParallel(Line A, Line B) {
	if (A.a == B.a) {
		throw ParallelException("Lines are parallel!");
		return true;
	} else {
		return false;
	}
}

double findXIntersect(Line A, Line B) {
	return ((B.b - A.b) / (A.a - B.a));
}

double Line::intersect(const Line& l) {
	try {
		if (!isParallel(*this, l))
			return findXIntersect(*this, l);
	} catch (ParallelException& pe) {
		cout << pe.getMessage() << endl;
	} catch (RuntimeException& re) {
		cout << re.getMessage() << endl;
	}
	return 0;
}

void C_2_4() {
	Line *lineA = new Line(2.1, 3.1);
	Line *lineB = new Line (2.1, 4.0);
	Line *lineC = new Line (1, 0);
	cout << '(';
	lineA->printParams(); cout << '+';
	lineB->printParams(); cout << ')';
	cout << ':';
	cout << lineA->intersect(*lineB) << endl;
	cout << '(';
	lineB->printParams(); cout << '+';
	lineC->printParams(); cout << ')';
	cout << ':';
	cout << lineB->intersect(*lineC) << endl;
	cout << '(';
	lineC->printParams(); cout << '+';
	lineA->printParams(); cout << ')';
	cout << ':';
	cout << lineC->intersect(*lineA) << endl;
}



int main() {
	srand (time(NULL));
	cout << "*****************C-2.1*****************\n";
	C_2_1();
	cout << "*****************C-2.3*****************\n";
	C_2_3();
	cout << "*****************C-2.4*****************\n";
	C_2_4();

}




