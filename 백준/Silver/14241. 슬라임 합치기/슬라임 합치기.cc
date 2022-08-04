#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int slm = 0;
	vector<int> v;
	int sum = 0;


	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> slm;
		v.push_back(slm);
	}

	for (int i{ 0 }; i <= N - 2; i++) {
		for (int j{ i + 1 }; j <= N - 1; j++) {
			sum += v[i] * v[j];
		}
	}
	cout << sum;
}