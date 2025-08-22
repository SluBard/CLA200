#include "HeapArray.h"

// ----- CONSTRUCTOR ----- //
HeapArray::HeapArray(const int size) {
	array_size = size;                       // set array size property
	arr = new int[array_size] {0};           // allocate memory on heap
}
HeapArray::HeapArray(const HeapArray& copy) {
	array_size = copy.array_size;
	arr = new int[array_size];
	for (int i = 0; i < array_size; ++i) {
		arr[i] = copy.arr[i];
	}
}
HeapArray& HeapArray::operator=(const HeapArray& copy) {
	array_size = copy.array_size;
	int* tmp = new int[array_size];
	for (int i = 0; i < array_size; ++i) {
		tmp[i] = copy.arr[i];
	}
	delete[] arr;
	arr = tmp;
	return *this;
}
// ----- DESTRUCTOR ----- //
HeapArray::~HeapArray() {
	delete[] arr;                          // deallocate memory 
}

// ----- SUBSCRIPT OPERATOR ----- //
int& HeapArray::operator[] (int i) { return arr[i]; }

// ----- MEMBER FUNCTIONS ----- //
int HeapArray::size() const { return array_size; }
int* HeapArray::begin() { return arr; }
int* HeapArray::end() { return arr + array_size; }