#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

void selectionSort(int* arr, const int& size) {

	int j = 0, minIndex;

	for (int i = 0; i < size; i++) {

		minIndex = i;

		for (int j = i; j < size; j++) {
			if (arr[j] < arr[minIndex]) minIndex = j;
		}

		std::swap(arr[minIndex], arr[i]);
	}
}

void printArray(int* arr, const int& size) {

	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

int main() {

	int arr[MAX_SIZE];

	int size = 0;

	std::cout << "Enter the size of the array: ";
	std::cin >> size;

	if (size < 0 || size > 100) {
		size = MAX_SIZE;
	}

	std::cout << "Enter the array: ";
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
	
	selectionSort(arr, size);
	printArray(arr, size);
}