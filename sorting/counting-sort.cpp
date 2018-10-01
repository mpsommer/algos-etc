#include <iostream>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/counting-sort/

void printVec(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int findMaxValue(vector<int> vec)
{
	int maxValue = -1;
	for (int i = 0; i < vec.size(); i++)
	{
		int value = vec[i] + 1;
		if (maxValue < value)
		{
			maxValue = value;
		}
	}
	return maxValue;
}

vector<int> countingSort(vector<int> vec)
{
	int countLength = findMaxValue(vec);
	vector<int> countVec(countLength);
	int vecLength = vec.size();
	vector<int> sortedVec(vecLength);
	int i = {0};

	// Puts the number of input elements equal to i
	// for each integer i = 0, 1,..., countLength into countVec.
	for (i = 0; i < vecLength; i++)
	{
		countVec[vec[i]] = countVec[vec[i]] + 1;
	}

	// Determines for each i = 0, 1, ..., countLength how many input
	// elements are less than or equal to i by keeping a running sum
	// of the vec countVec
	for (i = 1; i < countLength; i++)
	{
		countVec[i] = countVec[i] + countVec[i - 1];
	}

	// Places each element vec[i] into its correct sorted position in the
	// sortedVec.
	for (i = vecLength - 1; i > 0; i--)
	{
		sortedVec[countVec[vec[i]] - 1] = vec[i];
		countVec[vec[i]] = countVec[vec[i]] - 1;
	}

	return sortedVec;
}

/* Driver program to test above functions */
int main()
{
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(0);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(0);
	vec.push_back(3);

	cout << "Given array: " << endl;
	printVec(vec);
	vec = countingSort(vec);

	cout << "Sorted array: " << endl;
	printVec(vec);
}
