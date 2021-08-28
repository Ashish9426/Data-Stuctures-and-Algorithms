#include <iostream>
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

	void preorder(node* trav) {
		if (trav == NULL)
			return;
		cout << trav->data << ", ";
		preorder(trav->left);
		preorder(trav->right);
	}

	void preorder() {
		cout << "PRE: ";
		preorder(root);
		cout << endl;
	}
};


int main() {
	bstree t;
	t.add(50);
	t.add(20);
	t.add(10);
	t.add(5);
	t.add(25);
	t.add(30);
	t.add(70);
	t.add(90);
	t.add(60);
	t.preorder();
	return 0;
}

