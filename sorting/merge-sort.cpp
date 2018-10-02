// Reference: https://www.geeksforgeeks.org/merge-sort/

#include <iostream>
#include <vector>

template<typename T>
void merge(std::vector<T>& vec, int l, int m, int r)
{
	int i{0};
	int j{0};
	int k{0};
	int leftLength = m + 1 - l;
	int rightLength = r - m;
	std::vector<T> left;
	left.reserve(leftLength);
	std::vector<T> right;
	right.reserve(rightLength);

	for (i = 0; i < leftLength; ++i)
	{
		left[i] = vec[l + i];
	}

	for (j = 0; j < rightLength; ++j)
	{
		right[j] = vec[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < leftLength && j < rightLength)
	{
		if (left[i] <= right[j])
		{
			vec[k] = left[i++];
		}
		else
		{
			vec[k] = right[j++];
		}
		k++;
	}

	while (i < leftLength)
	{
		vec[k++] = left[i++];
	}

	while (j < rightLength)
	{
		vec[k++] = right[j++];
	}
}

template<typename T>
void mergeSort(std::vector<T>& vec, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(vec, l, m);
		mergeSort(vec, m + 1, r);
		merge(vec, l, m, r);
	}
}

template<typename T>
void printVec(std::vector<T> vec)
{
	for (auto const& elem: vec)
	{
		std::cout << elem << " ";
	}
	std::cout << "\n";
}

/* Driver program to test above functions */
int main()
{
	std::vector<int> vec;
	vec.push_back(12);
	vec.push_back(11);
	vec.push_back(13);
	vec.push_back(5);
	vec.push_back(6);
	// std::vector<char> vec;
	// vec.push_back('r');
	// vec.push_back('f');
	// vec.push_back('u');
	// vec.push_back('c');
	// vec.push_back('A');

	std::cout << "Given array: " << "\n";
	printVec(vec);
	mergeSort(vec, 0, vec.size() - 1);
	std::cout << "Sorted array: " << "\n";
	printVec(vec);
}
