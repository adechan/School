#include <iostream>
#include <vector>
#include <functional>


template <class T>
void swapElements(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

int lessThan(int a, int b)
{
	if (a < b)
		return 1;
	return 0;
}

template <class T>
int partition(T arr[], int low, int high, int(*compare)(T e1, T e2))
{
	T pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (compare(arr[j], pivot))
		{
			i++; 
			swapElements(&arr[i], &arr[j]);
		}
	}

	swapElements(&arr[i + 1], &arr[high]);
	return (i + 1);
}

template <class T>
void quickSort(T arr[], int low, int high, int(*compare)(T e1, T e2))
{
	if (low < high)
	{
		int pi = partition(arr, low, high, compare);
		quickSort(arr, low, pi - 1, compare);
		quickSort(arr, pi + 1, high, compare);
	}
}

template <class T>
void Sort(std::vector<T>& lista, int(*compare)(T e1, T e2))
{
	quickSort(lista.data(), 0, lista.size() - 1, compare);
}

int main()
{

	std::vector<int> arrayList;
	arrayList.push_back(3);
	arrayList.push_back(2);
	arrayList.push_back(5);
	arrayList.push_back(1);
	arrayList.push_back(0);
	arrayList.push_back(10);
	arrayList.push_back(23);
	arrayList.push_back(9);
	arrayList.push_back(5);
	arrayList.push_back(2);

	Sort(arrayList, lessThan);

	for (auto arrayNumber : arrayList)
	{
		std::cout << arrayNumber << " ";
	}

	std::vector<int> arrayList2;
	arrayList2.push_back(3);
	arrayList2.push_back(2);
	arrayList2.push_back(5);
	arrayList2.push_back(1);
	arrayList2.push_back(0);
	arrayList2.push_back(10);
	arrayList2.push_back(23);
	arrayList2.push_back(9);
	arrayList2.push_back(5);
	arrayList2.push_back(2);


	const auto compare = [](int a, int b) -> int
	{
		return a < b;
	};

	Sort<int>(arrayList2, compare);


	for (auto arrayNumber : arrayList2)
	{
		std::cout << arrayNumber << " ";
	}

	/*std::vector<std::function<int(int, int)>> fns;

	const auto fns2 = std::array{
		[](int a) {
			return [](int b) {
				return b;
			};
		}
	};

	fns2[0](2)(3);

	fns.push_back([](int a, int b) { return a < b; });
	fns.push_back([](int a, int b) { return a > b; });
	fns.push_back([](int a, int b) { return a == b; });

	
	fns[1](1, 2);
	
	[](int a, int b) { return a > b; }(1, 2);

	std::cout << fns[1](1, 2) << '\n';*/

	std::cin.get();
	return 0;
}