#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ref: https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/


int* maxCrossingSubArray(int* arr, int low, int mid, int high) {
	int leftSum = INT_MIN;
	int rightSum = INT_MIN;
	int sum = 0;
	int i, j;
	int* resultArr = new int[3];

	for (i = mid; i > low; i--) {
		sum += arr[i];
		if (sum > leftSum) {
			leftSum = sum;
			resultArr[0] = i;
		}
	}

	sum = 0;
	for (j = mid + 1; j < high; j++) {
		sum += arr[j];
		if (sum > rightSum) {
			rightSum = sum;
			resultArr[1] = j;
		}
	}
	resultArr[2] = leftSum + rightSum;
	return resultArr;
}

int* maxSubArray(int* arr, int low, int high) {
	// Index zero contains index of lowwest index for sum.
	// Index one contains index of highest index for sum.
	// Index three contains the sum.
	int* resultArr = new int[3];
	int* leftArr = new int[3];
	int* rightArr = new int[3];
	int* crossArr = new int[3];
	if (high == low) {
		resultArr[0] = low;
		resultArr[1] = high;
		resultArr[2] = arr[low];
	}
	else {
		int mid = low + (high - low) / 2;
		leftArr = maxSubArray(arr, low, mid);
		rightArr = maxSubArray(arr, mid + 1, high);
		crossArr = maxCrossingSubArray(arr, low, mid, high);

		if (leftArr[2] >= rightArr[2] && leftArr[2] >= crossArr[2]) {
			resultArr = leftArr;
		} else if (rightArr[2] >= leftArr[2] && rightArr[2] >= crossArr[2]) {
			resultArr = rightArr;
		} else {
			resultArr = crossArr;
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
	// int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	int* result = maxSubArray(arr, 0, arr_size - 1);

	printf("Max subarray start index: %d \n", result[0]);
	printf("Max subarray stop index: %d \n", result[1]);
	printf("Max subarray sum: %d \n", result[2]);
	return 0;
}
