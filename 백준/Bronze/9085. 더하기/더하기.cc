#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T = 0;
	cin >> T;
	int N = 0;
	int num = 0;
	int sum = 0;

	for (int i{ 0 }; i < T; i++) {
		sum = 0;
		cin >> N;
		for (int j{ 0 }; j < N; j++) {
			cin >> num;
			sum += num;
		}
		cout << sum << endl;
	}
}