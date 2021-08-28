#include <iostream>
using namespace std;

class circular_list; // forward declaration class

class node {
private:
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
	friend class circular_list;
};

class circular_list {
private:
	node* tail;
public:
	circular_list() {
		tail = NULL;
	}
	void display() {
		cout << "LIST: ";
		if (tail != NULL) {
			node* trav = tail->next;
			do {
				cout << trav->data << ", ";
				trav = trav->next;
			} while (trav != tail->next);
		}
		cout << endl;
	}
	void add_last(int val) {
		node* newnode, * trav;
		// alloc new node and init it
		newnode = new node(val);
		// special case: if list is empty, newnode itself is first node
		if (tail == NULL) {
			tail = newnode;
			newnode->next = tail;
		} else {
            // add node after tail and adjust tail
			newnode->next = tail->next;
			tail->next = newnode;
            tail = newnode;
		}
	}
    void add_first(int val) {
		node* newnode, * trav;
		// alloc new node and init it
		newnode = new node(val);
		// special case: if list is empty, newnode itself is first node
		if (tail == NULL) {
			tail = newnode;
			newnode->next = tail;
		} else {
            // add node after tail
			newnode->next = tail->next;
			tail->next = newnode;
		}
	}
	void del_first() {
		node* temp;
		// special1: if list empty, return
		if (tail == NULL)
			return;
		// special2: if single node, delete it.
		if (tail->next == tail) {
			delete tail;
			tail = NULL;
			return;
		}
		// take first node addr in temp
		temp = tail->next;
		// tail next point to new head
		tail->next = temp->next;
		// delete the temp
		delete temp;
	}
	~circular_list() {
		del_all();
	}
	void del_all() {	
        while (tail != NULL)
            del_first();
	}
};

int main() {
	circular_list l1;
	l1.add_last(10);
	l1.add_last(20);
	l1.add_last(30);
	l1.add_first(40);
	l1.display();
	l1.del_first();
	l1.display();
	l1.del_all();
	l1.display();
	return 0;
}

