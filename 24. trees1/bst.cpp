#include <iostream>
#include <stack>
using namespace std;

class bstree;

class node {
private:
	int data;
	node* left;
	node* right;
public:
	node() {
		data = 0;
		left = NULL;
		right = NULL;
	}
	node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
	int get_data() {
		return data;
	}
	friend class bstree;
};

class bstree {
private:
	node* root;
public:
	bstree() {
		root = NULL;
	}
	void add(int val) {
		// alloc & init new node
		node* newnode = new node(val);
		// if tree is empty (root is null), newnode is root node.
		if (root == NULL) {
			root = newnode;
			return;
		}
		// start traversing from the root
		node* trav = root;
		while (true) {
			// if val is less than trav data
			if (val < trav->data) {
				// if no node in trav left, add newnode there 
				if (trav->left == NULL) {
					trav->left = newnode;
					break;
				}
				//	go to left
				trav = trav->left;
			}
			else { // if val is greater than/equal trav data
				// if no node in trav right, add newnode there
				if (trav->right == NULL) {
					trav->right = newnode;
					break;
				}
				//	go to right
				trav = trav->right;
			}
		}
	}

	node* binsearch(int key) {
		// start searching from root
		node* trav = root;
		// repeat until NULL is reached
		while (trav != NULL) {
			// check if key is found
			if (key == trav->data)
				return trav;
			// check if key is smaller than current
			if (key < trav->data)
				trav = trav->left;
			else // check if key is greater/equal than current
				trav = trav->right;
		}		
		return NULL;
	}

	void preorder() {
		stack<node*> s;
		//1. start traversing from root
		node* trav = root;
		cout << "PRE : ";
		while (trav != NULL || !s.empty()) {
			while (trav != NULL) {
				//2. visit trav
				cout << trav->data << ", ";
				//3. if trav has right, push trav->right on stack
				if (trav->right != NULL)
					s.push(trav->right);
				//4. go to left of trav
				trav = trav->left;
			} //5. repeat 2-5 until trav is null
			//6. pop node from stack into trav
			if (!s.empty()) {
				trav = s.top();
				s.pop();
			}
		} //7. repeat 2-6, until trav is null or stack is empty
		cout << endl;
	}
};


int main() {
	bstree t;
	t.add(50);
	t.add(30);
	t.add(90);
	t.add(10);
	t.add(40);
	t.add(70);
	t.add(100);
	t.add(20);
	t.add(80);
	t.add(60);
	/*
	int val;
	cout << "enter num to search: ";
	cin >> val;
	node *trav = t.binsearch(val);
	if (trav == NULL)
		cout << "Key not found." << endl;
	else
		cout << "Key found: " << trav->get_data() << endl;
	*/
	t.preorder();
	return 0;
}

