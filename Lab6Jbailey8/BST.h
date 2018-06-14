
template <typename T>

class BST{
public:
	BST(T nodeVal);
	bool insert(const T &nodeVal);
	bool remove(const T &nodeVal);
	bool find(const T &nodeVal) const;
	void display() const; //we shouldn't need parameters for this display function.
	void printLevelOrder(); //this method was found from an online source. see implementation for details
	T val;
	BST<T> * left;
	BST<T> * right;
};
