#include<iostream>
#include<queue>
using namespace std;

struct compare{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else {
			return abs(a) > abs(b);
		}
		
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int x = 0;

	priority_queue<int, vector<int>, compare> q;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (q.size() == 0) {
				cout << 0 << "\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}