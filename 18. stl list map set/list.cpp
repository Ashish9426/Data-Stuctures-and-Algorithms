#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
	list<int> l;
	// push_back() -- add last
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	// push_front() -- add first
	l.push_front(50);
	l.push_front(60);
	// size() -- returns num of elements in the list
	cout << "size : " << l.size() << endl;

	list<int>::iterator trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	// pop_back() -- del last
	l.pop_back();
	// pop_front() -- del first
	l.pop_front();
	cout << "size : " << l.size() << endl;

	trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	// remove() -- find the element in list and delete its first occurrance  (if found).
	l.remove(30);
	trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	// erase() -- delete the element pointed by iterator
	trav = l.begin();
	while (trav != l.end()) {
		if (*trav == 20) {
			l.erase(trav);
			break;
		}
		trav++;
	}

	trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	trav = l.begin();
	while (trav != l.end()) {
		*trav = *trav + 5;
		trav++;
	}

	// forward traverse
	cout << "trav using iteraor in fwd dirn: \n" << "LIST: ";
	trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	// backward traverse
	cout << "trav using iteraor in rev dirn: \n" << "LIST: ";
	trav = l.end();
	while (trav != l.begin()) {
		trav--;
		cout << *trav << ", ";
	}
	cout << endl;

	// reverse iterator
	cout << "trav using reverse iteraor in dirn: \n" << "LIST: ";
	list<int>::reverse_iterator rtrav = l.rbegin();
	while (rtrav != l.rend()) {
		cout << *rtrav << ", ";
		rtrav++;
	}
	cout << endl;

	// const (input) iterator
	cout << "trav using const iteraor in dirn: \n" << "LIST: ";
	list<int>::const_iterator ctrav = l.cbegin();
	while (ctrav != l.end()) {
		//*ctrav = *ctrav + 2;	// cannot modify element using const iterator
		cout << *ctrav << ", ";
		ctrav++;
	}
	cout << endl;

	l.push_back(60);
	l.push_back(20);
	l.push_back(40);

	cout << "LIST: ";
	trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	cout << "reverse list using reverse() algo" << endl;
	reverse(l.begin(), l.end());

	cout << "LIST: ";
	trav = l.begin();
	while (trav != l.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	int cnt = count(l.begin(), l.end(), 40);
	cout << "40 is repeated " << cnt << " times." << endl;

	list<int>::iterator itr = find(l.begin(), l.end(), 90);
	if (itr == l.end())
		cout << "value not found" << endl;
	else
		cout << "value found: " << *itr << endl;
	return 0;
}

