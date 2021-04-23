#include <iostream>
#include <cstring>
#include <cstdint>
#include "MyDynArray.h"

// constructor; default size is 100 items
MyDynArray::MyDynArray()
{
	size = 100;
	array_ptr = new T[100];
}
//constructor
MyDynArray::MyDynArray(size_t size_ = 100)
{
	array_ptr = new T[size_];	
	size = size_;
	
}

// get the current array size
 size_t MyDynArray::getSize() const//The This is used to return 
{
	return this->size;
}


bool MyDynArray::set(T element, size_t index)
{	
	cout << "Function set() called with element: " << element << " and " << "index: " << index << endl; 
	
	if (index <= size)
	{
		array_ptr[index] = element;
		return true;
	}
		
		size = index; // element is assigned to the index in array pointer
		MyDynArray temparray(*this);
		delete array_ptr;
		*this = temparray;
		return true;
	}

// put the element at the position specified by index
// if the position is out of range, increase the size of array accordingly
T MyDynArray::get(size_t index) const
{
	return array_ptr[index];
}

// copy constructor: should do a deep copy
MyDynArray::MyDynArray(const MyDynArray& arg)
{
		cout << "Copy constructor called" << endl;
		size = arg.size;	//new array for args size
		array_ptr = new T[arg.size];	//sets size for the default class
		memcpy(array_ptr, arg.array_ptr, sizeof(T) * size);
		
	
}
// assignment operator: should do a deep,copy
MyDynArray& MyDynArray::operator=(const MyDynArray& rhs)
{
	if(this == &rhs)
		return *this;
	delete[] array_ptr;
	array_ptr = new T[rhs.size];
	size = rhs.size;
	memcpy(array_ptr, rhs.array_ptr, sizeof(T) * size);
	return *this;
}
 // destructor
MyDynArray::~MyDynArray()
{
	delete [] array_ptr;
	cout << "Destructor called" << endl;
}
