#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

void bubbleSort(int* arr, const int& size) {
	int j = 0;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if(arr[i] > arr[j]) std::swap(arr[i], arr[j]);
		}
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
	
	bubbleSort(arr, size);
	printArray(arr,size);
}