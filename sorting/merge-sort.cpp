// Reference: https://www.geeksforgeeks.org/merge-sort/

#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int leftLength = m + 1 - l;
	int rightLength = r - m;

	int left[leftLength], right[rightLength];

	for (i = 0; i < leftLength; i++) {
		left[i] = arr[l + i];
	}

	for (j = 0; j < rightLength; j++) {
		right[j] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;
	
	while (i < leftLength && j < rightLength) {
		if(left[i] <= right[j]) {
			arr[k] = left[i++];
		} else {
			arr[k] = right[j++];
		}
		k++;
	}
	while (i < leftLength) {
		arr[k] = left[i++];
		k++;
	}

	while (j < rightLength) {
		arr[k] = right[j++];
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m +1, r);
		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
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

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}
