#include<iostream>
#include<vector>
using namespace std;


class Dequeue {
private:
	vector<int> v;
	int capacity = 0;

public:
	Dequeue() {
	}

	void push_front(int num) {
		if (empty()) {
			v.push_back(num);
			capacity++;
			return;
		}
		v.push_back(0);
		for (int i{ capacity }; i > 0; i--) {
			v[i] = v[i - 1];
		}
		v[0] = num;
		capacity++;
	}

	void push_back(int num) {
		v.push_back(num);
		capacity++;
	}

	bool empty() {
		return capacity == 0;
	}

	void pop_front() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << v.front() << endl;
			for (int i{ 1 }; i < capacity; i++) {
				v[i - 1] = v[i];
			}
			v.pop_back();
			capacity--;
		}
	}

	void pop_back() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << v.back() << endl;
			v.pop_back();
			capacity--;
		}
	}

	void front() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << v.front() << "\n";
		}
	}

	void back() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			cout << v.back() << "\n";
		}
	}

	void size() {
		cout << capacity << "\n";
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	string mode;
	int num = 0;

	cin >> N;

	Dequeue q;

	for (int i{ 0 }; i < N; i++) {
		cin >> mode;
		if (mode == "push_front") {
			cin >> num;
			q.push_front(num);
		}
		else if (mode == "push_back") {
			cin >> num;
			q.push_back(num);
		}
		else if (mode == "front") {
			q.front();
		}
		else if (mode == "back") {
			q.back();
		}
		else if (mode == "pop_back") {
			q.pop_back();
		}
		else if (mode == "pop_front") {
			q.pop_front();
		}
		else if (mode == "size") {
			q.size();
		}
		else if (mode == "empty") {
			cout << q.empty() << "\n";
		}
	}
}