#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	int num = 0;

	stack<int> s;
	queue<int> q;
	queue<int> q1;

	vector<char> v;

	cin >> n;

	for (int i{ 1 }; i <= n; i++) {
		q1.push(i);
	}

	for (int i{ 0 }; i < n; i++) {
		cin >> num;
		q.push(num);
	}

	int no = 0;

	while (q.size() > 0) {
		int cnt = 0;

		if (s.empty()) {
			for (int i{ 0 }; i < q.size(); i++) {
				if (q1.size() == 0) {
					cout << "NO";
					cnt++;
					break;
				}
				else if (q.front() != q1.front()) {
					s.push(q1.front());
					q1.pop();
					v.push_back('+');
				}
				else {
					s.push(q1.front());
					q1.pop();
					v.push_back('+');
					break;
				}
			}
		}
		else if (s.top() == q.front()) {
			s.pop();
			q.pop();
			v.push_back('-');
		}
		else {
			for (int i{ 0 }; i < q.size(); i++) {
				if (q1.size() == 0) {
					cout << "NO";
					cnt++;
					break;
				}
				else if (q.front() != q1.front()) {
					s.push(q1.front());
					q1.pop();
					v.push_back('+');
				}
				else {
					s.push(q1.front());
					q1.pop();
					v.push_back('+');
					break;
				}
			}
		}

	
		if (cnt != 0) {
			no++;
			break;
		}
	}

	if (no != 0) {
		return 0;
	}
	else {
		for (int i{ 0 }; i < v.size(); i++) {
			cout << v[i] << "\n";
		}
	}
}