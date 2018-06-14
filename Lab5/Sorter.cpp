#include <iostream>
using namespace std;

#include "Sorter.h"

void Sorter::swap(int i, int j) {
   int tmp; 
   tmp = array[i]; 
   array[i] = array[j];
   array[j] = tmp; 
   return;
}

Sorter::Sorter() {
   numElements = 0;
   capacity = 0;
   array = NULL;  
}

Sorter::Sorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   array = new int[capacity]; 
}

unsigned int Sorter::makeSpace(unsigned int newCapacity) {
   int *old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = array; 
      array = new int[newCapacity]; 
      for (i=0; i<numElements; i++) 
         array[i] = old[i]; 
      capacity = newCapacity;
      delete old; 
   }

   return capacity;
}

void Sorter::clear() {
   numElements = 0;
   return; 
}

bool Sorter::insert(int element) {
   if (numElements >= capacity) 
      return false;
   array[numElements++] = element;  
   return true;
}

Sorter::~Sorter() {
   if (array) {
      delete array; 
      numElements = 0; 
   }
}

// Shuffle array elements
void Sorter::shuffle() {
   unsigned int j; 
   for (unsigned int i=1; i<numElements; i++) {
      j = rand() % i; 
      swap(i, j); 
   }
}

// Show the first n elements, k per line, using << 
void Sorter::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << array[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Snsertion Sort
void Sorter::insertionSortI() {
   int j, iNum;
   for(unsigned int i = 0; i < numElements; i++){
	iNum = array[i];
	j = i;
	while((j > 0) && (array[j-1] > iNum)){
		array[j] = array[j-1];
		j = j-1;
	}
	array[j] = iNum;
   }
}

// Iterative Selection Sort
void Sorter::selectionSortI() {
   unsigned int min;
   for(unsigned int i = 0; i < numElements-1; i++){
	min = i;
	for(unsigned int j = i+1; j < numElements; j++){
		if(array[j] < array[min]){
			 min = j;
		}
	}
	swap(i, min);
   }
}

// Iterative Bubble Sort
void Sorter::bubbleSortI() {
   for(int i = (numElements-1); i >= 0; i--){
	for(int j = 1; j <= i; j++){
		if(array[j-1] > array[j]){
			swap(j-1, j);
		}
	}
   }
}
     
// Recursive Insertion Sort
void Sorter::insertionSortR() {
	insertionSortRHelper(numElements);
}

void Sorter::insertionSortRHelper(int length){
  if(length == 1) {
	return;
   }
   insertionSortRHelper(--length);
   recursiveSwap(length);
}

void Sorter::recursiveSwap(int length){
   if(length <= 0) return;
   if (array[length-1] > array[length]){
   	swap(length-1, length);
	recursiveSwap(--length);
   }
}

// Recursive Selection Sort
void Sorter::selectionSortR() {
   selectionSortRHelper(numElements);
}

void Sorter::selectionSortRHelper(int length){
   if(length == 0) return;
   insertionSortRHelper(length--);
   recursiveFindMin(--length);
}

void Sorter::recursiveFindMin(int length){
   if(length < 0) return;
   int prevLength = length;
   if(array[length+1] < array[length]){
	length = length+1;
   }
   swap(prevLength, length);
}
	
// Recursive Bubble Sort
void Sorter::bubbleSortR() {
   bubbleSortRHelper(numElements);
}

void Sorter::bubbleSortRHelper(int length){
   if(length == 0) return;
   bubbleSortRHelper(--length);
   recursiveBubbleSort(length, 1);
}

void Sorter::recursiveBubbleSort(int length, int pos){
   if(length == 1 || pos == 10) return;
   if(array[pos-1] > array[pos]){
      swap(pos-1, pos);
      recursiveBubbleSort(--length, pos);
   }
   pos++;
   recursiveBubbleSort(--length, pos);
}

