#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int num = 0;
	int sum = 0;

	cin >> N;
	vector<int> v;
	vector<int> v1;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v1.push_back(num);
	}

	sort(v.begin(), v.end());
	sort(v1.rbegin(), v1.rend());

	for (int i{ 0 }; i < N; i++) {
		sum += v[i] * v1[i];
	}
	cout << sum;
}