#include <iostream>
#include <map>
#include <iterator>


//  Implement an algorithm to determice if a string has all unique characters. 
//  What if you cannot use additional data structures?

// https://thispointer.com/how-check-if-a-given-key-exists-in-a-map-c/

bool isUnique(std::string str)
{
	// Declare string iterator.
	std::string::iterator itr;
	// Declare map with char for keys, and int for key count.
	std::map<char, int> hashMap;
	// Iterate over string.
	for (itr = str.begin(); itr != str.end(); ++itr)
	{
		// If the count of a key is greater than 0, then not unique, return false.
		if (hashMap.count(*itr) > 0)
		{
			std::cout << "Returning False" << '\n';
			return false;
		}
		else
		{
			hashMap.insert(std::pair<char, int>(*itr, hashMap.count(*itr) + 1));
		}
	}
	return true;
}

int main()
{
	std::string str = "hello world";

	std::cout << str << '\n';
	bool result = isUnique(str);
	std::cout << result << '\n';
}