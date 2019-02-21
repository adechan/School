#include "sortArray.h"
#include <vector>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(std::vector<int>& vector)
{
	for (int i = 0; i < vector.size() - 1; i++)
	{
		for (int j = 0; j < vector.size() - i - 1; j++)
		{
			if (vector[j] > vector[j+1])
			{
				std::swap(vector[j], vector[j + 1]);
			}
		}
	}
}