#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int num = 1;

	cin >> N;

	for (int i{ N }; i >= 1; i--) {
		num *= i;
	}

	cout << num;
}