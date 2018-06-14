#include "threeary.cpp"
#include <random>
#include<stdio.h>
#include <sys/time.h>
#include <queue>
#include <math.h>

using namespace std;

/*void makeBalancedTree(threeary<int> *root, int start, int end, int n){
    if(start >= end) return;
    //std::cout << n << ' ' << start << ' ' << end << std::endl;
    int newStart = start;
    int newEnd = end;
    if(n == 0){
	    newStart = start;
	    newEnd = (end-start)/3.0;
	    root->insert((end+start)/3);
            root->insert(ceil(end - (end+start)/3.0));
	    makeBalancedTree(root, newStart, newEnd, 0);
    }
    else if(n == 1){
            newStart = floor((end-start)/3.0) + start;
            newEnd = end - (end-start)/3;
	    if(root->insert(newStart) == false && root->insert(newEnd) == false) return;
	    makeBalancedTree(root, newStart, newEnd, 1);
    }
    else if(n == 2){
	    newStart = end - floor((end-start)/3.0);
	    newEnd = end;
	    root->insert((end-start)/3 + start);
            root->insert(end - (end-start)/3);
	    std::cout << ((end-start)/3 + start) << ' ' << (end - (end-start)/3) << std::endl;
	    makeBalancedTree(root, newStart, newEnd, 2);
    }
    else{
	    makeBalancedTree(root, newStart, newEnd, 1);
	    //makeBalancedTree(root, newStart, newEnd, 0);
	    //makeBalancedTree(root, newStart, newEnd, 2);
    }
}*/

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
	while(j < 50000){
		threeary<int> root(0);
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

	/*cout << endl << "BALANCE BEST CASE! (Logarithmic)" << endl;
	while(j < 200000){
	//create a balanced tree. code motivated by printLevelOrder
		threeary<int> root(j/3);
		gettimeofday(&tvStart, NULL);
		makeBalancedTree(&root, 0, j);
		gettimeofday(&tvEnd, NULL);
		//root.printLevelOrder();
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
	}*/

    	j = 100;
	cout << endl << "RANDOM AVERAGE CASE! (Logarithmic) (Apparently counts as balanced)" << endl;
	while(j < 50000){
		threeary<int> root1(rand() % j + 1);
		gettimeofday(&tvStart, NULL);
		for(long long int i = 0; i < j; i++){
			root1.insert(rand() % j + 1);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Build Tree TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		gettimeofday(&tvStart, NULL);
		for(long long int i = 0; i < 20; i++){
			int n = rand() % j + 1;
			root1.find(n);
			root1.remove(n);
			root1.insert(n);
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff, &tvEnd, &tvStart);
		cout << "Find & Remove TimeVal " << j << ": ";
		timeval_print(&tvDiff);
		j = j << 1;
	}
}
