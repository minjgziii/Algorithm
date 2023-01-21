#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0; // 점 개수
	int x = 0;
	int y = 0;

	cin >> N;

	vector<pair<int, int>> v;

	for (int i{ 0 }; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), compare);

	for (int i{ 0 }; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}