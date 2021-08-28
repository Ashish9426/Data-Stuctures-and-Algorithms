#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	/*
	// student roll --> student marks
	map<int, double> map1;
	map1[11] = 78.00;
	map1[33] = 87.00;
	map1[22] = 94.00;
	map1[44] = 65.00;
	map1[33] = 97.00; // overwrite old value of roll=33

	int roll;
	cout << "enter roll: ";
	cin >> roll;
	double marks = map1[roll];
	cout << "marks of " << roll << " are " << marks << endl;
	*/

	map<string, string> map2;
	map2["nilesh"] = "9527331338"; 
	map2["nitin"] = "9881208115";
	map2["prashant"] = "9881208114";
	
	/*
	string name, mobile;
	cout << "enter name: ";
	cin >> name;
	mobile = map2[name];
	cout << name << " -- " << mobile << endl;
	*/

	map<string,string>::iterator itr = map2.begin();
	while (itr != map2.end()) {
		cout << itr->first << " = " << itr->second << endl;
		itr++;
	}

	cout << "map size = " << map2.size() << endl;
	map2.clear(); // del all key value pairs

	// student roll --> marks of multiple subjects
	map< int, vector<double> > map3;

	char str[] = "dfksjdfdsjfkhskjdhkjsahdjsalkfjlkadjsfksjdkfl";
	map<char, int> m;
	for (int i = 0; str[i] != '\0'; i++) {
		char ch = str[i];
		m[ch] = m[ch] + 1;
	}

	map<char, int>::iterator mitr = m.begin();
	while (mitr != m.end()) {
		cout << mitr->first << " - " << mitr->second << endl;
		mitr++;
	}
	return 0;
}




 