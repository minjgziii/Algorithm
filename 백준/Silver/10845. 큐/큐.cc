#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	

	int N = 0;
	string mode;
	int num = 0;

	queue<int> st;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> mode;
		if (mode == "push") {
			cin >> num;
			st.push(num);
		}
		else if (mode == "front") {
			if (st.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << st.front() << "\n";
			}
		}
		else if (mode == "pop") {
			if (st.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << st.front() << "\n";
				st.pop();
			}
		}
		else if (mode == "empty") {
			if (st.size() == 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (mode == "size") {
			cout << st.size() << "\n";
		}
		else if (mode == "back") {
			if (st.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << st.back() << "\n";
			}
		}
	}
	
}