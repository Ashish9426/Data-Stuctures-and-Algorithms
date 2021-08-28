#include <iostream>
#include <map>
using namespace std;

int main() {
	map<int, float> m;
	m[11] = 87.0;

	pair<int, float> p1(22, 78.0);
	m.insert(p1);
	pair<int, float> p2(33, 88.0);
	m.insert(p2);

	map<int, float>::iterator itr = m.begin();
	while (itr != m.end()) {
		cout << itr->first << " = " << itr->second << endl;
		itr++;
	}

	return 0;
}
