#include <iostream>
using namespace std;

class singly_list; // forward declaration class

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
	friend class singly_list;
};

class singly_list {
private:
	node* head;
public:
	singly_list() {
		head = NULL;
	}
	~singly_list() {
		del_all();
	}
	void add_first(int val) {
		node* newnode = new node(val);
		newnode->next = head;
		head = newnode;
	}
	node* add_last(int val) {
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
		return newnode;
	}

	void del_first() {
		node* temp;
		if (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
	void del_all() {
		while (head != NULL)
			del_first();
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

	void create_list_with_loop() {
		int pos = 3;
		node* trav = NULL, * last;
		del_all();
		for (int i = 1; i <= 7; i++) {
			last = add_last(i);
			if (i == pos)
				trav = last;
		}
		last->next = trav;
	}
	int check_if_loop() {
		node* slow = head, * fast = head;
		int cnt = 0;
		while (fast != NULL && fast->next != NULL) {
			cnt++;
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return cnt;
		}
		return 0;
	}

	void remove_loop(int max) {
		node* trav1, * trav2;
		int i;
		for (trav1 = head; trav1 != NULL; trav1 = trav1->next) {
			trav2 = trav1->next;
			for (i=1; i<=max; i++) {
				if (trav1->next == trav2->next) {
					trav2->next = NULL;
					return;
				}
				trav2 = trav2->next;
			}
		}
	}
};

int main() {
	singly_list l1;
	l1.create_list_with_loop();
	//l1.display(); // infinite loop
	if (l1.check_if_loop())
		cout << "list contains loop." << endl;
	else
		cout << "list doesn't contain loop." << endl;
	
	int max;
	if (max=l1.check_if_loop())
		l1.remove_loop(max);
	l1.display();
	return 0;
}






