#include "BST.cpp"
#include <random>
#include<stdio.h>
#include <sys/time.h>
#include <queue>

using namespace std;

void makeBalancedTree(BST<int> *root, int start, int end){
    if(start > end) return;
    int median = (start + end)/2;
    root->insert(median);
    makeBalancedTree(root, start, median-1);
    makeBalancedTree(root, median+1, end);    
}

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(struct timeval *tv)
{
    cout << tv->tv_sec << " sec, " << tv->tv_usec << " micro sec" << endl;
}

int main()
{	
	int j = 100;
	struct timeval tvDiff, tvStart, tvEnd;
	cout << "UNBALANCED WORST CASE! (Linear)" << endl;
	while(j < 200000){
		BST<int> root(0);
		gettimeofday(&tvStart, NULL);
		for(long long int i = 0; i < j; i++){
			root.insert(i);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Build Tree TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		gettimeofday(&tvStart, NULL);
		for(long long int i = 0; i < 20; i++){
			root.find(j+1);
			root.remove(j+1);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Find & Remove TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		j = j << 1;
	}

	j = 100;
	cout << endl << "BALANCE BEST CASE! (Logarithmic)" << endl;
	while(j < 200000){
	//create a balanced tree. code motivated by printLevelOrder
		BST<int> root(j/2);
		gettimeofday(&tvStart, NULL);
		makeBalancedTree(&root, 0, j);
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Build Tree TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		//root.printLevelOrder();
		gettimeofday(&tvStart, NULL);
		for(int i = 0; i < 100000; i++){
			root.find(j+1);
			root.remove(j+1);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Find & Remove TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		j = j << 1;
	}

    	j = 100;
	cout << endl << "RANDOM AVERAGE CASE! (Logarithmic)" << endl;
	while(j < 200000){
		BST<int> root1(rand() % j + 1);
		gettimeofday(&tvStart, NULL);
		for(long long int i = 0; i < j; i++){
			root1.insert(rand() % 100000 + 1);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Build Tree TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		gettimeofday(&tvStart, NULL);
		for(long long int i = 0; i < j; i++){
			root1.find(rand() % j + 1);
			root1.remove(rand() % j + 1);
			root1.insert(rand() % j + 1);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Find & Remove TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		j = j << 1;
	}
}
