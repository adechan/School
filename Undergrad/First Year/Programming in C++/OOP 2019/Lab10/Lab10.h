#pragma once

#include <stdexcept>

class Compare
{

public:
	virtual int CompareElements(void * e1, void * e2) = 0;

};

template <class T>
class Array;

template <class T>
class ArrayIterator

{
private:

	Array<T>* List;
	// add more data and functions for the iterator
	int Current;

public:

	ArrayIterator()
		: List(nullptr)
		, Current(0)
	{
	}

	ArrayIterator(Array<T>& array, int current)
		: List(&array)
		, Current(current)
	{
	}

	ArrayIterator & operator ++ ()
	{
		Current++;
	}

	ArrayIterator & operator - ()
	{
		Current--;
	}

	bool operator == (ArrayIterator <T> & other)
	{
		return *List == *other.List && Current == other.Current;
	}

	bool operator != (ArrayIterator <T> & other)
	{
		return !(*this == other);
	}

	T* GetElement()
	{
		return (*List)[Current];
	}

};

template <class T>

class Array
{
private:

	// list of pointers to objects of type T *
	T ** List; 

	// the size of the pointer list
	int Capacity; 

	// how many items are on the list
	int Size; 

public:

	// List not assigned, Capacity and Size = 0
	Array() 
		: List(nullptr)
		, Capacity(0)
		, Size(0)
	{}

	// destructor
	~Array()
	{
		delete[] List;
	}

	// The list is assigned with 'capacity' items
	Array(int capacity) 
		: List(new T*[capacity])
		, Capacity(capacity)
		, Size(0)
	{}

	// copy constructor
	Array(const Array <T> & otherArray) 
		: Array(otherArray.Capacity)
	{
		for (int i = 0; i < otherArray.Size; i++)
			(*this)[i] = otherArray[i];
	}

	// throw the exception if the index is out of range
	T & operator [] (int index) 
	{
		if (index >= Size)
			throw std::out_of_range("Index is larger than the array size");

		return *List[index];
	}

	// add a type T element at the end of the list and return this
	const Array <T> & operator += (const T & newElem) 
	{
		if (Size >= Capacity)
		{
			const auto oldList = List;
			List = new T*[Capacity + 20];
			Capacity += 20;
			Size++;

			for (int i = 0; i < Size + 1; i++)
				List[i] = oldList[i];

			delete[] oldList;
		}
		else
		{
			List[Size + 1] = &newElem;
			Size++;
		}
	}

	// add an item to the index position, retry this. If an index is invalid, throw an exception
	const Array <T> & Insert(int index, const T & newElem) 
	{
		if (index > Size)
			throw std::out_of_range("Index is larger than the array size");

		auto oldList = List;

		List = new T*[Capacity + 1];
		Capacity++;
		Size++;

		for (int i = 0; i < index; i++)
			List[i] = oldList[i];

		List[index] = &newElem;

		for (int i = index + 1; i < Size; i++)
			List[i] = oldList[i - 1];

		delete[] oldList;
		return *this;
	}

	// add a list to the index position, retouch this. If an index is invalid, throw an exception
	const Array <T> & Insert(int index, const Array <T> otherArray) 
	{
		if (index > Size)
			throw std::out_of_range("Index is larger than the array size");

		for (int i = 0; i < otherArray.Size; i++)
			this->Insert(index + i, otherArray[i]);
		return *this;
	}

	// deletes an element from the index position, returns this. If an index is invalid, throw an exception
	const Array <T> & Delete(int index) 
	{
		if (index >= Size)
			throw std::out_of_range("Index is larger than the array size");

		for (int i = index; i < Size - 1; i++)
			List[i] = List[i + 1];

		Size--;
		return *this;
	}

	bool operator ==(const Array <T> & otherArray)
	{
		if (Size != otherArray.Size)
			return false;

		for (int i = 0; i < Size; i++)
			if (List[i] != otherArray.List[i])
				return false;

		return true;
	}

	// Sorts using the comparison between the elements in T
	void Sort() 
	{

	}

	// Sorts using a comparison function
	void Sort(int(*compare) (const T &, const T &))
	{

	}

	// Sorts using a comparison object
	void Sort(Compare * compare)
	{

	}

	// search functions - returns the position of the element or -1 if it does not exist
	// search for an element using binary search in Array
	int BinarySearch(const T & elem) 
	{
	}

	// search for an element using binary search and a comparison function
	int BinarySearch(const T & elem, int(*compare) (const T &, const T &)); 

	// search for an element using binary search and comparator
	int BinarySearch(const T & elem, Compare * comparator); 

	// searches for an element in Array
	int Find(const T & elem) 
	{
		for (int i = 0; i < Size; i++)
			if (List[i] == &elem)
				return i;

		return -1;
	}

	// search for an element using a comparison function
	int find(const T & elem, int(*compare) (const T &, const T &)) 
	{
		for (int i = 0; i < Size; i++)
			if ((*compare)((void*)List[i], (void*)elem))
				return i;

		return -1;
	}

	// search for an element using a comparator
	int Find(const T & elem, Compare * comparator)
	{
		for (int i = 0; i < Size; i++)
			if ((*comparator)(List[i], elem))
				return i;

		return -1;
	}

	int GetSize() const
	{
		return Size;
	}

	int GetCapacity() const
	{
		return Capacity;
	}

	ArrayIterator <T> GetBeginIterator()
	{
		return ArrayIterator<T>(this, 0);
	}

	ArrayIterator <T> GetEndIterator()
	{
		return ArrayIterator<T>(this, Size);
	}
};