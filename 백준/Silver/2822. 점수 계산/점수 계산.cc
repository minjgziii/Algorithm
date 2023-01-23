#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num = 0;
	int count = 0;
	vector < pair<int, int>> v;

	for (int i{ 0 }; i < 8; i++) {
		cin >> num;
		v.push_back(make_pair(num, i + 1));
	}

	sort(v.begin(), v.end(), greater<>());

	vector<int> v1;

	for (int i{ 0 }; i < 5; i++) {
		count += v[i].first;
		v1.push_back(v[i].second);
	}
	sort(v1.begin(), v1.end());

	cout << count << "\n";

	for (int i{ 0 }; i < 5; i++) {
		cout << v1[i] << " ";
	}
}