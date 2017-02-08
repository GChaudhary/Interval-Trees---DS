#include <iostream>
#include <algorithm>
#include <conio.h>

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

	// Dictionary Operations

	// Insert an interval 'i' to the BST
	// keyed with lower end of interval.
	//
	// Returns none.
	void insert(Interval i);



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
	void find(Interval i);

};

// Main function
int main(){

	cout << "Hello Gtm" << endl;

Interval temp(32,2);
cout << temp.low << " " << temp.high << endl;
Node node(&temp);
cout << node.key << " " << node.max << endl;

	getch();
	return 0;
}