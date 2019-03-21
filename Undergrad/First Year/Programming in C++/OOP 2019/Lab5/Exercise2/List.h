#pragma once

template <typename T>
void swap(T *xp, T *yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template <typename T>
void bubbleSort(T arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}		
	}	
}

template <typename T>

class List
{

public:
	T* Elemente;

	int Count, Allocated;

public:

	List()
	{
		Count = 0;
		Allocated = 100;
		Elemente = new T[Allocated];
	}

	~List()
	{
		delete[] Elemente;
	}

	bool Add(const T& element)
	{
		if (this->Count > this->Allocated)
		{
			T* newArray = new T[this->Allocated + this->Count];

			for (int i = 0; i < this->Count; i++)
				newArray[i] = Elemente[i];

			delete[] Elemente;

			T* Elemente = new T[this->Allocated + this->Count];

			for (int i = 0; i < this->Count; i++)
				Elemente[i] = newArray[i];

			delete[] newArray;
			Elemente[Count + 1] = element;
		}
		
		Elemente[this->Count] = element;
		this->Count++;
		return true;
	}

	T& operator[] (int index)
	{
		return Elemente[index];
	}

	void Sort()
	{
		bubbleSort(Elemente, this->Count);
	}

	void printList()
	{
		for (int i = 0; i < this->Count; i++)
		{
			std::cout << Elemente[i] << " ";
		}
		std::cout << std::endl;
	}

};