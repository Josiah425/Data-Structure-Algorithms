#include "BST.h"
#include <iostream>
#include <queue>

template <typename T>
BST<T>::BST(T param){
	this->val = param;
	left = NULL;
	right = NULL;
}

template <typename T>
bool BST<T>::insert(const T &nodeVal){
	BST<T> * traverse;
	BST<T> * previous;
	bool leftOrRight;
	for(traverse = this; traverse != NULL; ){
		previous = traverse;
		if(nodeVal > traverse->val){
			leftOrRight = 1;
			traverse = traverse->right;
		}
		else if(nodeVal < traverse->val){
			leftOrRight = 0;
			traverse = traverse->left;
		}
		else{
			/*std::cout << "Value of "<< nodeVal << " is already in the tree! Did not insert." << std::endl;*/
			return false;
		}
	}
	if(leftOrRight) previous->right = new BST<T>(nodeVal);
	else previous->left = new BST<T>(nodeVal);
	return true;
}

template <typename T>
bool BST<T>::remove(const T &nodeVal){
	if(this->val == nodeVal && this->right == NULL && this->left == NULL){
		return false; //our implementation will not allow root to be removed.
	}
	BST<T> * traverse = this;
	BST<T> * parent = NULL;
	bool leftOrRight; //1 is right, 0 is left from parent of node we are removing not root
	while(traverse != NULL && traverse->val != nodeVal){
		if(nodeVal > traverse->val){
			parent = traverse;
			leftOrRight = 1;
			traverse = traverse->right;
		}
		else if(nodeVal < traverse->val){
			parent = traverse;
			leftOrRight = 0;
			traverse = traverse->left;
		}
	}
	BST<T> * replacement;
	BST<T> * previous2;
	//if we are removing the root, we update it's value and delete the replacement node
	if(!traverse && traverse->val == nodeVal){
		//if the root's right node is not null, we find a successor on right
		if(this->right){
			replacement = this->right;
			previous2 = this;
			while(replacement->left != NULL){
				previous2 = replacement;
				replacement = replacement->left;
			}
			if(previous2 != this) previous2->left = NULL; // we took the left child, so we have to make this null
			this->val = replacement->val;
			if(this->right == replacement) this->right = replacement->right;
			delete replacement;
		}
		//otherwise we find a successor on the left, has to be one of these because we checked at beginning for root having no children.
		else{
			replacement = this->left;
			previous2 = this;
			while(replacement->right != NULL){
				previous2 = replacement;
				replacement = replacement->right;
			}
			if(previous2 != this) previous2->right = NULL; // we took the right child, so we have to make this null	
			this->val = replacement->val;
			if(this->left == replacement) this->left = replacement->left;
			delete replacement;
		}
		return true;
	}
	
	if(traverse == NULL){
		return false;
	}
	//at this point if we dont return false, then traverse is the node we want to remove
	
	//If Node has 2 children that we are removing
	if(traverse->right != NULL && traverse->left != NULL){
		//if node on right subtree
		if(leftOrRight == 1){
			replacement = traverse->left;
			previous2 = traverse;
			while(replacement->right != NULL){
				previous2 = replacement;
				replacement = replacement->right;
			}
			if(previous2 != traverse) previous2->right = NULL; // we took the right child, so we have to make this null
			replacement->right = traverse ->right; //replacement takes the role of the node we are removing
			if(traverse->left != replacement) replacement ->left = traverse ->left; //so it takes the children of the removed node
			if(parent != NULL) parent->right = replacement; //link up old parent with the replacing node.
		}
		//if node on left subtree
		else {
			replacement = traverse->right; 
			previous2 = traverse; 
			while(replacement->left != NULL){
				previous2 = replacement;
				replacement = replacement->left;
			}
			if(previous2 != traverse) previous2->left = NULL; // we took the left child, so we have to make this null
			if(traverse->right != replacement) replacement->right = traverse ->right; //replacement takes the role of the node we are removing
			replacement ->left = traverse ->left; //so it takes the children of the removed node
			if(parent != NULL) parent->left = replacement; //link up old parent with the replacing node.
		}
	}
	//If Node has 1 child
	else if(traverse->left != NULL || traverse->right != NULL){
		if(traverse->left == NULL) replacement = traverse->right;
		else replacement = traverse->left;
		if(leftOrRight == 0 && parent != NULL) parent->left = replacement;
		else if(parent != NULL) parent->right = replacement;
	}
	//If Node has no children
	else{
		if(leftOrRight == 0 && parent != NULL) parent->left = NULL;
		else if(leftOrRight == 1 && parent != NULL) parent->right = NULL;
	}
	delete traverse;
	return true;
}

template <typename T>
bool BST<T>::find(const T &nodeVal) const{
	//if the BST is empty, obviously can't find the node
	if(this == NULL) return false;
	if(this->val == nodeVal) return true;
	BST<T>* search;
	if(this->val > nodeVal) search = this->left; 
	else search = this->right;
	//use search to find the value, if it exists in the BST
	while(search != NULL){
		if(search->val == nodeVal) return true; //we found it!
		//if the value is smaller than the current node, we need to search left subtree
		if(search->val > nodeVal) search = search->left; 
		//if the value is bigger than the current node, search the right subtree
		else search = search->right;
	}
	//if search is NULL, the value was not found
	return false;
}

template <typename T>
void BST<T>::display() const{
	if(this == NULL){ 
		return;
	}
	if(this->left != NULL) this->left->display();
	std::cout << this->val << ' ';
	if(this->right != NULL) this->right->display();
}

//this code is NOT original, modified it from an online source. 
//we needed it to check the behavior of our BST's
//it is a breadth first printing algorithm, which needs a queue to implement effectively
//it will print level by level, and work it's way down from top to bottom.
//see http://www.geeksforgeeks.org/level-order-tree-traversal/ C++ implementation for our 
// motivation
template <typename T>
void BST<T>::printLevelOrder() {
  if (!this) return;
  std::queue<BST<T> *> currentLevel, nextLevel;
  currentLevel.push(this);
  while (!currentLevel.empty()) {
    BST<T> *currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode) {
      std::cout << currNode->val << " ";
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->right);
    }
    else std::cout << "-1" << " ";
    if (currentLevel.empty()) {
      std::cout << std::endl << std::endl;
      swap(currentLevel, nextLevel);
    }
  }
}
