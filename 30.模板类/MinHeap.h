#ifndef MINHEAP_H_
#define MINHEAP_H_

#include "Heap.h"

template<typename T, int m_size>
class MinHeap :public Heap<T, m_size>{
public:
	MinHeap();
	MinHeap(const Heap<T, m_size>& origMinHeap);

	~MinHeap(){};

	//T& Remove();

	void  PercolateUp(int index);
	void  PercolateDown(int index);
};

#endif
