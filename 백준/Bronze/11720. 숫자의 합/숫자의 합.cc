#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	string num;
	int sum = 0;

	int cnt = 0;

	cin >> N >> num;

	for (auto c : num) {
		sum += c - '0';
	}
	cout << sum;
}