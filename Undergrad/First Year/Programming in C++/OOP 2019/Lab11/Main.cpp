#include <iostream>
#include <vector>

template <class T, class Comparator>
int partition(T arr[], int low, int high, Comparator compare)
{
	T pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (compare(arr[j], pivot))
		{
			i++;
			std::swap(arr[i], arr[j]);
		}
	}

	std::swap(arr[i + 1], arr[high]);

	// Should be i+1 because otherwise we miss the last element
	// Original: return i + 1;
	return i;
}

template <class T, class Comparator>
void quickSort(T arr[], int low, int high, Comparator compare)
{
	if (low < high)
	{
		//Original: int pi = partition(arr, low, high, compare);
		int pi = partition(arr, low + 1, high, compare);

		// Should be just low because otherwise we miss the first element
		//Original: quickSort(arr, low, pi - 1, compare);
		quickSort(arr, low + 1, pi - 1, compare);
		quickSort(arr, pi + 1, high, compare);
	}
}

// Should take vector by reference in order to actually change any of its contents
// Original: void sort(std::vector<T>& vector, Comparator compare)
template <class T, class Comparator>
void sort(std::vector<T> vector, Comparator compare)
{
	// Should start at 0 so that we sort the whole vector
	//Original: quickSort(vector.data(), 0, vector.size(), compare);
	quickSort(vector.data(), 1, vector.size(), compare);
}

template <class Range>
void print(const Range& range)
{
	for (const auto& e : range)
		std::cout << e << ' ';

	std::cout << '\n';
}

int main()
{
	std::vector<int> x = { 5, 1, 3, 2, 6 };
	print(x);

	sort(x, [](int left, int right)
	{
		return left > right;
	});

	print(x);
	std::cin.get();
	return 0;
}