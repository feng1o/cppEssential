#include "MinHeap.h"

template<typename T, int m_size>
MinHeap<T, m_size>::MinHeap() :Heap<T, m_size>(){

};

template<typename T, int m_size>
MinHeap<T, m_size>::MinHeap(const Heap<T, m_size>& origMinHeap) :Heap<T, m_size>(origMinHeap){

};

template<typename T, int m_size>
void MinHeap<T, m_size>::PercolateDown(int index){
	Heap<T, m_size>::PercolateDown(index);
};

template<typename T, int m_size>
void MinHeap<T, m_size>::PercolateUp(int index){
	Heap<T, m_size>::PercolateUp(index);
};
