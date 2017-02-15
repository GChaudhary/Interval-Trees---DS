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
		if(( high < i.low )||( i.high < low ))		// Non-Intersectin condition
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
			inorderDisplay(root);
	}


	// Inorder Traversal of BST
	//
	// Returns nothing. (Only prints)
	void inorderDisplay(Node *subRoot){
		if(subRoot == NULL)
			return;

		inorderDisplay(subRoot->left);
		cout << (subRoot->interval)->low << " to " << (subRoot->interval)->high << ", \t|| Key: " << subRoot->key << endl;		
		inorderDisplay(subRoot->right);
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
						// Update the 'max' value of 'current' node, if needed
						if( (tempPointer->max) < (i->high) )
							(tempPointer->max) = (i->high);

						// Move to LEFT
						tempPointer = tempPointer->left;
					}
				}
				else{									// In the RIGHT
					if(tempPointer->right == NULL){
						tempPointer->right = new Node(i);
						terminate = 1;
					}
					else{
						// Update the 'max' value of 'current' node, if needed
						if( (tempPointer->max) < (i->high) )
							(tempPointer->max) = (i->high);

						// Move to RIGHT
						tempPointer = tempPointer->right;
					}
				}
			}
		}
		cout << "Node inserted" << endl;
	}



	// Delete in interval 'i' that is 
	// exactly matches with an interval
	// node in the tree. If more than
	// one nodes match then only FIRST
	// matched node is deleted.
	//
	// Returns none
	void remove(Interval i){
		Node *temp = root;
		while(temp != NULL){
			// Check if 'i' equals current node
			if( i.equals(*(temp->interval))){
				// Remove current node

				cout << "Node removed" << endl;
			}
			else if(i.low < (temp->key)) // Move to LEFT sub-tree
			{
				temp = temp->left;
			}
			else	// Move to RIGHT sub-tree
			{
				temp = temp->right;
			}
		}
	}



	// Searches in the BST an interval node
	// which has intersection with given
	// interval. If more than one intervals
	// match (i.e. intersect) then only
	// FIRST found node is returned.
	//
	// Returns the 'interval' that intersect
	// with the given interval 'i'.
	Interval search(Interval i){
		// Interval to be returned
		Interval *result = new Interval(0,0);

		Node *temp = root;
		while( temp != NULL){
			// Check if 'i' intersects with current node
			if(i.intersects(*(temp->interval))){
				*result = *(temp->interval);
				break;
			}
			else if( i.high < (temp->left)->max ){ // Move to LEFTsub-tree
				temp = temp->left;
			}
			else{	// Move to RIGHT sub-tree
				temp = temp->right;
			}
		}

		return *result;
	}


	

	// Finds if the any node in BST exactly
	// matches up with the given node.
	//
	// Returns 'true' if found else 'false'
	bool find(Interval i){
		// Move inOrder to search for interval
		int count = 0;

		Node *temp = root;
		while (temp != NULL){
			// Check if current node interval equal the given interval
			if(i.equals(*(temp->interval))){
				count = count + 1;
				break;
			}
			// Else move to LEFT
			else if(i.low < temp->key)
				temp = temp->left;
			// Else move to RIGHT
			else
				temp = temp->right;
		}

		return (count > 0);
	}


};

// Main function
int main(){

	cout << "Hello Gtm" << endl;


BST *demoIntervalTree = new BST();
demoIntervalTree->display();

Interval *temp = new Interval(3,6);
demoIntervalTree->insert(temp);

temp = new Interval(4,15);
demoIntervalTree->insert(temp);

temp = new Interval(2,9);
demoIntervalTree->insert(temp);

temp = new Interval(3,-9);
demoIntervalTree->insert(temp);

demoIntervalTree->display();

Interval abc(-8,3), cde(1,0);
cout << demoIntervalTree->find(abc) << endl;

Interval result = demoIntervalTree->search(abc);
cout << result.low << " to " << result.high << endl;


//	getch();
	return 0;
}