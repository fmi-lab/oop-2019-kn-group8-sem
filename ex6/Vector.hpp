#pragma once
#include <iostream>
#include <cassert>

/*
Base representation of vector structure.

Note: The next piece of header was used for exercise reasons.
Parts of it can be written in different ways 
*/

template <typename Type>
class Vector {
private:
	Type* container;
	size_t usedSize;
	size_t capacity;

	void resize();
	void copy(const Vector& src); // copy(Type*& dest, Type* src..)
	void destroy() {
		delete[] container;
	}

public:
	Vector();
	Vector(const Type* container, const size_t& usedSize, const size_t& capacity);
	Vector(const Vector& src);
	~Vector();

	size_t getSize() const;
	size_t getCapacity() const;

	Vector& operator=(const Vector& src);

	bool isEmpty() const;

	void pushBack(const Type& src);
	Type popBack();

	void insertAt(const Type& src, const int& index);
	void eraseAt(const int& index);

	Type& operator[](const int& index);
	Type operator[](const int& index) const;
	Type& at(const int& index);

	friend std::ostream& operator<<(std::ostream& out, const Vector<Type>& src) {
		out << "----------------------------\n";

		for (size_t index = 0; index < src.getSize(); ++index) {
			out << src[index] << ' '; // src.container[index]
		}

		return out;
	}
};

template<typename Type>
inline void Vector<Type>::resize()
{
	Type* buffer = new Type[2 * (capacity + 1)];
	for (size_t index = 0; index < capacity; ++index) {
		buffer[index] = container[index];
	}

	delete[] container;
	container = buffer;
	capacity = 2 * (capacity + 1);
}

template<typename Type>
inline void Vector<Type>::copy(const Vector & src)
{
	if (container != nullptr) {
		destroy();
	}

	container = new Type[src.capacity];
	for (size_t index = 0; index < src.usedSize; ++index) {
		container[index] = src.container[index];
	}
	capacity = src.capacity;
	usedSize = src.usedSize;
}

template<typename Type>
inline Vector<Type>::Vector()
{
	container = nullptr;
	usedSize = 0;
	capacity = 0;
}

template<typename Type>
inline Vector<Type>::Vector(const Type * container, const size_t & usedSize, const size_t & capacity)
{
	this->usedSize = usedSize;
	this->capacity = capacity;
	this->container = new Type[capacity];

	for (size_t index = 0; index < usedSize; ++index) {
		this->container[index] = container[index];
	}
}

template<typename Type>
inline Vector<Type>::Vector(const Vector & src)
{
	copy(src);
}

template<typename Type>
inline Vector<Type>::~Vector()
{
	destroy();
}

template<typename Type>
inline size_t Vector<Type>::getSize() const
{
	return usedSize;
}

template<typename Type>
inline size_t Vector<Type>::getCapacity() const
{
	return capacity;
}

template<typename Type>
inline Vector<Type> & Vector<Type>::operator=(const Vector<Type> & src)
{
	if (this != &src) {
		destroy();
		copy(src);
	}

	return *this;
}

template<typename Type>
inline bool Vector<Type>::isEmpty() const
{
	return usedSize == 0; // container == nullptr
}

template<typename Type>
inline void Vector<Type>::pushBack(const Type & src)
{
	if (usedSize == capacity) {
		resize();
	}

	container[usedSize++] = src;
}

template<typename Type>
inline Type Vector<Type>::popBack()
{
	/*
	return container[--usedSize];
	*/

	Type toPop = container[usedSize - 1];

	Type *buffer = new Type[capacity];
	for (size_t index = 0; index < usedSize - 1; ++index) {
		buffer[index] = container[index];
	}

	delete[] container;
	container = buffer;
	--usedSize;

	return toPop;
}

template<typename Type>
inline void Vector<Type>::insertAt(const Type & src, const int & index)
{
	assert(index >= 0 && index <= usedSize);
	
	if (usedSize == capacity) {
		resize();
	}

	for (int move = usedSize - 1; move >= index; --move) {
		container[move + 1] = container[move];
	}
	container[index] = src;
	
	++usedSize;
}

template<typename Type>
inline void Vector<Type>::eraseAt(const int & index)
{
	assert(index >= 0 && index < usedSize);

	for (size_t move = index; move < usedSize - 1; ++move) {
		container[move] = container[move + 1];
	}

	--usedSize;

	/*with new buffer*/
}

template<typename Type>
inline Type & Vector<Type>::operator[](const int & index)
{
	// assert(index >=0 && index < usedSize);
	return container[index];
}

template<typename Type>
inline Type Vector<Type>::operator[](const int & index) const
{
	// assert(index >=0 && index < usedSize);
	return container[index];
}

template<typename Type>
inline Type & Vector<Type>::at(const int & index)
{
	// assert(index >=0 && index < usedSize);
	return container[index];
}
