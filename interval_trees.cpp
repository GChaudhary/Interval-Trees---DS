#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;

// Implementing 'node' class
class Node{
public:
	// Key of this node
	int key;

	// Left and Right pointers to this node
	Node *left, *right;

	// Constructor Method
	Node(int key = 0){
		this->key = key;
		this->left = NULL;
		this->right = NULL;
	}

	// Destructor
	~Node(){

	}
	
};

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

// Main function
int main(){

	cout << "Hello Gtm" << endl;

	Interval temp(1, 4), demo(1,1);
	cout << temp.low << " " << temp.high << endl;
	cout << demo.low << " " << demo.high << endl;

	cout << temp.equals(demo) << endl << endl;
	Interval common = temp.intersection(demo);
	cout << common.low << " " << common.high << endl;
	

	getch();
	return 0;
}