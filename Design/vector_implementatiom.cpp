#include <bits/stdc++.h>
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
		cout << "inside copy constructor\n";

		data = new T[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			data[i] = other.data[i];
		}
	}
	// Move constructor
	Vector(Vector &&other) noexcept : data(other.data), size(other.size), capacity(other.capacity)
	{
		cout << "inside move constructor\n";
		other.data = nullptr;
		other.size = 0;
		other.capacity = 0;
	}

	// Assignment operator
	Vector &operator=(const Vector &other)
	{
		cout << "inside copy assignement\n";
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
	// Move Assignment operator
	Vector &operator=(Vector &&other) noexcept
	{
		cout << "inside move assignement \n";
		if (this != &other)
		{
			// Swap internal state with the temporary object
			swap(data, other.data);
			swap(size, other.size);
			swap(capacity, other.capacity);
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
			throw out_of_range("Index out of range");
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

	cout << "Size: " << vec.getSize() << endl;
	cout << "Capacity: " << vec.getCapacity() << endl;

	for (size_t i = 0; i < vec.getSize(); ++i)
	{
		cout << "Element " << i << ": " << vec[i] << endl;
	}
	Vector<int> vec2 = vec; // Copy constructor
	Vector<int> vec3;
	vec3 = vec; // Copy assignment operator

	Vector<int> vec4 = move(vec); // Move constructor
	Vector<int> vec5;
	vec5 = move(vec4); // Move assignment operator

	return 0;
}
