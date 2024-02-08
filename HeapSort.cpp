#include <iostream>
#include <algorithm>

void siftDown(int* arr, int n, int i) {

	int largest = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {

		std::swap(arr[i], arr[largest]);

		siftDown(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {

	for (int i = n / 2; i >= 0; --i) {
		siftDown(arr, n, i);
	}

	for (int i = n - 1; i >= 0; --i) {
		std::swap(arr[0], arr[i]);
		siftDown(arr, i, 0);
	}
}

int main() {

	int arr[] = { 2,3,6,5,12,1,8 };
	int n = 7;

	heapSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}