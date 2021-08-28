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
		// special 1 & 2: if list is empty, new node is first node | user give pos = 1 or less than that, new node should be first
		if (head == NULL || pos <= 1) {
			add_first(val);
			return;
		}
		// alloc node and init it
		newnode = new node(val);
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
	void del_at_pos(int pos) {
		node* temp, * trav;
		int i;
		//special 1 & 2: if list is empty or pos == 1, delete the first node
		if (head == NULL || pos == 1)
			del_first();
		else {
			//1. trav till pos-1
			trav = head;
			for (i = 1; i < pos - 1; i++) {
				//special 3: if pos is beyond size of list
				if (trav->next == NULL)
					return;
				trav = trav->next;
			}
			//2. get pointer temp to the next node (to be deleted)
			temp = trav->next;
			//3. trav's next to temp's next
			trav->next = temp->next;
			//4. delete temp node
			delete temp;
		}
	}
	void reverse() {
		node* oldhead, * temp;
		// consider cur list as old list & make cur list empty
		oldhead = head;
		head = NULL;
		while (oldhead != NULL) {
			// delete first node from old list
			temp = oldhead;
			oldhead = oldhead->next;
			// add it to start of new list
			temp->next = head;
			head = temp;
		}
	}

	void rev_display(node* trav) {
		if (trav == NULL)
			return;
		rev_display(trav->next);
		cout << trav->data << ", ";
	}
	void rev_display() {
		cout << "REV : ";
		rev_display(head);
		cout << endl;
	}
	void find_mid() {
		node* slow = head, * fast = head;
		if (head != NULL) {
			while (fast != NULL && fast->next != NULL) {
				slow = slow->next;
				fast = fast->next->next;
			}
			cout << "Mid: " << slow->data << endl;
		}
	}
	node* revrec(node* trav) {
		if (trav->next == NULL) {
			head = trav;
			return trav;
		}
		node* travnext = revrec(trav->next);
		travnext->next = trav;
		return trav;
	}
	void revrec() {
		if (head != NULL) {
			node *trav = revrec(head);
			trav->next = NULL;
		}
	}

	void find_common(singly_list &other) {
		cout << "Common : ";
		node* trav1 = this->head, * trav2 = other.head;
		while (trav1 != NULL && trav2 != NULL) {
			if (trav1->data == trav2->data) {
				cout << trav1->data << ", ";
				trav1 = trav1->next;
				trav2 = trav2->next;
			}
			else {
				if (trav1->data < trav2->data)
					trav1 = trav1->next;
				else
					trav2 = trav2->next;
			}
		}
		cout << endl;
	}

	node* del(node* prev, node* trav) {
		node* travnext = trav->next;
		if (prev == NULL) {
			head = travnext;
			delete trav;
		}
		else {
			prev->next = travnext;
			delete trav;
		}
		return travnext;
	}

	void del_common(singly_list& other) {
		cout << "Common : ";
		node* trav1 = this->head, * trav2 = other.head;
		node* prev = NULL;
		while (trav1 != NULL && trav2 != NULL) {
			if (trav1->data == trav2->data) {
				cout << trav1->data << ", ";
				trav1 = del(prev, trav1);
				trav2 = trav2->next;
			}
			else {
				if (trav1->data < trav2->data) {
					prev = trav1;
					trav1 = trav1->next;
				} 
				else
					trav2 = trav2->next;
			}
		}
		cout << endl;
	}

	void del_duplicates() {
		node* trav1, * trav2, * prev2, * next2;
		for (trav1 = head; trav1 != NULL; trav1 = trav1->next) {
			prev2 = trav1;
			for (trav2 = trav1->next; trav2 != NULL; trav2 = next2) {
				next2 = trav2->next;
				if (trav1->data == trav2->data)
					del(prev2, trav2);
				else
					prev2 = trav2;
			}
		}
	}
};

int main() {
	singly_list l1;
	l1.add_last(10);
	l1.add_last(20);
	l1.add_last(30);
	l1.add_last(40);
	l1.display();

	//l1.reverse();
	//l1.display();
	
	//l1.rev_display();
	
	//l1.find_mid();

	//l1.revrec();
	//l1.display();

	singly_list l2;
	l2.add_last(20);
	l2.add_last(40);
	l2.add_last(50);

	//l1.find_common(l2);
	l1.del_common(l2);

	l1.display();

	singly_list l3;
	l3.add_last(10);
	l3.add_last(20);
	l3.add_last(20);
	l3.add_last(40);
	l3.add_last(30);
	l3.add_last(40);
	l3.add_last(30);
	l3.display();
	l3.del_duplicates();
	l3.display();
	return 0;
}






