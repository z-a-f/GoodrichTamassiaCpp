#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <vector>

#include "progression.hpp"

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


// C-2.5
class AbsProgression : public Progression {
public:
	AbsProgression(long f = 2, long s = 200);
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	long second;
	long prev;
};

AbsProgression::AbsProgression(long f, long s)
	: Progression(f), second(s), prev(abs(second + first)) {}

long AbsProgression::firstValue() {
	cur = first;
	prev = abs(second + first);
	return cur;
}

long AbsProgression::nextValue() {
	long temp = prev;
	prev = cur;
	cur = abs(cur - temp);
	return cur;
}

void C_2_5 () {
	Progression * prog;
	cout << "Absolute difference progression with default start:\n";
	prog = new AbsProgression();
	prog->printProgression(10);
}

// C-2.6
class SqrtProgression : public Progression {
public:
	SqrtProgression(double f = 65536) : first(f), cur(f) {}
protected:
	virtual long firstValue();
	virtual long nextValue();
protected:
	double first;
	double cur;
};

long SqrtProgression::firstValue() {
	cur = first;
	return long(cur);
}

long SqrtProgression::nextValue() {
	cur = sqrt(cur);
	return long(cur);
}

void C_2_6() {
	Progression * prog;
	cout << "Absolute difference progression with default start:\n";
	prog = new SqrtProgression(129);
	prog->printProgression(10);
}

// C-2.7
class A {
public:
	A(long X = 0) : x(X) {}
	long getX() {
		return this->x;
	}
	void setX(long x) {
		this->x = x;
	}
	virtual long getParentX() {return x;}
	virtual void setParentX(long x) {this->x = x;}
protected:
	long x;
};


class B : public A {
public:
	B(long X = 0) : x(X) {}
	long getX() {
		return this->x;
	}
	void setX(long x) {
		this->x = x;
	}
	virtual long getParentX() {
		return A::getX();
	}
	virtual void setParentX(long x) {
		A::setX(x);
	}
protected:
	long x;
};


class C : public B {
public:
	C(long X = 0) : x(X) {}
	long getX() {
		return this->x;
	}
	void setX(long x) {
		this->x = x;
	}
	virtual long getParentX() {
		return B::getX();
	}
	virtual void setParentX(long x) {
		B::setX(x);
	}
	void setGrandParentX(long x) {
		A::setX(x);
	}
protected:
	long x;
};

void C_2_7() {
	C *obj = new C(3);
	obj->setParentX(2);
	obj->setGrandParentX(1);

	cout << obj->getX() << endl;
	cout << obj->getParentX() << endl;
	cout << obj->B::getParentX() << endl;

	obj->A::setX(100);
	cout << obj->A::getX() << endl;
	cout << obj->B::getX() << endl;
	cout << obj->getX() << endl;
	
}


int main() {
	srand (time(NULL));
	cout << "*****************C-2.1*****************\n";
	C_2_1();
	cout << "*****************C-2.3*****************\n";
	C_2_3();
	cout << "*****************C-2.4*****************\n";
	C_2_4();
	cout << "*****************C-2.5*****************\n";
	C_2_5();
	cout << "*****************C-2.6*****************\n";
	C_2_6();
	cout << "*****************C-2.7*****************\n";
	C_2_7();
}




