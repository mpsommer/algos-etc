// Reference: https://www.geeksforgeeks.org/quick-sort/

#include <iostream>

int partition(int* arr, int low, int high) {
	int pivot = arr[high];
	int smallIndex = low - 1;

	for (int largeIndex = low; largeIndex < high; largeIndex++) {
		if (arr[largeIndex] <= pivot) {
			smallIndex++;
			std::swap(arr[smallIndex], arr[largeIndex]);
		}
	}
	std::swap(arr[smallIndex + 1], arr[high]);
	return smallIndex + 1;
}

void quickSort(int* arr, int low, int high) {
	if (low < high) {
		int partitionIndex = partition(arr, low, high);
		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size) {
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
}

// Driver program to test above functions 
int main() {
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Array: ");
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printf("Sorted array: ");
	printArray(arr, n);
	return 0;
}