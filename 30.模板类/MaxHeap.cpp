#include "MaxHeap.h"

template<typename T, int m_size>
MaxHeap<T, m_size>::MaxHeap() :Heap<T, m_size>(){

};

template<typename T, int m_size>
MaxHeap<T, m_size>::MaxHeap(const Heap<T, m_size>& origMaxHeap):Heap<T, m_size>(origMaxHeap){

};

template<typename T, int m_size>
void MaxHeap<T, m_size>::PercolateDown(int index){
	Heap<T, m_size>::PercolateDown(index);
}

template<typename T, int m_size>
void MaxHeap<T, m_size>::PercolateUp(int index){
	Heap<T, m_size>::PercolateUp(index);
}
