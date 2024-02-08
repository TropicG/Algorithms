#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

int* merge(int* A, int* B, const int& sizeA, const int& sizeB) {

	int indexA = 0, indexB = 0;

	int* C = new int[sizeA + sizeB];
	int indexC = 0;

	while (indexA != sizeA && indexB != sizeB) {
		if (A[indexA] <= B[indexB]) C[indexC++] = A[indexA++];
		else C[indexC++] = B[indexB++];
	}

	while (indexA != sizeA)
		C[indexC++] = A[indexA++];

	while (indexB != sizeB)
		C[indexC++] = B[indexB++];


	return C;
}

void printArray(int* arr, const int& size) {

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

int main() {

	int A[MAX_SIZE], B[MAX_SIZE];

	int sizeA = 0, sizeB;

	std::cout << "Enter the size of array A: ";
	std::cin >> sizeA;

	if (sizeA < 0 || sizeA > 100) {
		sizeA = MAX_SIZE;
	}

	std::cout << "Enter the array A: ";
	for (int i = 0; i < sizeA; i++) {
		std::cin >> A[i];
	}

	std::cout << "Enter the size of array B: ";
	std::cin >> sizeB;

	if (sizeB < 0 || sizeB > 100) {
		sizeB = MAX_SIZE;
	}

	std::cout << "Enter the array B: ";
	for (int i = 0; i < sizeB; i++) {
		std::cin >> B[i];
	}

	int* C = merge(A, B, sizeA, sizeB);

	printArray(C, sizeA + sizeB);

	delete[] C;
}