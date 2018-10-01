#include <iostream>
#include <vector>
using namespace std;

// Reference: https://www.geeksforgeeks.org/insertion-sort/

vector<int> insertionSort(vector<int> vec)
{
	int i, j, key;

	for (i = 1; i < vec.size(); i++)
	{
		key = vec[i];
		j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j = j - 1;
		}
		vec[j + 1] = key;
	}
	return vec;
}

void printVec(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec;
	vec.push_back(12);
	vec.push_back(11);
	vec.push_back(13);
	vec.push_back(5);
	vec.push_back(6);

	cout << "Given array: " << endl;
	printVec(vec);
	vec = insertionSort(vec);
	cout << "Sorted array: " << endl;
	printVec(vec);
}