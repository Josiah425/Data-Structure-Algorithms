using namespace std;

#include "Fraction.h"
#include "TSorter.cpp"

#define DEFAULT_NUMVALUES 10
#define MAX_NUMVALUES 1000
#define MIN_NUMVALUES 1

int main (int argc, char **argv) {
   unsigned int numValues = DEFAULT_NUMVALUES; 
   //double value;

   if (argc > 1)
      numValues = atoi(argv[1]);
   if ((numValues < MIN_NUMVALUES) || (numValues > MAX_NUMVALUES)) {
      cerr << "Specify numValues in the range [" << MIN_NUMVALUES; 
      cerr << ", " << MAX_NUMVALUES << endl; 
      cerr << "\nUsage: " << argv[0] << " {numValues}" << endl; 
   }
   if (argc > 2) 
      cerr << "Ignoring extra command line arguments." << endl; 

   cout << endl << "Generating " << numValues << " values for sorting." << endl; 
   TSorter<string> s;
   TSorter<int> i;
   TSorter<Fraction> f;
   i.makeSpace(numValues);
   f.makeSpace(numValues);
   s.makeSpace(numValues);
   srand(time(NULL)); // use this line for pseudo-random numbers 
   // srand(23);      // use this line for deterministic "random" numbers
   int value;
   for (unsigned int k=0; k < numValues; k++) {
      value = rand() % 100;  
      i.insert(value);
   }
   f.insert(Fraction(7, 8));
   f.insert(Fraction(8, 7));
   f.insert(Fraction(12, 5));
   f.insert(Fraction(13, 5));
   f.insert(Fraction(2, 4));
   f.insert(Fraction(3, 5));
   f.insert(Fraction(9, 10));
   f.insert(Fraction(11, 10));
   f.insert(Fraction(15, 3));
   f.insert(Fraction(9, -1));
   s.insert("Hello");
   s.insert("Apples");
   s.insert("Banana");
   s.insert("Chicken");
   s.insert("hello");
   s.insert("apples");
   s.insert("chicken");
   s.insert("banana");
   s.insert("Xenophobia");
   s.insert("CS240");

   cout << "STRING CLASS" << endl;

   cout << "Initial array: ";
   s.show(25, 10); 

   s.insertionSortI();
   cout << "After iterative Insertion Sort:";
   s.show(25, 10);

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortI();
   cout << "After iterative Selection Sort:";
   s.show(25,10);

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.insertionSortR();
   cout << "After recursive Insertion Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.selectionSortR();
   cout << "After recursive Selection Sort:";
   s.show(25, 10); 

   s.shuffle(); 
   cout << "Shuffled: "; 
   s.show(25, 10); 

   s.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   s.show(25, 10); 

   cout << endl << endl << endl;

   cout << "INT CLASS" << endl;

   cout << "Initial array: ";
   i.show(25, 10); 

   i.insertionSortI();
   cout << "After iterative Insertion Sort:";
   i.show(25, 10);

   i.shuffle(); 
   cout << "Shuffled: "; 
   i.show(25, 10); 

   i.selectionSortI();
   cout << "After iterative Selection Sort:";
   i.show(25,10);

   i.shuffle(); 
   cout << "Shuffled: "; 
   i.show(25, 10); 

   i.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   i.show(25, 10); 

   i.shuffle(); 
   cout << "Shuffled: "; 
   i.show(25, 10); 

   i.insertionSortR();
   cout << "After recursive Insertion Sort:";
   i.show(25, 10); 

   i.shuffle(); 
   cout << "Shuffled: "; 
   i.show(25, 10); 

   i.selectionSortR();
   cout << "After recursive Selection Sort:";
   i.show(25, 10); 

   i.shuffle(); 
   cout << "Shuffled: "; 
   i.show(25, 10); 

   i.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   i.show(25, 10); 

   cout << endl << endl << endl;

   cout << "FRACTION CLASS" << endl;

   cout << "Initial array: ";
   f.show(25, 10); 

   f.insertionSortI();
   cout << "After iterative Insertion Sort:";
   f.show(25, 10);

   f.shuffle(); 
   cout << "Shuffled: "; 
   f.show(25, 10); 

   f.selectionSortI();
   cout << "After iterative Selection Sort:";
   f.show(25,10);

   f.shuffle(); 
   cout << "Shuffled: "; 
   f.show(25, 10); 

   f.bubbleSortI();
   cout << "After iterative Bubble Sort:";
   f.show(25, 10); 

   f.shuffle(); 
   cout << "Shuffled: "; 
   f.show(25, 10); 

   f.insertionSortR();
   cout << "After recursive Insertion Sort:";
   f.show(25, 10); 

   f.shuffle(); 
   cout << "Shuffled: "; 
   f.show(25, 10); 

   f.selectionSortR();
   cout << "After recursive Selection Sort:";
   f.show(25, 10); 

   f.shuffle(); 
   cout << "Shuffled: "; 
   f.show(25, 10); 

   f.bubbleSortR();
   cout << "After recursive Bubble Sort:";
   f.show(25, 10); 


}

