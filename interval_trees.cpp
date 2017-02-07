#include <iostream>
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


// Main function
int main(){

	cout << "Hello Gtm" << endl;


	getch();
	return 0;
}