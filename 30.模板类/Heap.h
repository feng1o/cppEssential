#ifndef HEAP_H_
#define HEAP_H_

#include "exception"
#include <algorithm>
#include <numeric>
#include <iostream>

template<class T, int m_size> class Heap{

public:

	// required functions by UML
	Heap();
	Heap(const Heap<T, m_size>& origHeap);
	bool Contains(const T& needle) const;
	const T* Find(const T& needle) const;
	virtual T& Remove();
	void Insert(T& insertable);
	void PercolateUp(int index);
	void PercolateDown(int index);

	// student-made functions below
	void BigHeapAdjust(int index);
	void MinHeapAdjust(int index);
	void SetFlag(bool);
	bool GetFlag();
	int  GetSize();
	int  GetArrayKey(int index);
	int  GetArrayValue(int index);
	virtual ~Heap();
//private:
protected:

	// UML-required member variables
	T* m_array;

	// student-made member variables
	int		m_rsize;
	bool	m_flag;
};

#include "Heap.cpp"
#endif /* HEAP_H_ */