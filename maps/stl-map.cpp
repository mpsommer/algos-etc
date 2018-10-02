// ref: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

#include <iostream>
#include <map>
#include <iterator>

template<typename T>
void printMap(std::map<T, T>& hashMap) {
	// printing map hashMap
	std::map<int, int>::iterator itr;
	std::cout << "The map hashMap is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	// begin() – Returns an iterator to the first element in the map
	// end() – Returns an iterator to the theoretical element that follows last element in the map
	for (itr = hashMap.begin(); itr != hashMap.end(); ++itr)
	{
		std::cout << '\t' << itr->first
			 << '\t' << itr->second << '\n';
	}
	std::cout << '\n';
}


int main()
{
	std::map<int, int> hashMap; // empty map container

	// pair insert(keyvalue,mapvalue) – Adds a new element to the map
	hashMap.insert(std::pair<int, int>(1, 40));
	hashMap.insert(std::pair<int, int>(2, 30));
	hashMap.insert(std::pair<int, int>(3, 60));
	hashMap.insert(std::pair<int, int>(4, 20));
	hashMap.insert(std::pair<int, int>(5, 50));
	hashMap.insert(std::pair<int, int>(6, 50));
	hashMap.insert(std::pair<int, int>(7, 10));

	printMap(hashMap);

	// assigning the elements from hashMap to gquiz2
	std::map<int, int> gquiz2(hashMap.begin(), hashMap.end());

	// // print all elements of the map gquiz2
	std::cout << "\nThe map gquiz2 after assign from hashMap is : \n";

	printMap(gquiz2);

	// remove all elements up to element with key=3 in gquiz2
	std::cout << "\ngquiz2 after removal of elements less than key=3 : \n";
	std::cout << "\tKEY\tELEMENT\n";
	// erase(iterator position) – Removes the element at the position pointed by the iterator
	gquiz2.erase(gquiz2.begin(), gquiz2.find(3));

	printMap(gquiz2);

	// remove all elements with key = 4
	int num;
	// erase(const g)- Removes the key value ‘g’ from the map
	num = gquiz2.erase(4);
	std::cout << "\ngquiz2.erase(4) : ";
	std::cout << num << " removed \n";
	std::cout << "\tKEY\tELEMENT\n";

	printMap(gquiz2);

	std::cout << '\n';

	//lower bound and upper bound for map hashMap key = 5
	std::cout << "hashMap.lower_bound(5) : "
		 << "\tKEY = ";
	// lower_bound(const g) – Returns an iterator to the first element that is
	//  equivalent to mapped value with key value ‘g’ or definitely will not go
	//  before the element with key value ‘g’ in the map
	std::cout << hashMap.lower_bound(5)->first << '\t';
	std::cout << "\tELEMENT = " << hashMap.lower_bound(5)->second << '\n';
	std::cout << "hashMap.upper_bound(5) : "
		 << "\tKEY = ";
	// upper_bound(const g) – Returns an iterator to the first element that is
	// equivalent to mapped value with key value ‘g’ or definitely will go after
	// the element with key value ‘g’ in the map
	std::cout << hashMap.upper_bound(5)->first << '\t';
	std::cout << "\tELEMENT = " << hashMap.upper_bound(5)->second << '\n';

	return 0;
}