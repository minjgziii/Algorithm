#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	queue<int> q;

	for (int i{ 1 }; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		int num = q.front();
		cout << num << " ";
		q.pop();

		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	cout << q.front();
}