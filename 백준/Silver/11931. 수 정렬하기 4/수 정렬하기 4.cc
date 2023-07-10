#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int number = 0;
	vector<int> v;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i{ 0 }; i < N; i++) {
		cout << v[i];
		cout << "\n";
	}
}