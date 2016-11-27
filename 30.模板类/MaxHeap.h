#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "Heap.h"

template<typename T, int m_size>
class MaxHeap :public Heap<T, m_size>{
public:
	MaxHeap() ;
	MaxHeap(const Heap<T, m_size>& origMaxHeap);
	~MaxHeap(){};

	//T& Remove();
	void  PercolateUp(int index);
	void  PercolateDown(int index);
};

#endif
