#include <iostream>
using namespace std;

class doubly_list;

class node {
private:
	int data;
	node* next;
	node* prev;
public:
	node() {
		data = 0;
		next = NULL;
		prev = NULL;
	}
	node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
	friend class doubly_list;
};

class doubly_list {
private:
	node* head;
    node* tail;
public:
	doubly_list() {
		head = NULL;
        tail = NULL;
	}
	void display() {
		cout << "FWD LIST: ";
		node* trav = head;
		while (trav != NULL) {
			cout << trav->data << ", ";
			trav = trav->next;
		}
		cout << endl;
	}
	void display_rev() {
		cout << "REV LIST: ";
		node* trav;
		if (tail != NULL) {
			trav = tail;
			// visit each node in reverse order (using prev pointer)
			while (trav != NULL) {
				cout << trav->data << ", ";
				trav = trav->prev;
			}
		}
		cout << endl;
	}
	void add_first(int val) {
		// alloc & init new node
		node* newnode = new node(val);
		// special 1: if list empty, newnode is first node
		if (head == NULL) {
			head = newnode;
            tail = newnode;
        }
		// add node at the start & head to it.
		else {
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
	}
	void add_last(int val) {
		node* newnode;
		// alloc new node and init it
		newnode = new node(val);
		// special case: if list is empty, newnode itself is first node
		if (head == NULL) {
			head = newnode;
            tail = newnode;
        }
		else {
			// add new node to the next of tail node
			tail->next = newnode;
			// newnode prev to last node
			newnode->prev = tail;
            // make new node as tail
            tail = newnode;
		}
	}
	void add_at_pos(int pos, int val) {
		node* newnode, * trav, *temp;
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
		// take address of next pos into temp
		temp = trav->next;
		// newnode'next to trav's next
		newnode->next = temp;
		// newnode'prev to trav
		newnode->prev = trav;
		// trav 'next to newnode
		trav->next = newnode;
		// temp's prev to newnode
		if (temp != NULL) // special4: pos is immediately after last node (temp will NULL).
			temp->prev = newnode;
        if(trav == tail) // if adding to last element, update tail.
            tail = newnode;
	}
	void del_first() {
		node* temp;
		// special1: if list is empty, do nothing.
		if (head != NULL) {
			// take addr of first node into temp
			temp = head;
			// take head to next node
			head = head->next;
			// delete temp node
			delete temp;
			// special2: list having only one node, head will become NULL.
			if(head != NULL)
				// set new head's prev to NULL
				head->prev = NULL;
            else // if head become NULL, make tail also NULL (empty list)
                tail = NULL;
		}
	}
    void del_last() {
		node* temp;
		// special1: if list is empty, do nothing.
		if (head != NULL) {
			// take addr of last node into temp
			temp = tail;
			// take tail to prev node
			tail = tail->prev;
			// delete temp node
			delete temp;
			// special2: list having only one node, tail will become NULL.
			if(tail != NULL)
				// set new tail's next to NULL
				tail->next = NULL;
            else // if tail become NULL, make head also NULL (empty list)
                head = NULL;
		}
	}
	void del_at_pos(int pos) {
		node* trav;
		int i;
		//special 1 & 2: if list is empty or pos == 1, delete the first node
		if (head == NULL || pos == 1)
			del_first();
		else {
			//1. trav till pos
			trav = head;
			for (i = 1; i < pos; i++) {
				//special 3: if pos is beyond size of list
				if (trav == NULL)
					return;
				trav = trav->next;
			}
			//3. trav prev's next to trav nex
			trav->prev->next = trav->next;
			//special 4: delete the last pos node (trav next will be NULL).
			if (trav->next != NULL) {
				//4. trav next's prev to trav's prev
				trav->next->prev = trav->prev;
            } else {
                tail = trav->prev;
            }
			//5. delete trav node
			delete trav;
		}
	}

	~doubly_list() {
		del_all();
	}

	void del_all() {
		while (head != NULL)
			del_first();
	}

	bool is_empty() {
		return head == NULL;
	}

	int get_first() {
		return head->data;
	}

	int get_last() {
		return tail->data;
	}

};

class deque_using_list {
private:
	doubly_list l;
public:
	void push_rear(int ele) {
		l.add_last(ele);
	}
	void push_front(int ele) {
		l.add_first(ele);
	}
	void pop_rear() {
		l.del_last();
	}
	void pop_front() {
		l.del_first();
	}
	bool is_empty() {
		return l.is_empty();
	}
	int peek_front() {
		return l.get_first();
	}
	int peek_rear() {
		return l.get_last();
	}
};

int main() {
	deque_using_list q;
	// ...
	return 0;
}




