#include <iostream>
#include "List.h"
#include "BinaryTree.h"

int main()
{
	std::cout << "Test LinkedList" << std::endl;
	List myList = List();
	myList.Add(3);
	myList.Add(1);
	myList.Add(2);
	myList.Add(3);
	myList.Add(2);

	std::cout << "Count: "<< myList.Count(3);
	std::cout << std::endl;
	
	std::cout << "Print list:" << std::endl;
	myList.printList();
	std::cout << std::endl;

	 myList.Del(2);
	 std::cout << "Print list:" << std::endl;
	 myList.printList();
	 std::cout << std::endl;

	 myList.Add(3);
	 myList.Add(7);

	 std::cout << "Print list:" << std::endl;
	 myList.printList();
	 std::cout << std::endl;

	 std::cout << "Count: " << myList.Count(3) << std::endl;

	 std::cout << "Already exists? " << myList.Exists(3) << std::endl;

	 int* sortedList = myList.GetSortedArray();
	 std::cout << "Print list:" << std::endl;
	 myList.printList();
	 std::cout << std::endl;

	 std::cout << "Sort list1: " << std::endl;
	 for (int i = 0; i < myList.GetCount() - 1; i++)
	 {
		 std::cout << sortedList[i] << " ";
	 }
	 std::cout << std::endl;
	 std::cout << "Count:" << myList.GetCount() << std::endl;


	 myList.Add(8);
	 myList.Add(4);

	 std::cout << "Sort list2: " << std::endl;
	 int* sortedList2 = myList.GetSortedArray();
	 for (int i = 0; i < myList.GetCount() - 1; i++)
	 {
		 std::cout << sortedList2[i] << " ";
	 }
	 std::cout << std::endl;

	 std::cout << "Count:" << myList.GetCount() << std::endl;
	 std::cout << std::endl;

	delete[] sortedList;
	delete[] sortedList2;

	std::cout << "Test BinaryTree" << std::endl;
	BinaryTree myTree = BinaryTree();


	myTree.Add(2);
	myTree.Add(3);

	myTree.printTree();


	std::cin.get();
	return 0;
}