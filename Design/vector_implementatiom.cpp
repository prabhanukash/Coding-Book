#include <bits/stdc++.h>
#include<vector>
using namespace std;

template <typename T>
class Vector
{
private:
	T *data;		 // Pointer to the dynamically allocated array
	size_t size;	 // Current number of elements in the array
	size_t capacity; // Current capacity of the array

	// Helper function to reallocate memory if needed
	void resize(size_t newCapacity)
	{
		T *newData = new T[newCapacity];
		for (size_t i = 0; i < size; ++i)
		{
			newData[i] = move(data[i]);
		}
		delete[] data;
		data = newData;
		capacity = newCapacity;
	}

public:
	// Constructor
	Vector() : data(nullptr), size(0), capacity(0) {}

	// Destructor
	~Vector()
	{
		delete[] data;
	}

	// Copy constructor
	Vector(const Vector &other) : data(nullptr), size(other.size), capacity(other.capacity)
	{
		data = new T[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = other.data[i];
		}
	}

	// Assignment operator
	Vector &operator=(const Vector &other)
	{
		if (this != &other)
		{
			delete[] data;
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for (size_t i = 0; i < size; ++i)
			{
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	// Push element to the back of the vector
	void push_back(const T &value)
	{
		if (size == capacity)
		{
			if (capacity == 0)
			{
				resize(1);
			}
			else
			{
				resize(capacity * 2);
			}
		}
		data[size++] = value;
	}

	// Get element at index
	T &operator[](size_t index)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of range");
		}
		return data[index];
	}

	// Get size of the vector
	size_t getSize() const
	{
		return size;
	}

	// Get capacity of the vector
	size_t getCapacity() const
	{
		return capacity;
	}
};

int main()
{
	Vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::cout << "Size: " << vec.getSize() << std::endl;
	std::cout << "Capacity: " << vec.getCapacity() << std::endl;

	for (size_t i = 0; i < vec.getSize(); ++i)
	{
		std::cout << "Element " << i << ": " << vec[i] << std::endl;
	}

	return 0;
}
