#include <iostream>

int merged[7];

void merge(int* arr, int start, int mid, int end) {

	int i = start, j = mid + 1, index = 0;

	while (i <= mid && j <= end) {


		if (arr[i] <= arr[j]) {
			merged[index++] = arr[i++];
		}
		else {
			merged[index++] = arr[j++];
		}
	}

	while (i <= mid) {
		merged[index++] = arr[i++];
	}

	while (j <= end) {
		merged[index++] = arr[j++];
	}

	for (int k = start; k <= end; k++) {
		arr[k] = merged[k - start];
	}
}

void mergeSort(int* arr, int start, int end) {

	if (start >= end) return;

	int mid = start + (end - start) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);


	merge(arr, start, mid, end);
}


int main() {

	int arr[] = { 7,1,3,2,8,5 };
	int n = 6;

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}