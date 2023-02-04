#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	string mode;
	int num = 0;

	queue<int> q;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> mode;

		if (mode == "push") {
			cin >> num;
			q.push(num);
		}

		else if (mode == "front") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}

		else if (mode == "back") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}

		else if (mode == "pop") {
			if (q.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop(); 
			}
		}

		else if (mode == "size") {
			cout << q.size() << "\n";
		}

		else if (mode == "empty") {
			if (q.size() == 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
	}
}