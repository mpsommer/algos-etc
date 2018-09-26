#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/counting-sort/


int findMaxValue(int arr[], int arrLength) {
	int maxValue = -1;
	for (int i = 0; i < arrLength; i++) {
		if (maxValue < arr[i]) {
			maxValue = arr[i];
		}
	}
	return maxValue;
}

void countingSort(int* arr, int arrLength) {

	int maxValue = findMaxValue(arr, arrLength);
}

void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	cout << findMaxValue(arr, arr_size) << endl;

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}

