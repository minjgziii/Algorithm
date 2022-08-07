#include<bits/stdc++.h>;
using namespace std;

int s;
int a[10001];

void push(int x) {
	a[s] = x;
	s++;
}

int pop() {
	if (s == 0)
		return -1;
	else {
		int t = a[s - 1];
		s--;
		return t;
	}
}
int size() {
	return s;
}

int top() {
	if (s == 0)
		return -1;
	else
		return a[s - 1];
}
int empty() {
	if (s == 0)
		return 1;
	else
		return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int N = 0;
	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			push(n);
		}
		if (str == "pop") {
			cout << pop() << "\n";
		}
		if (str == "top") {
			cout << top() << "\n";
		}
		if (str == "size") {
			cout << size() << "\n";
		}
		if (str == "empty") {
			cout << empty() << "\n";
		}
	}
}