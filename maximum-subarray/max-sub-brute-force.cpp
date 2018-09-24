#include <stdio.h>
#include <stdlib.h>

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
int* maxSubArray(int* arr, int arrLength) {
	int* resultArr = new int[3];
	int i, j, maxSum, maxSoFar;
	maxSum = 0;
	for (i = 0; i < arrLength; i++) {
		maxSoFar = 0;
		for (j = i; j < arrLength; j++) {
			maxSoFar += arr[j];
			if (maxSoFar > maxSum) {
				maxSum = maxSoFar;
				resultArr[0] = i;
				resultArr[1] = j;
				resultArr[2] = maxSum;
			}
		}
	}
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
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	int* result = maxSubArray(arr, arr_size);

	printf("Max subarray start index: %d \n", result[0]);
	printf("Max subarray stop index: %d \n", result[1]);
	printf("Max subarray sum: %d \n", result[2]);
	return 0;
}
