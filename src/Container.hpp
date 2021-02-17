#pragma once

namespace NContainer
{
	template <class T, size_t size>
	class CArray;

	template <class T, size_t size>
	class CCyclic;

	template <class T>
	class CStack;

	template <class T, size_t size>
	class CQueue;

	template <class T>
	class CVector;

	/*template<class T>
	class CIterator;

	template<class T>
	class CReverseIterator;*/
}

template <class T, size_t size>
class NContainer::CArray
{
public:
	CArray() {}

	CArray(const CArray& a);
	CArray(const T* t, const size_t s);

	T & operator[](const size_t s);
	T operator[](const size_t s) const;

	T * Base();
	T const * Base() const;

	T Front() const;
	T Back() const;

	static int Size();

private:
	T e[size];
};

template <class T, size_t size>
class NContainer::CCyclic
{
public:
	T & operator[](const size_t s);
	T operator[](const size_t s) const;

	T * Base();
	T const * Base() const;

	void CopyToArray(T* t) const;

	void Push(T t);

private:
	T e[size];

	size_t pos = 0;
	size_t shiftpos = 0;
};

template <class T>
class NContainer::CStack
{
public:
	T * Base();
	T const * Base() const;

	void Push(T t);
	void Pop();

	T Top() const;

private:
	CVector<T> e;
};

template <class T>
class NContainer::CVector
{
public:
	CVector() {}

	explicit CVector(const size_t s);
	CVector(const T* init, const size_t s);
	CVector(const CVector& v);
	~CVector();

	T & operator[](const size_t s);
	T operator[](const size_t s) const;

	T * Base();
	T const * Base() const;

	T * Begin();
	T const * Begin() const;
	T * End();
	T const * End() const;

	T const * begin() const
	{
		return Begin();
	}

	T const * end() const
	{
		return End();
	}

	void Resize(const size_t s, const T& t = T());

	T &			Front();
	const T &	Front() const;
	T &			Back();
	const T &	Back() const;

	void		PushBack(T t);
	void		PopBack();

	void		Reserve(const size_t s);
	void		ShrinkToFit();
	void		Clear();

	void		Insert(const size_t pos, const T& t);
	void		Insert(const size_t pos, const T* t, const size_t s);
	void		Insert(const size_t pos, const T* t1, const T* t2);

	void		Erase(const size_t pos);
	void		Erase(const size_t pos, const size_t s);

	size_t		Size() const;
	size_t		Capacity() const;

private:
	T*			e = nullptr;

	void		Realloc(const size_t s);

	size_t		size = 0;
	size_t		capacity = 0;
};

/*template<class T>
class NContainer::CIterator
{
public:
	T &			operator[](const int i);
	T			operator[](const int i) const;

	CIterator &	operator=(const CIterator i);
	CIterator &	operator=(T * t);

	CIterator &	operator++();
	CIterator &	operator++(int unused);
	CIterator &	operator--();
	CIterator &	operator--(int unused);

	CIterator &	operator+=(const CIterator i);
	CIterator &	operator-=(const CIterator i);

	CIterator	operator+(const CIterator i) const;
	CIterator	operator+(const CIterator i) const;
	CIterator	operator-(const CIterator i) const;
	CIterator	operator-(const CIterator i) const;

	bool		operator<(CIterator<T> i);
	bool		operator<=(CIterator<T> i);
	bool		operator>(CIterator<T> i);
	bool		operator>=(CIterator<T> i);

	T &			operator*();
	T &			operator->();

private:
	T *			e;
};
*/

// CArray

template <class T, size_t size>
NContainer::CArray<T, size>::CArray(const CArray& a)
{
	for (size_t i = 0; i < size; ++i)
		this[i] = a[i];
}

template <class T, size_t size>
NContainer::CArray<T, size>::CArray(const T* t, const size_t s)
{
	for (size_t i = 0; i < s; ++i)
		this[i] = t[i];
}

template <class T, size_t size>
T & NContainer::CArray<T, size>::operator[](const size_t s)
{
	return e[s];
}

template <class T, size_t size>
T NContainer::CArray<T, size>::operator[](const size_t s) const
{
	return e[s];
}

template <class T, size_t size>
T * NContainer::CArray<T, size>::Base()
{
	return e;
}

template <class T, size_t size>
T const * NContainer::CArray<T, size>::Base() const
{
	return e;
}

template <class T, size_t size>
T NContainer::CArray<T, size>::Front() const
{
	return e[0];
}

template <class T, size_t size>
T NContainer::CArray<T, size>::Back() const
{
	return e[size - 1];
}

template <class T, size_t size>
int NContainer::CArray<T, size>::Size()
{
	return size;
}

// CCyclic

template <class T, size_t size>
T & NContainer::CCyclic<T, size>::operator[](const size_t s)
{
	return e[(pos + s) % size];
}

template <class T, size_t size>
T NContainer::CCyclic<T, size>::operator[](const size_t s) const
{
	return e[(pos + s) % size];
}

template <class T, size_t size>
T * NContainer::CCyclic<T, size>::Base()
{
	return e;
}

template <class T, size_t size>
T const * NContainer::CCyclic<T, size>::Base() const
{
	return e;
}

template <class T, size_t size>
void NContainer::CCyclic<T, size>::CopyToArray(T* t) const
{
	for (size_t i = 0; i < size; ++i)
		t[i] = e[(pos + i) % size];
}

template <class T, size_t size>
void NContainer::CCyclic<T, size>::Push(T t)
{
	if (shiftpos < size)
	{
		e[shiftpos];
		++shiftpos;
		return;
	}

	e[pos] = t;

	pos = (pos + 1) % size;
}

// CStack

template <class T>
void NContainer::CStack<T>::Push(T t)
{
	e.PushBack(t);
}

template <class T>
void NContainer::CStack<T>::Pop()
{
	e.PopBack();
}

template <class T>
T NContainer::CStack<T>::Top() const
{
	return e.Back();
}

template <class T>
T * NContainer::CStack<T>::Base()
{
	return e;
}

template <class T>
T const * NContainer::CStack<T>::Base() const
{
	return e;
}

// CVector

template <class T>
NContainer::CVector<T>::CVector(const size_t s)
{
	capacity = size = s;
	e = new T[s];
}

template <class T>
NContainer::CVector<T>::CVector(const T* init, const size_t s)
{
	capacity = size = s;
	e = new T[s];

	for (size_t i = 0; i < size; ++i)
		e[i] = init;
}

template <class T>
NContainer::CVector<T>::CVector(const CVector<T>& v)
{
	size = v.size;
	capacity = v.capacity;

	for (size_t i = 0; i < size; ++i)
		e[i] = v[i];
}

template <class T>
NContainer::CVector<T>::~CVector()
{
	delete[] e;
}

template <class T>
T & NContainer::CVector<T>::operator[](const size_t s)
{
	return e[s];
}

template <class T>
T NContainer::CVector<T>::operator[](const size_t s) const
{
	return e[s];
}

template <class T>
T * NContainer::CVector<T>::Base()
{
	return e;
}

template <class T>
T const * NContainer::CVector<T>::Base() const
{
	return e;
}

template <class T>
T * NContainer::CVector<T>::Begin()
{
	return e;
}

template <class T>
const T * NContainer::CVector<T>::Begin() const
{
	return e;
}

template <class T>
T * NContainer::CVector<T>::End()
{
	return e + size;
}

template <class T>
const T * NContainer::CVector<T>::End() const
{
	return e + size;
}

template <class T>
void NContainer::CVector<T>::Resize(const size_t s, const T& t)
{
	if (s > capacity)
		Realloc(s);

	if (s > size)
	{
		for (size_t i = size; i < s; ++i)
			e[i] = t;
	}

	size = s;
}

template <class T>
void NContainer::CVector<T>::Reserve(const size_t s)
{
	if (s <= capacity)
		return;

	Realloc(s);
}

template <class T>
void NContainer::CVector<T>::ShrinkToFit()
{
	if (size == capacity)
		return;

	for (size_t i = size; size < capacity; ++i)
		delete e[i];
}

template <class T>
void NContainer::CVector<T>::Clear()
{
	size = 0;
}

template <class T>
void NContainer::CVector<T>::Insert(const size_t pos, const T& t)
{
	if (++size > capacity)
		capacity = size * 2;

	T* temp = new T[capacity];

	for (size_t i = 0; i < pos; ++i)
		temp[i] = e[i];

	e[pos] = t;

	for (size_t i = (pos + 1); i < size; ++i)
		temp[i] = e[i - 1];

	delete[] e;

	e = temp;
}

template <class T>
void NContainer::CVector<T>::Insert(const size_t pos, const T* t, const size_t s)
{
	if (size += s > capacity)
		capacity = size * 2;

	T* temp = new T[capacity];

	for (size_t i = 0; i < pos; ++i)
		temp[i] = e[i];

	for (size_t i = 0; i < s; ++i)
		temp[pos + i] = t[i];

	for (size_t i = (pos + s); i < size; ++i)
		temp[i] = e[i - s];

	delete[] e;

	e = temp;
}

template <class T>
void NContainer::CVector<T>::Insert(const size_t pos, const T* t1, const T* t2)
{
	size_t diff = t2 - t1;

	if (size += diff > capacity)
		capacity = size * 2;

	T* temp = new T[capacity];

	for (size_t i = 0; i < pos; ++i)
		temp[i] = e[i];

	for (size_t i = 0; i < diff; ++i)
		temp[pos + i] = t1[i];

	for (size_t i = (pos + diff); i < size; ++i)
		temp[i] = e[i];

	delete[] e;

	e = temp;
}

template <class T>
void NContainer::CVector<T>::Erase(const size_t pos)
{
	for (size_t i = (pos + 1); i < size; ++i)
		e[i - 1] = e[i];
}

template <class T>
void NContainer::CVector<T>::Erase(const size_t pos, const size_t s)
{
	for (size_t i = (pos + s); i < size; ++i)
		e[i - s] = e[i];
}

template <class T>
size_t NContainer::CVector<T>::Size() const
{
	return size;
}

template <class T>
size_t NContainer::CVector<T>::Capacity() const
{
	return capacity;
}

template <class T>
T & NContainer::CVector<T>::Front()
{
	return e[0];
}

template <class T>
const T & NContainer::CVector<T>::Front() const
{
	return e[0];
}

template <class T>
const T & NContainer::CVector<T>::Back() const
{
	return e[size - 1];
}

template <class T>
T & NContainer::CVector<T>::Back()
{
	return e[size - 1];
}

template <class T>
void NContainer::CVector<T>::PushBack(const T t)
{
	if (++size > capacity)
	{
		capacity = size * 2;
		Realloc(capacity);
	}

	e[size - 1] = t;
}

template <class T>
void NContainer::CVector<T>::PopBack()
{
	--size;
}

template <class T>
void NContainer::CVector<T>::Realloc(const size_t s)
{
	T* temp = new T[s];

	for (size_t i = 0; i < size; ++i)
		temp[i] = e[i];

	capacity = s;

	delete[] e;

	e = temp;
}

/*// CIterator

template <class T>
T& NContainer::CIterator<T>::operator[](const int i)
{
return e[i];
}

template <class T>
T NContainer::CIterator<T>::operator[](const int i) const
{
return e[i];
}

template <class T>
NContainer::CIterator<T>& NContainer::CIterator<T>::operator=(const CIterator i)
{
e = i.e;
return *this;
}

template <class T>
NContainer::CIterator<T>& NContainer::CIterator<T>::operator=(T* t)
{
e = t;
}

template <class T>
NContainer::CIterator<T> & NContainer::CIterator<T>::operator++()
{
++e;
return *this;
}

template <class T>
NContainer::CIterator<T> & NContainer::CIterator<T>::operator++(int unused)
{
CIterator<T> temp = *this;
++e;
return temp;
}

template <class T>
NContainer::CIterator<T> & NContainer::CIterator<T>::operator--()
{
--e;
return *this;
}

template <class T>
NContainer::CIterator<T> & NContainer::CIterator<T>::operator--(int unused)
{
CIterator<T> temp = e;
--e;
return temp;
}

template <class T>
NContainer::CIterator<T>& NContainer::CIterator<T>::operator+=(const CIterator i)
{
e += i.e;
return *this;
}

template <class T>
NContainer::CIterator<T>& NContainer::CIterator<T>::operator-=(const CIterator i)
{
e -= i.e;
return *this;
}

template <class T>
NContainer::CIterator<T> NContainer::CIterator<T>::operator+(const CIterator i) const
{
CIterator<T> temp = e + i.e;
return temp;
}

template <class T>
NContainer::CIterator<T> NContainer::CIterator<T>::operator-(const CIterator i) const
{
CIterator<T> temp = e - i.e;
return temp;
}

template <class T>
bool NContainer::CIterator<T>::operator<(CIterator<T> i)
{
return e < i.e;
}

template <class T>
bool NContainer::CIterator<T>::operator<=(CIterator<T> i)
{
return e <= i.e;
}

template <class T>
bool NContainer::CIterator<T>::operator>(CIterator<T> i)
{
return e > i.e;
}

template <class T>
bool NContainer::CIterator<T>::operator>=(CIterator<T> i)
{
return e >= i.e;
}

template <class T>
T & NContainer::CIterator<T>::operator*()
{
return *e;
}

template <class T>
T& NContainer::CIterator<T>::operator->() {}
*/