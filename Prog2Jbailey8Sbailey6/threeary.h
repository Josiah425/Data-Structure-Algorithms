
template <typename T>

class threeary{
public:
	threeary();
	threeary(T nodeVal);
	bool insert(const T &nodeVal);
	bool remove(const T &nodeVal);
	bool find(const T &nodeVal);
	void recursiveRemove(threeary<T>* parent, threeary<T> * update, const T &nodeVal, int leftMidRight);
	void display() const; //we shouldn't need parameters for this display function.
	void printLevelOrder(); //this method was found from an online source. see implementation for details
	T val1;
	T val2;
	bool oneFull;
	bool twoFull;
	threeary<T> * left;
	threeary<T> * middle;
	threeary<T> * right;
};
