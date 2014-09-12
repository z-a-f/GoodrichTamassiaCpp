#include <cmath>
#include <iostream>

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
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	print<int>(A, 9);
	reverseArray<int>(A, 9);
	print<int>(A, 9);
}

int main() {
	cout << "***************R-6.1***************\n";
	R_6_1();
}