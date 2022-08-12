#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	vector<pair<int, int>> v;
	int num1 = 0;
	int num2 = 0;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> num1 >> num2;
		v.push_back(pair<int, int>(num2, num1));
	}
	sort(v.begin(), v.end());

	for (int i{ 0 }; i < N; i++) {
		cout << v[i].second << " " << v[i].first << "\n";
	}

	return 0;
}