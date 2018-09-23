#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

int* maxSubArray(int* arr, int arrLength) {
	int maxSoFar = 0;
	int maxEndingHere = 0;
	int* resultArr = new int[3];
	resultArr[0] = 0;
	resultArr[1] = 0; 
	bool newBeginning = false;

	for (int i = 0; i < arrLength; i++) {
		maxEndingHere += arr[i];
		if (maxEndingHere < 0) { 
			maxEndingHere = 0; 
			newBeginning = true;
		}

		if (maxEndingHere > maxSoFar) { 
			maxSoFar = maxEndingHere; 
			if (newBeginning) { 
				resultArr[0] = i;
				newBeginning = false;
			}
			resultArr[1] = i; 
		}
	}
	resultArr[2] = maxSoFar;
	return resultArr;
}

void printArray(int arr[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	// int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int arr[] = {3, -1, -1, -1, -11, 45};
	// int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	int* result = maxSubArray(arr, arr_size);

	printf("Max subarray start index: %d \n", result[0]);
	printf("Max subarray stop index: %d \n", result[1]);
	printf("Max subarray sum: %d \n", result[2]);
	return 0;
}
