#include<iostream>
#include<vector>
using namespace std;

class Queue {
private:
	int capacity = 0;
	vector<int> q;

public:
	Queue() {
		capacity = NULL;
	}

	void push(int num) {
		q.push_back(num);
		capacity++;
	}

	void pop() {
		if (empty()) {
			cout << -1 << "\n";
		}
		else {
			int tmp = q.front();
			q.erase(q.begin());
			capacity--;
			cout << tmp << "\n";
		}
	}

	int size() {
		return capacity;
	}

	bool empty() {
		return capacity == 0;
	}

	int front() {
		if (empty()) {
			return -1;
		}
		else {
			return q.front();
		}
	}

	int back() {
		if (empty()) {
			return -1;
		}
		else {
			return q.back();
		}
	}
};


int main() {
	int N = 0;
	string mode;
	int num = 0;

	cin >> N;

	Queue q;

	for (int i{ 0 }; i < N; i++) {
		cin >> mode;
		if (mode == "push") {
			cin >> num;
			q.push(num);
		}
		else if (mode == "front") {
			cout << q.front() << "\n";
		}
		else if (mode == "back") {
			cout << q.back() << "\n";
		}
		else if (mode == "pop") {
			q.pop();
		}
		else if (mode == "size") {
			cout << q.size() << "\n";
		}
		else if (mode == "empty") {
			cout << q.empty() << "\n";
		}
	}
}