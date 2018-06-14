#include "threeary.h"
#include <iostream>
#include <queue>

template <typename T>
threeary<T>::threeary(){
	this->val1 = -1;
	this->val2 = -1;
	oneFull = 0;
	twoFull = 0;
	left = NULL;
	middle = NULL;
	right = NULL;
}

template <typename T>
threeary<T>::threeary(T param){
	this->val1 = param;
	this->val2 = -1;
	oneFull = 1;
	twoFull = 0;
	left = NULL;
	middle = NULL;
	right = NULL;
}

template <typename T>
bool threeary<T>::insert(const T &nodeVal){
	threeary<T> * traverse;
	threeary<T> * previous;
	int leftMiddleRight; //left = 0 middle = 1 right = 2
	for(traverse = this; traverse != NULL; ){
		previous = traverse;
		if(traverse->oneFull == 0) {
			traverse->val1 = nodeVal;
			traverse->oneFull = 1;
			return true;
		}
		else if(traverse->twoFull == 0 && traverse->val1 != nodeVal){
			traverse->val2 = nodeVal;
			traverse->twoFull = 1;
			return true;
		}
		else if(nodeVal > traverse->val1 && nodeVal > traverse->val2){
			leftMiddleRight = 2;
			traverse = traverse->right;
		}
		else if(nodeVal < traverse->val1 && nodeVal < traverse->val2){
			leftMiddleRight = 0;
			traverse = traverse->left;
		}
		else if((nodeVal > traverse->val1 && nodeVal < traverse->val2) || (nodeVal > traverse->val2 && nodeVal < traverse->val1)){
			leftMiddleRight = 1;
			traverse = traverse->middle;
		}
		else if(nodeVal == traverse->val1 && traverse->oneFull == false){
			traverse->oneFull = true;
			return true;
		}
		else if(nodeVal == traverse->val2 && traverse->twoFull == false){
			traverse->twoFull = true;
			return true;
		}
		else{
			//std::cout << "Value of "<< nodeVal << " is already in the tree! Did not insert." << std::endl;
			return false;
		}
	}
	if(leftMiddleRight == 0) previous->left = new threeary<T>(nodeVal);
	else if(leftMiddleRight == 1) previous->middle = new threeary<T>(nodeVal);
	else previous->right = new threeary<T>(nodeVal);
	return true;
}
 
//TODO: update values one at a time, working our way down the tree. 
    //prioritize middle, then right, then left. 
    //1.) if there is a middle subtree, want middle's min or max
    //a.) want mid's minimum if we are getting rid of smaller value in update node
    //b.) want mid's maximum if we are getting rid of larger value in update node
    //2.) otherwise, if theres a right subtree, want right subtree's minimum
    //3.) otherwise, if there is a left subtree, want left's maximum
    //this may not be correct, but it is what we have discussed thus far. we could do this recursively but would limit the tree size we could get based off the stack overflow issue
template <typename T>
void threeary<T>::recursiveRemove(threeary<T>* parent, threeary<T> * update, const T &nodeVal, int leftMidRight){
	//BASE CASE	
	if(update->left == NULL && update->right == NULL && update->middle == NULL){
		if(update->val1 == nodeVal){
		    update->oneFull = false;
		    if(update->twoFull == false){
			    if(parent != update){
				if(leftMidRight == 0) parent->left = NULL;
				else if(leftMidRight == 1) parent->middle = NULL;
				else if(leftMidRight == 2) parent->right = NULL;    
			    }
			    delete update;
		    }
		    return;    
		}
		update->twoFull = false;
		if(update->oneFull == false){
			 if(parent != update){
			     if(leftMidRight == 0) parent->left = NULL;
			     else if(leftMidRight == 1) parent->middle = NULL;
			     else if(leftMidRight == 2) parent->right = NULL;    
			 }
			 delete update;
		}
		return;         
        }
	//removing bigger value in node
	if((nodeVal == update->val1 && update->val1 > update->val2) || (nodeVal == update->val2 && update->val2 > update->val1)){
		bool largeOrSmall; // 0 large, 1 small		
		//need to find max of middle subtree
		threeary<T>* replacement;
		threeary<T>* replacementParent;		
		if(update->middle != NULL){
			replacementParent = update;
			replacement = update->middle;
			leftMidRight = 1;
			largeOrSmall = 0;
		}
		//need the minimum of right subtree
		else if(update->right != NULL){
			replacementParent = update;
			replacement = update->right;
			leftMidRight = 2;
			largeOrSmall = 1;
		}
		//need max of left subtree
		else{	
			replacementParent = update;
			replacement = update->left;
			leftMidRight = 0;
			largeOrSmall = 0;
		}
		while((largeOrSmall == 0 && replacement->right != NULL) || (largeOrSmall == 1 && replacement->left != NULL)){
			//finding largest replacement
			if(largeOrSmall == 0){
				if(replacement->right != NULL){
					replacementParent = replacement;
					leftMidRight = 2;
					replacement = replacement->right;
				}
			}
			//finding smallest replacement
			else{
				if(replacement->left != NULL){
					replacementParent = replacement;
					leftMidRight = 0;					
					replacement = replacement->left;
				}
			}
		}
		//check if val1 is greater than val2
		int max;
		if(replacement->val1 > replacement->val2 && replacement->oneFull == true) max = replacement->val1;
		else max = replacement->val2;
		//if we want to set the update val to larger val
			if(largeOrSmall == 0){
				if(update->oneFull == false){
					update->val1 = max;
					update->oneFull = true;
					if(replacement->val1 == max) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val1, leftMidRight); 
				}
				else{
					update->val2 = max;
					update->twoFull = true;
					if(replacement->val1 == max) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val2, leftMidRight);
				}
			}
			//if we want to set the update val to smaller val
			else{
				int min;
				if(replacement->val1 > replacement->val2 && replacement->twoFull == true) min = replacement->val2;
				else min = replacement->val1;
				if(update->oneFull == false){
					update->val1 = min;
					update->oneFull = true;
					if(replacement->val1 == min) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val1, leftMidRight);
				}
				else{
					update->val2 = min;
					update->twoFull = true;
					if(replacement->val1 == min) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val2, leftMidRight);
				}
			}

		}
	//removing smaller value in node
	else{
		bool largeOrSmall; // 0 large, 1 small		
		//need to find minimum of middle subtree
		threeary<T>* replacement;
		threeary<T>* replacementParent;		
		if(update->middle != NULL){
			replacementParent = update;
			replacement = update->middle;
			leftMidRight = 1;
			largeOrSmall = 1;
		}
		//need the maximum of left subtree
		else if(update->left != NULL){
			replacementParent = update;
			replacement = update->left;
			leftMidRight = 0;
			largeOrSmall = 0;
		}
		//need min of right subtree
		else{	
			replacementParent = update;
			replacement = update->right;
			leftMidRight = 2;
			largeOrSmall = 1;
		}
		while((largeOrSmall == 0 && replacement->right != NULL) || (largeOrSmall == 1 && replacement->left != NULL)){
			//finding largest replacement
			if(largeOrSmall == 0){
				if(replacement->right != NULL){
					replacementParent = replacement;
					leftMidRight = 2;
					replacement = replacement->right;
				}
			}
			//finding smallest replacement
			else{
				if(replacement->left != NULL){
					replacementParent = replacement;
					leftMidRight = 0;					
					replacement = replacement->left;
				}
			}
		}
		//find max
		int max;
		if(replacement->val1 > replacement->val2 && replacement->oneFull == true) max = replacement->val1;
		else max = replacement->val2;
			//if we want to set the update val to larger val
			if(largeOrSmall == 0){
				if(update->oneFull == false){
					update->val1 = max;
					update->oneFull = true;
					if(replacement->val1 == max) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val1, leftMidRight); 
				}
				else{
					update->val2 = max;
					update->twoFull = true;
					if(replacement->val1 == max) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val2, leftMidRight);
				}
			}
			//if we want to set the update val to smaller val
			else{
				int min;
				if(replacement->val1 > replacement->val2 && replacement->twoFull == true) min = replacement->val2;
				else min = replacement->val1;
				if(update->oneFull == false){
					update->val1 = min;
					update->oneFull = true;
					if(replacement->val1 == min) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val1, leftMidRight);
				}
				else{
					update->val2 = min;
					update->twoFull = true;
					if(replacement->val1 == min) replacement->oneFull = false;
					else replacement->twoFull = false;
					recursiveRemove(replacementParent, replacement, update->val2, leftMidRight);
				}
			}
		}
}

template <typename T>
bool threeary<T>::remove(const T &nodeVal){
    //if pointer is NULL, no point in continuing. (this shouldn't happen)
    if(this == NULL) return false;
    //handle lone root case first
    if(this->left == NULL && this->middle == NULL && this->right == NULL){
        //if the root has no values, tree is empty. return nothing removed
        if(this->oneFull == false && this->twoFull == false) return false;
         //if first val is being removed, do so
        if(this->oneFull == true && this->val1 == nodeVal){
                this->oneFull = false;
                return true; 
        }
        //if second val is being removed, do so
        if(this->twoFull == true && this->val2 == nodeVal){
            this->twoFull = false;
            return true;    
        }
        //root has values, but not the one trying to be removed
        return false;            
    }
    //now, we need to start by seeing if the value is actually in the tree to be removed.
    threeary<T>* update = this;
    threeary<T>* parent = this;
    int leftMidRight = -5; //0 left, 1 middle, 2 right
    while(update != NULL){
	if(update->oneFull == false || update->twoFull == false){
	    if(update->oneFull == true && update->val1 == nodeVal) {
		break;
	    }
	    if(update->twoFull == true && update->val2 == nodeVal) {
		break;
	    }
	    return false;
	}
	if(update->val1 == nodeVal || update->val2 == nodeVal) break;
	else if (nodeVal > update->val1 && nodeVal > update->val2) {
	    parent = update;
	    update = update->right;
	    leftMidRight = 2;
	}
	else if (nodeVal < update->val1 && nodeVal < update->val2){
	    parent = update;
	    update = update->left;
	    leftMidRight = 0;
	}
	else if ((nodeVal > update->val1 && nodeVal < update->val2) || (nodeVal < update->val1 && nodeVal > update->val2)){
	    parent = update;
	    update = update->middle;
	    leftMidRight = 1;
	}
    }
    if(update == NULL) return false;
    //note: update is a pointer to the node which has the value to be removed. (need to update it)
    //now that we found the node, handle cases

    //no children
    // I CHANGED THIS SO U DELETE UPDATE AT THE END
    if(update->left == NULL && update->right == NULL && update->middle == NULL){
        if(update->oneFull == true && update->val1 == nodeVal){
            update->oneFull = false;
            if(update->twoFull == false){
		    if(parent != update){
		        if(leftMidRight == 0) parent->left = NULL;
		        else if(leftMidRight == 1) parent->middle = NULL;
		        else if(leftMidRight == 2) parent->right = NULL;    
		    }
		    delete update;
	    }
            return true;    
        }
        update->twoFull = false;
        if(update->oneFull == false){
		 if(parent != update){
		     if(leftMidRight == 0) parent->left = NULL;
		     else if(leftMidRight == 1) parent->middle = NULL;
		     else if(leftMidRight == 2) parent->right = NULL;    
		 }
		 delete update;
	}
        return true;         
    }
	//before we call recursive remove, set the value to remove's bool to false
	if(update->val1 == nodeVal) update->oneFull = false;
	else update->twoFull = false;
       	recursiveRemove(parent, update, nodeVal, leftMidRight);
	return true; 
}

template <typename T>
bool threeary<T>::find(const T &nodeVal){
	if(this == NULL) return false;
	threeary<T> *traverse = this;
	while(traverse != NULL){
        //if the node has an empty slot, it can't have children.
        if(traverse->oneFull == false || traverse->twoFull == false){
            if((traverse->oneFull == true) && (traverse->val1 == nodeVal)) return true;
            if((traverse->twoFull == true) && (traverse->val2 == nodeVal)) return true;
            return false;
        }
		if(traverse->val1 == nodeVal || traverse->val2 == nodeVal) return true;
		else if (nodeVal > traverse->val1 && nodeVal > traverse->val2) traverse = traverse->right;
		else if (nodeVal < traverse->val1 && nodeVal < traverse->val2) traverse = traverse->left;
		else if ((nodeVal > traverse->val1 && nodeVal < traverse->val2) || (nodeVal < traverse->val1 && nodeVal > traverse->val2)) traverse = traverse->middle;
	}
	return false;
}

template <typename T>
void threeary<T>::display() const{
	if(this == NULL){ 
		return;
	}
	if(this->left != NULL) this->left->display();
	if(this->middle != NULL) this->middle->display();
	if(this->oneFull == 1) std::cout << this->val1 << ' ';
	if(this->twoFull == 1) std::cout << this->val2 << '|';
	else{
		std::cout << " |";
	}
	if(this->right != NULL) this->right->display();
}

//this code is NOT original, modified it from an online source. 
//we needed it to check the behavior of our threeary's
//it is a breadth first printing algorithm, which needs a queue to implement effectively
//it will print level by level, and work it's way down from top to bottom.
//see http://www.geeksforgeeks.org/level-order-tree-traversal/ C++ implementation for our 
// motivation
template <typename T>
void threeary<T>::printLevelOrder() {
  if (!this) return;
  std::queue<threeary<T> *> currentLevel, nextLevel;
  currentLevel.push(this);
  while (!currentLevel.empty()) {
    threeary<T> *currNode = currentLevel.front();
    currentLevel.pop();
    if (currNode) {
      if(currNode->oneFull) std::cout << currNode->val1 << " ";
      if(currNode->twoFull) std::cout << currNode->val2 << " |";
      else std::cout << " E |";
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->middle);
      nextLevel.push(currNode->right);
    }
    else std::cout << " |" << " ";
    if (currentLevel.empty()) {
      std::cout << std::endl << std::endl;
      swap(currentLevel, nextLevel);
    }
  }
}
