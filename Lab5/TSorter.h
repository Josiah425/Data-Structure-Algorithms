#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <cstdlib>

template <class T> 
class TSorter{
  private:
      vector<T> myVector; 
      unsigned int numElements;
      unsigned int capacity;

      void swap(typename vector<T>::iterator i, typename vector<T>::iterator j); 

  public:
      TSorter();
      TSorter(unsigned int initialCapacity);
      ~TSorter();

      void clear(); 
      bool insert(T value); 

      // Make sure the array contains at least newCapacity elements.
      // If not, grow it to that size and copy in old values
      unsigned int makeSpace(unsigned int newCapacity); 

      // Show the first n elements, k per line using << 
      void show(unsigned int n, unsigned int k); 

      // "Shuffle" the array elements
      void shuffle(); 

      // These are the functions you should implement for Lab 5
      // You should keep these interfaces the same, but you may add
      // other "helper" functions if necessary.
      void insertionSortI();
      void selectionSortI();
      void bubbleSortI();     
      void insertionSortR(); 
      void selectionSortR();	
      void bubbleSortR(); 

      void insertionSortRHelper(typename vector<T>::iterator length);
      void recursiveSwap(typename vector<T>::iterator length);

      void selectionSortRHelper(typename vector<T>::iterator length);
      void recursiveFindMin(typename vector<T>::iterator length);

      void bubbleSortRHelper(typename vector<T>::iterator length);
      void recursiveBubbleSort(typename vector<T>::iterator length, typename vector<T>::iterator pos);
};
