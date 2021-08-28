#include <iostream>
#include <cstring>
using namespace std;

class student {
private:
	int roll;
	char name[20];
	float marks;
public:
	student() {
		roll = 0;
		strcpy(name, "");
		marks = 0.0f;
	}
	student(int roll, const char *name, float marks) {
		this->roll = roll;
		strcpy(this->name, name);
		this->marks = marks;
	}
	// getters/setters
	float get_marks() {
		return marks;
	}
	void display() {
		cout << roll << ", " << name << ", " << marks << endl;
	}
};

void selection_sort(student a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i].get_marks() < a[j].get_marks())
				swap(a[i], a[j]);
		}
	}
}

int main() {
	student arr[5] = {
		student(1, "A", 87),
		student(2, "B", 76),
		student(3, "C", 98),
		student(4, "D", 45),
		student(5, "E", 76)
	};
	selection_sort(arr, 5);
	for (int i = 0; i < 5; i++)
		arr[i].display();
	return 0;
}