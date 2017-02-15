#include <iostream>
#include <algorithm>
//#include <conio.h>

using namespace std;




// Interval Class
class Interval{
public:
	// Interval Parameters
	int low, high;
	int duration;

	// Constructor
	Interval(int low, int high){
		if(low <= high){
			this->low = low;
			this->high = high;
			this->duration = (high - low);
		}
		else{
			this->low = high;
			this->high = low;
			this->duration = (low - high);
		}
	}

	// Check if two intervals have 'intersection'
	bool intersects(Interval i){
		if(( high < i.low )||( i.high < low ))
			return false;
		return true;
	}

	// Check if two intervals are 'equal'
	bool equals(Interval i){
		if(( low == i.low )&&( i.high == high ))
			return true;
		return false;
	}

	// Return the 'intersection' of two intervals
	Interval intersection(Interval i){
		int array[] = {low, high, i.low, i.high};
		sort(array, array + 4);

		Interval intersectionInterval(array[1], array[2]);	// Common interval is from 2nd to 3rd element
		return intersectionInterval;
	}
};

// Implementing 'node' class
class Node{
public:
	// Key of this node
	int key;

	// Augmented Data
	Interval *interval;
	int max;

	// Left and Right pointers to this node
	Node *left, *right;

	// Constructor Method
	Node(Interval *i){  			// Initialization of -
		this->interval = i;			// Interval
		this->max = i->high;			// 'max' end of interval
		this->key = i->low;			// 'key' of tree
		this->left = NULL;			// 'left' pointer
		this->right = NULL;			// 'right' pointer
	}

	// Destructor
	~Node(){

	}
	
};

// Implementing the Binary Search Tree
class BST{
public:
	// Handle of 'BST'
	Node *root;

	// Constructor
	BST(){
		root = NULL;
	}


	// Returns 'true' if tree is EMPTY
	bool isEmpty(){
		return (root == NULL);
	}

	// Dictionary Operations

	// Display the BST
	//
	// Returns nothing. (Only prints)
	void display(){
		if(isEmpty())
			cout << "Tree is EMPTY" << endl;
		else
			inorder(root);
	}


	// Inorder Traversal of BST
	//
	// Returns nothing. (Only prints)
	void inorder(Node *subRoot){
		if(subRoot == NULL)
			return;

		inorder(subRoot->left);
		cout << (subRoot->interval)->low << " to " << (subRoot->interval)->high << ", \t|| Key: " << subRoot->key << endl;		
		inorder(subRoot->right);
	}


	// Insert an interval 'i' to the BST
	// keyed with lower end of interval.
	//
	// Returns none.
	void insert(Interval *i){
		if( root == NULL){	// If the tree is EMPTY
			root = new Node(i);
		}
		else{				// If the tree is NON-EMPTY
			Node *tempPointer = root;

			int terminate = 0;
			// Traverse to the last node where
			// new node is to be added (similar
			// to insertion in binary tree).
			while(terminate != 1){
				if((i->low) < (tempPointer->key)){		// In the LEFT
					if(tempPointer->left == NULL){
						tempPointer->left = new Node(i);
						terminate = 1;
					}
					else{
						tempPointer = tempPointer->left;
					}
				}
				else{									// In the RIGHT
					if(tempPointer->right == NULL){
						tempPointer->right = new Node(i);
						terminate = 1;
					}
					else{
						tempPointer = tempPointer->right;
					}
				}
			}
		}
	}



	// Delete in interval 'i' that is 
	// exactly matches with an interval
	// node in the tree. If more than
	// one nodes match then only FIRST
	// matched node is deleted.
	//
	// Returns none
	void remove(Interval i);



	// Searches in the BST an interval node
	// which has intersection with given
	// interval. If more than one intervals
	// match (i.e. intersect) then only
	// FIRST found node is returned.
	//
	// Returns the intersection of two intervals
	Interval search(Interval i);

	

	// Finds if the any node in BST exactly
	// matches up with the given node.
	//
	// Returns 'true' if found else 'false'
	bool find(Interval i){
		// Move inOrder to search for interval
		int count = 0;
		if(!isEmpty()){ 	//Tree is not empty
			inorderFind(root, i, &count);
		}

		return (count > 0);
	}


	// Inorder Traversal of BST for FIND
	//
	// Returns nothing. (Only prints)
	void inorderFind(Node *subRoot, Interval i, int *count){
		if(subRoot == NULL)
			return;

		inorderFind(subRoot->left, i, count);
		if(i.equals(*(subRoot->interval)))
			*count = *count + 1;
		inorderFind(subRoot->right, i, count);
	}


};

// Main function
int main(){

	cout << "Hello Gtm" << endl;


BST *demoIntervalTree = new BST();
demoIntervalTree->display();

Interval *temp = new Interval(3,6);
demoIntervalTree->insert(temp);

temp = new Interval(4,5);
demoIntervalTree->insert(temp);

temp = new Interval(2,9);
demoIntervalTree->insert(temp);

temp = new Interval(3,-9);
demoIntervalTree->insert(temp);

demoIntervalTree->display();

Interval abc(2,9);
cout << demoIntervalTree->find(abc) << endl;
//	getch();
	return 0;
}