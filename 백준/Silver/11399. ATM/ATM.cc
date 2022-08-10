#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int p = 0;
	cin >> N;

	vector<int> v;
	int sum = 0;

	for (int i{ 0 }; i < N; i++) {
		cin >> p;
		v.push_back(p);
	}

	sort(v.begin(), v.end());

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j <= i; j++) {
			sum += v[j];
		}
	}

	cout << sum;
}