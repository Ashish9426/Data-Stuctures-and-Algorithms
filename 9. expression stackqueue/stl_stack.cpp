#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
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
				cout << "stack empty." << endl;
			else {
				val = s.top();
				cout << "next ele : " << val << endl;
			}
			break;
		case 3: // pop
			if (s.empty())
				cout << "stack empty." << endl;
			else {
				val = s.top();
				s.pop();
				cout << "popped ele : " << val << endl;
			}
			break;
		}
	} while (option != 0);
	return 0;
}

