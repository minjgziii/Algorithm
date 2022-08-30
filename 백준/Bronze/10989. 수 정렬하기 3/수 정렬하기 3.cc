#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N = 0;
	int num = 0;

	cin >> N;

	int input[10001] = { 0 };

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		input[num] += 1;
	}

	for (int i{ 1 }; i < 10001; i++) {
		for (int j{ 0 }; j < input[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}