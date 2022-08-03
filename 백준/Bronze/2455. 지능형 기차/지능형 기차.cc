#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int plus = 0;
	int minus = 0;
	vector<int> v;
	int num = 0;

	for (int i{ 0 }; i < 4; i++) {
		cin >> minus >> plus;
		num += - minus + plus;
		v.push_back(num);
	}
	int max = *max_element(v.begin(), v.end());

	cout << max;

	return 0;
}