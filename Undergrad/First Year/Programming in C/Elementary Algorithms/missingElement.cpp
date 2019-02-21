// Sum of n integer elements is: n(n+1)/2.
// Here we are missing one element which means we should replace n with n+1.
// So the total of elements in our case becomes: (n+1)(n+2)/2. 
// Once we have the total, we are removing all the elements that user has entered from the total. 
// This way the remaining value is our missing number

#include "stadfx.h"
#include <iostream>

int missingNum(int arr[], int size)				 // sum of n numbers = n(n+1)/ 2
{
	int missing;
	missing = ((size + 1)*(size + 2)) / 2;			// sum of n+1 numbers = (n+1)(n+2)/ 2
	for (int i = 0; i < size; i++)	
		missing = missing - arr[i];
	return missing;
}

int main()
{
	int n;
	std::cout << "Enter the size of array: ";
	std::cin >> n;  
	int arr[100];
	
	std::cout << "Enter array elements: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Number " << i << " : ";
		std::cin >> arr[i];
	}
	int missingNumber = missingNum(arr, 10);
	std::cout << "Missing Number is: " << missingNumber;
	return 0;
}
