#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
public:
	node() {
		data = 0;
		next = NULL;
	}
	node(int val) {
		data = val;
		next = NULL;
	}
};

class singly_list {
private:
	node* head;
public:
	singly_list() {
		head = NULL;
	}
	void add_first(int val) {
		node* newnode = new node(val);
		newnode->next = head;
		head = newnode;
	}
	void add_last(int val) {
		node* newnode, * trav;
		// alloc new node and init it
		newnode = new node(val);
		// special case: if list is empty, newnode itself is first node
		if (head == NULL)
			head = newnode;
		else {
			// traverse till last node
			trav = head;
			while (trav->next != NULL)
				trav = trav->next;
			// add new node to the next of last node
			trav->next = newnode;
		}
	}
	void add_at_pos(int pos, int val) {
		node* newnode, * trav;
		// special2: user give pos = 1 or less than that
		if (pos <= 1) {
			add_first(val);
			return;
		}
		// alloc node and init it
		newnode = new node(val);
		// special1: if list is empty, new node is first node
		if (head == NULL) {
			head = newnode;
			return;
		}
		// trav till pos-1
		trav = head;
		for (int i = 1; i < pos - 1; i++) {
			// special3: if pos is beyond size of list
			if (trav->next == NULL)
				break;
			trav = trav->next;
		}
		// newnode'next to trav's next
		newnode->next = trav->next;
		// previous (trav) 'next to newnode
		trav->next = newnode;
	}
	void display() {
		cout << "LIST: ";
		node* trav = head;
		while (trav != NULL) {
			cout << trav->data << ", ";
			trav = trav->next;
		}
		cout << endl;
	}
};

int main() {
	singly_list l1;
	l1.add_last(10);
	l1.add_last(20);
	l1.add_last(30);
	l1.add_first(40);
	l1.add_at_pos(3, 50);
	l1.add_at_pos(1, 60);
	l1.add_at_pos(8, 70);
	l1.display();
	return 0;
}


