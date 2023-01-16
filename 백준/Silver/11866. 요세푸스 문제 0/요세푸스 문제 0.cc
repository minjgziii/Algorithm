#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n = 0;
	int k = 0;
	int tmp = 0;

	queue<int> q;

	cin >> n >> k;

	for (int i{ 1 }; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	while (q.size() > 1) {
		for (int i{ 0 }; i < k - 1; i++) {
			tmp = q.front();
			q.push(tmp);
			q.pop();
		}

		tmp = q.front();
		cout << tmp << ", ";
		q.pop();
	}

	cout << q.front() << ">";

}