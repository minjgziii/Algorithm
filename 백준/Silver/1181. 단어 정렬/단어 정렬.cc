#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	string str;
	vector<pair<int, string>> v;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> str;
		v.push_back(pair<int, string>(str.length(), str));
	}
	sort(v.begin(), v.end());

	cout << v[0].second << endl;

	for (int j{ 1 }; j < N; j++) {
		if (v[j].second == v[j - 1].second) {
			continue;
		}
		else {
			cout << v[j].second << endl;
		}
		
	}
}