#include <iostream>
using namespace std;

class doubly_circular_list; // forward declaration class

class node
{
private:
    int data;
    node *next;
    node *prev;

public:
    node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    friend class doubly_circular_list;
};

class doubly_circular_list
{
private:
    node *head;

public:
    doubly_circular_list()
    {
        head = NULL;
    }
    void display()
    {
        cout << "FWD LIST: ";
        if (head != NULL)
        {
            node *trav = head;
            do
            {
                cout << trav->data << ", ";
                trav = trav->next;
            } while (trav != head);
        }
        cout << endl;
    }
    void display_rev()
    {
        cout << "REV LIST: ";
        if (head != NULL)
        {
            // jump to last node
            node *trav = head->prev;
            // visit each node in reverse order (using prev pointer)
            do
            {
                cout << trav->data << ", ";
                trav = trav->prev;
            } while (trav != head->prev);
        }
        cout << endl;
    }
    void add_first(int val)
    {
        // alloc & init new node
        node *newnode = new node(val);
        // special 1: if list empty, newnode is first node
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        // add node at the start & head to it.
        else
        {
            newnode->next = head;
            newnode->prev = head->prev;
            head->prev->next = newnode;
            head->prev = newnode;
            head = newnode;
        }
    }
    void add_last(int val)
    {
        node *newnode, *trav;
        // alloc new node and init it
        newnode = new node(val);
        // special case: if list is empty, newnode itself is first node
        if (head == NULL)
        {
            head = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else
        {
            // jump to last node
            trav = head->prev;
            // add new node to the next of last node
            trav->next = newnode;
            // newnode prev to last node
            newnode->prev = trav;
            // newnode to first node
            newnode->next = head;
            // first node prev to newnode
            head->prev = newnode;
        }
    }
    void add_at_pos(int pos, int val)
    {
        node *newnode, *trav, *temp;
        // special 1 & 2: if list is empty, new node is first node | user give pos = 1 or less than that, new node should be first
        if (head == NULL || pos <= 1)
        {
            add_first(val);
            return;
        }
        // alloc node and init it
        newnode = new node(val);
        // trav till pos-1
        trav = head;
        for (int i = 1; i < pos - 1; i++)
        {
            // special3: if pos is beyond size of list
            if (trav->next == head)
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
        temp->prev = newnode;
    }
    void del_first()
    {
        node *temp;
        // special1: if list is empty, do nothing.
        if (head == NULL)
            return;
        // special2: if single node, delete it.
        if (head == head->next)
        {
            delete head;
            head = NULL;
            return;
        }
        // take addr of first node into temp
        temp = head;
        // take head to next node
        head = head->next;
        // establish links of tail to newhead and reverse
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        // delete temp node
        delete temp;
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
				trav = trav->next;
				//special 3: if pos is beyond size of list
				if (trav == head)
					return;
			}
			//3. trav prev's next to trav nex
			trav->prev->next = trav->next;
            //4. trav next's prev to trav's prev
            trav->next->prev = trav->prev;
            //5. delete trav node
			delete trav;
		}
	}

    ~doubly_circular_list()
    {
        del_all();
    }

    void del_all()
    {
        while (head != NULL)
            del_first();
    }
};

int main()
{
    doubly_circular_list l1;
    l1.add_last(10);
    l1.add_last(20);
    l1.add_last(30);
    l1.display();
    l1.display_rev();
    l1.add_first(40);
    l1.display();
    l1.display_rev();
    l1.add_at_pos(3, 50);
    l1.add_at_pos(1, 60);
    l1.display();
    l1.add_at_pos(7, 70);
    l1.display();
    l1.display_rev();
    l1.del_first();
    l1.display();
    l1.display_rev();
    l1.del_first();
    l1.display();
    l1.display_rev();
    l1.del_at_pos(3);
    l1.display();
    l1.display_rev();
    l1.del_at_pos(4);
    l1.display();
    l1.display_rev();
    l1.del_at_pos(5);
    l1.display();
    l1.display_rev();
    l1.del_all();
    l1.display();
    l1.display_rev();
    return 0;
}
