#include <iostream>
#include <algorithm>
using namespace std;

#include "TSorter.h"

template <class T>
void TSorter<T>::swap(typename vector<T>::iterator i, typename vector<T>::iterator j) {
   T temp;
   temp = *i;
   *i = *j;
   *j = temp;
   return; 
}

template <class T>
TSorter<T>::TSorter() {
   numElements = 0;
   capacity = 0;
   myVector.clear();   
}

template <class T>
TSorter<T>::TSorter(unsigned int initialCapacity) {
   capacity = initialCapacity; 
   numElements = 0;
   myVector.reserve(capacity);
}

template <class T>
unsigned int TSorter<T>::makeSpace(unsigned int newCapacity) {
   vector<T> old; 
   unsigned int i;
   if (newCapacity > capacity) {
      old = myVector; 
      myVector.reserve(newCapacity); 
      for (i=0; i < numElements; i++) 
	 myVector[i] = old[i]; 
      capacity = newCapacity;
      vector<T>().swap(old); 
   }

   return capacity;
}

template <class T>
void TSorter<T>::clear() {
   numElements = 0;
   return; 
}

template <class T>
bool TSorter<T>::insert(T element) {
   if (numElements >= capacity) 
      return false;
   myVector.push_back(element); 
   numElements++; 
   return true;
}

template <class T>
TSorter<T>::~TSorter() {
   if (!myVector.empty()) {
      vector<T>().swap(myVector); 
      numElements = 0; 
   }
}

// Shuffle array elements
template <class T>
void TSorter<T>::shuffle() {
   random_shuffle(myVector.begin(), myVector.end());
}

// Show the first n elements, k per line, using <<
template <class T>
void TSorter<T>::show(unsigned int n, unsigned int k) {
   unsigned int toShow = ((n < numElements) ? n : capacity); 
   for (unsigned int i=0; i < toShow; i++) {
      if (!(i%k)) cout << endl;
      cout << myVector[i] << " "; 
   }
   cout << endl << endl;
} 

// Iterative Snsertion Sort
template <class T>
void TSorter<T>::insertionSortI() {
   typename vector<T>::iterator j;
   T iNum;
   for(typename vector<T>::iterator i = myVector.begin(); i < myVector.end(); i++){
	iNum = *i;
	j = i;
	while((j > myVector.begin()) && (*(j-1) > iNum)){
		*j = *(j-1);
		j = j-1;
	}
	*j = iNum;
   }
}

// Iterative Selection Sort
template <class T>
void TSorter<T>::selectionSortI() {
   typename vector<T>::iterator min;
   for(typename vector<T>::iterator i = myVector.begin(); i < myVector.end()-1; i++){
	min = i;
	for(typename vector<T>::iterator j = i+1; j < myVector.end(); j++){
		if(*j < *min){
			 min = j;
		}
	}
	swap(i, min);
   }
}

// Iterative Bubble Sort
template <class T>
void TSorter<T>::bubbleSortI() {
   for(typename vector<T>::iterator i = myVector.end() - 1; i >= myVector.begin(); i--){
	for(typename vector<T>::iterator j = myVector.begin() + 1; j <= i; j++){
		if(*(j-1) > *j){
			swap((j-1), j);
		}
	}
   }
}
     
// Recursive Insertion Sort
template <class T>
void TSorter<T>::insertionSortR() {
	insertionSortRHelper(myVector.end());
}

template <class T>
void TSorter<T>::insertionSortRHelper(typename vector<T>::iterator length){
  if(length == (myVector.begin() + 1)) {
	return;
   }
   insertionSortRHelper(--length);
   recursiveSwap(length);
}

template <class T>
void TSorter<T>::recursiveSwap(typename vector<T>::iterator length){
   if(length <= myVector.begin()) return;
   if (*(length-1) > *length){
   	swap((length-1), length);
	recursiveSwap(--length);
   }
}

// Recursive Selection Sort
template <class T>
void TSorter<T>::selectionSortR() {
   selectionSortRHelper(myVector.end());
}

template <class T>
void TSorter<T>::selectionSortRHelper(typename vector<T>::iterator length){
   if(length == myVector.begin()) return;
   insertionSortRHelper(length--);
   recursiveFindMin(--length);
}

template <class T>
void TSorter<T>::recursiveFindMin(typename vector<T>::iterator length){
   if(length < myVector.begin()) return;
   typename vector<T>::iterator prevLength = length;
   if(*(length+1) < *length){
	*length = *(length+1);
   }
   swap(prevLength, length);
}

template <class T>
void TSorter<T>::bubbleSortR() {
   bubbleSortRHelper(myVector.end());
}

template <class T>
void TSorter<T>::bubbleSortRHelper(typename vector<T>::iterator length){
   if(length == myVector.begin()) return;
   typename vector<T>::iterator pos = myVector.begin() + 1;
   bubbleSortRHelper(--length);
   recursiveBubbleSort(length, pos);
}

template <class T>
void TSorter<T>::recursiveBubbleSort(typename vector<T>::iterator length, typename vector<T>::iterator pos){
   if(length == (myVector.begin() + 1) || pos == myVector.end()) return;
   if(*(pos-1) > *pos){
      swap((pos-1), pos);
      recursiveBubbleSort(--length, pos);
   }
   pos++;
   recursiveBubbleSort(--length, pos);
}
