#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<pair<int, int>> v;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		int s, e;
		cin >> s >> e;

		v.push_back({ e,s });
	}

	sort(v.begin(), v.end());

	int cnt = 1;
	int endTime = v[0].first;

	for (int i{ 1 }; i < N; i++) {
		if (endTime > v[i].second) {
			continue;
		}
		cnt++;
		endTime = v[i].first;
	}

	cout << cnt;
}