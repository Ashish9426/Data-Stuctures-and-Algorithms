#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> s;
	int option, val;
	do {
		cout << "0. exit\n1. push\n2. peek\n3. pop\nenter option: ";
		cin >> option;
		switch (option) {
		case 1: // push
			cout << "enter ele: ";
			cin >> val;
			s.push(val);
			break;
		case 2: // peek
			if (s.empty())
				cout << "queue empty." << endl;
			else {
				val = s.front();
				cout << "next ele : " << val << endl;
			}
			break;
		case 3: // pop
			if (s.empty())
				cout << "queue empty." << endl;
			else {
				val = s.front();
				s.pop();
				cout << "popped ele : " << val << endl;
			}
			break;
		}
	} while (option != 0);
	return 0;
}

