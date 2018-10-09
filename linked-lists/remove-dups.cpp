#include <iostream>
#include <map>
#include <iterator>
#include <list>

// Write code to remove duplicates from an unsorted linked list.
// https://www.geeksforgeeks.org/delete-elements-c-stl-list/

template <typename T>
void printList(std::list<T> lst)
{
	typename std::list<T>::iterator listIter;
	for (listIter = lst.begin(); listIter != lst.end(); ++listIter)
	{
		std::cout << *listIter;
	}
	std::cout << '\n';
}

template <typename T>
void removeDups(std::list<T>& lst)
{
	typename std::map<T, int> hashMap;
	typename std::list<T>::iterator listIter = lst.begin();

	while (listIter != lst.end())
	{
		if (hashMap.count(*listIter) > 0)
		{
			listIter = lst.erase(listIter);
		}
		else
		{
			hashMap.insert(std::pair<T, int>(*listIter, hashMap.count(*listIter) +1));
			++listIter;
		}
	}
}

int main()
{
	std::list<char> list;
	list.push_back('h');
	list.push_back('e');
	list.push_back('l');
	list.push_back('l');
	list.push_back('o');
	list.push_back(' ');
	list.push_back('w');
	list.push_back('o');
	list.push_back('r');
	list.push_back('l');
	list.push_back('d');
	list.push_back('!');
	removeDups(list);
	printList(list);
}