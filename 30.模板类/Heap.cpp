#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"
#include <exception>

template<class T, int m_size>
Heap<T, m_size>::Heap() :m_array(NULL), m_rsize(0), m_flag(true){
	if (NULL == m_array)
		m_array = new T[m_size];
	if (NULL == m_array)
		std::cerr << "bad alloc~!\n";
}

template<class T, int m_size>
Heap<T, m_size>::~Heap(){
	if (m_array)
	{
		delete[] m_array;
	}
}

template<class T, int m_size>
Heap<T, m_size>::Heap(const Heap<T, m_size>& origHeap) :m_rsize(origHeap.m_rsize), m_flag(origHeap.m_flag) {
	m_array = new T[m_rsize];
	//std::cout << "........................\n";
	for (int i = 0; i < m_rsize; ++i)
	{
		m_array[i] = origHeap.m_array[i];
	}
}

template<class T, int m_size>
bool Heap<T, m_size>::Contains(const T& needle) const {
	for (int i = 0; i < m_rsize; ++i)
	{
		if (m_array[i] == needle)
		{
			return true;
		}
	}
	return false;
}


template<class T, int m_size>
const T* Heap<T, m_size>::Find(const T& needle) const {
	for (int i = 0; i < m_rsize; ++i)
	{
		if (m_array[i] == needle)
		{
			return  &needle;
		}
	}
	return NULL;
}

template<class T, int m_size>
T& Heap<T, m_size>::Remove() {
	if (0 < m_rsize){
		//T tmp = m_array[0];
		std::swap(m_array[0], m_array[m_rsize - 1]);
		--m_rsize;
		//if (GetFlag())
		//{
		//	BigHeapAdjust(0);
		//}
		//else{
		//	MinHeapAdjust(0);
		//}
		PercolateDown(0);
		//return tmp;
        return m_array[m_rsize-1];
	}
	else{
		T t(-1, 0);
		return t;
	}
}

template<class T, int m_size>
void Heap<T, m_size>::Insert(T& insertable) {
	if (m_rsize + 1 > m_size)
	{
        std::cerr << "error out of size \n";
	}
	m_array[m_rsize] = insertable;
	++m_rsize;
	PercolateUp(m_rsize - 1);
	/*if (GetFlag()){
		std::cout << "adjustHeap-big-----" << m_rsize - 1 << " key= " << insertable.GetKey() << " value= " << insertable.GetValue() << std::endl;
		BigHeapAdjust((m_rsize - 1) / 2);

		}
		else{
		std::cout << "adjustHeap-min-----" << m_rsize - 1 << " key= " << insertable.GetKey() << " value= " <<insertable.GetValue()<< std::endl;
		MinHeapAdjust((m_rsize - 1)/2);
		}*/
}

template<class T, int m_size>
void Heap<T, m_size>::PercolateUp(int index) {
	//BigHeapAdjust(index);
	//std::cout << std::boolalpha << m_flag << std::endl;
	if (m_flag){
		int son = index;
		int parent = (index - 1) / 2;
		while (son != 0){
			if (m_array[son] < m_array[parent]){
				return;
			}
			else{
				std::swap(m_array[son], m_array[parent]);
				son = parent;
				parent = (son - 1) / 2;
			}
		}
	}
	else{
		int son = index;
		int parent = (index - 1) / 2;
		while (son != 0){
			if (m_array[son] > m_array[parent]){
				return;
			}
			else{
				std::swap(m_array[son], m_array[parent]);
				son = parent;
				parent = (son - 1) / 2;
			}
		}
	}
}

template<class T, int m_size>
void Heap<T, m_size>::PercolateDown(int index) {
	if (m_flag){
		int dad = index;
		int son = 2 * dad + 1;
		while (son <= m_rsize){
			if (son + 1 < m_rsize && m_array[son] < m_array[son + 1])
				++son;
			if (m_array[dad] > m_array[son])
				return;
			else{
				std::swap(m_array[dad], m_array[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	}
	else{
		int dad = index;
		int son = 2 * dad + 1;
		while (son <= m_rsize){
			if (son + 1 < m_rsize && m_array[son] > m_array[son + 1])
				++son;
			if (m_array[dad] < m_array[son])
				return;
			else{
				std::swap(m_array[dad], m_array[son]);
				dad = son;
				son = dad * 2 + 1;
			}
		}
	}
}

template<class T, int m_size>
void Heap<T, m_size>::BigHeapAdjust(int index){
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (index <= m_rsize / 2)
	{
		if (lchild < m_rsize && m_array[lchild] > m_array[max])
		{
			max = lchild;
		}
		if (rchild < m_rsize && m_array[rchild] > m_array[max])
		{
			max = rchild;
		}
		if (max != index)
		{
			std::swap(m_array[index], m_array[max]);
			BigHeapAdjust(max);
		}
	}
}


template<class T, int m_size>
void Heap<T, m_size>::MinHeapAdjust(int index){
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	if (index <= m_rsize / 2)
	{
		if (lchild < m_rsize && m_array[lchild] < m_array[max])
		{
			max = lchild;
		}
		if (rchild < m_rsize && m_array[rchild] < m_array[max])
		{
			max = rchild;
		}
		if (max != index)
		{
			std::swap(m_array[index], m_array[max]);
			MinHeapAdjust(max);
		}
	}
}

template<class T, int m_size>
bool Heap<T, m_size>::GetFlag(){
	return m_flag;
}

template<class T, int m_size>
void Heap<T, m_size>::SetFlag(bool flag){
	m_flag = flag;
}


template<typename T, int m_size>
int Heap<T, m_size>::GetSize(){
	return m_rsize;
}

template<typename T, int m_size>
int Heap<T, m_size>::GetArrayKey(int index){
	return m_array[index].GetKey();
}

template<typename T, int m_size>
int Heap<T, m_size>::GetArrayValue(int index){
	return m_array[index].GetValue();
}
#endif /* HEAP_CPP_ */
