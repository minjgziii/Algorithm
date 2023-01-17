#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N = 0;
	int tmp = 0;

	queue<int> q;

	cin >> N;

	for (int i{ 1 }; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		tmp = q.front();
		q.push(tmp);
		q.pop();
	}

	cout << q.front();
}