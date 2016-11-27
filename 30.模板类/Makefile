#!/bin/bash
#Makefile:
CXX=g++
CXXFLAG=-Wall -g 
BIN=Driver.o Heap.o MaxHeap.o MinHeap.o PinHit.o
driver.out:${BIN}
	$(CXX) $(CXXFLAG) $^ -o $@
${BIN}:%.o:%.cpp
	$(CXX) $(CXXFLAG) -c $< -o $@

.PHONY:clean
clean:
	rm -f *.o driver.out
