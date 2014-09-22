#include <cmath>
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

template <typename T>
void swap (T *a, T *b) {
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

template <typename T>
void print(T ar[], size_t n) {
	for (size_t i = 0; i < n; i++) {
		cout << ar[i] << ' ';
	}
	cout << endl;
}

// R-6.1
template <typename T>
void reverseArray(T *ar, size_t n) {
	size_t half = floor(n/2);
	for (size_t i = 0; i < half; i++) {
		swap(ar[i], ar[n-i-1]);
	}
}

void R_6_1() {
	size_t len;

	cout << "Test ODD array:\n";
	len = 9;
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print<int>(A, len);
	reverseArray<int>(A, len);
	print<int>(A, len);
	
	cout << "Test EVEN array:\n";
	len = 10;
	int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print<int>(B, len);
	reverseArray<int>(B, len);
	print<int>(B, len);

	cout << "Test EMPTY array\n";
	len = 0;
	int C[] = {};
	print<int>(C, len);
	reverseArray<int>(C, len);
	print<int>(C, len);
}

// R-6.2
template <typename T>
void permuteArray(T *ar, size_t n) {
	for (size_t i = 0; i < n; i++) {
		swap(ar[i], ar[rand() % (n - i) + i]);
	}
}

void R_6_2() {
	size_t len;

	cout << "Test ODD array:\n";
	len = 9;
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print<int>(A, len);
	permuteArray<int>(A, len);
	print<int>(A, len);
	
	cout << "Test EVEN array:\n";
	len = 10;
	int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print<int>(B, len);
	permuteArray<int>(B, len);
	print<int>(B, len);

	cout << "Test EMPTY array\n";
	len = 0;
	int C[] = {};
	print<int>(C, len);
	permuteArray<int>(C, len);
	print<int>(C, len);
}

// R-6.3
template <typename T>
void rotateArray(T *ar, int d, size_t n) {
	T temp[n];
	if (d > 0) {
		for (size_t i = 0; i < d; i++) {
			temp[i] = ar[n-d+i];
		}
		for (size_t i = 0; i < n-d; i++) {
			temp[i+d] = ar[i];
		}
	} else if (d < 0) {
		for (size_t i = 0; i < n-d; i++) {
			temp[i] = ar[i-d];	// Note that d<0
		}
		for (size_t i = 0; i < d; i++) {
			temp[i+n-d] = ar[i+n-d];
		}
	} else return;
}

void R_6_3 () {
	size_t len;

	cout << "Test ODD array:\n";
	len = 9;
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print<int>(A, len);
	rotateArray<int>(A, 1, len);
	print<int>(A, len);
	
	cout << "Test EVEN array:\n";
	len = 10;
	int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print<int>(B, len);
	rotateArray<int>(B, 1, len);
	print<int>(B, len);

	cout << "Test EMPTY array\n";
	len = 0;
	int C[] = {};
	print<int>(C, len);
	rotateArray<int>(C, 1, len);
	print<int>(C, len);
}

int main() {
	srand(time(NULL));
	cout << "***************R-6.1***************\n";
	R_6_1();
	cout << "***************R-6.2***************\n";
	R_6_2();
	cout << "***************R-6.3***************\n";
	R_6_3();
}