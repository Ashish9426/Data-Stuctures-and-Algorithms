#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	unsigned i;
	cout << "size: " << v.size() << endl;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "size: " << v.size() << endl;
	
	cout << "vect: ";
	for (i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;
	
	cout << "vect: ";
	vector<int>::iterator trav = v.begin();
	while (trav != v.end()) {
		cout << *trav << ", ";
		trav++;
	}
	cout << endl;

	vector<int>::iterator ptr = v.begin() + 2;
	cout << "2nd ele of vect = " << *ptr << endl;

	v.erase(ptr);
	cout << "size: " << v.size() << endl;

	cout << "vect: ";
	for (i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;

	return 0;
}

