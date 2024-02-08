#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

void countingSort(int* arr, const int& size) {

	int maxElem = arr[0];
	for (int i = 1; i < size; i++) {
		if (maxElem < arr[i]) maxElem = arr[i];
	}

	int* counting = new int[maxElem];
	for (int i = 0; i < maxElem; i++) {
		counting[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		counting[arr[i] - 1]++;
	}
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}

	int index = 0;
	for (int i = 0; i < maxElem; i++) { 
		while (counting[i] > 0) {
			arr[index++] = i + 1;
			counting[i]--;
		}
	}
	
	delete counting;
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

	countingSort(arr, size);
	printArray(arr, size);
}