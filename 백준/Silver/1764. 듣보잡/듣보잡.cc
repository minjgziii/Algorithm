#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string s1, string s2) {
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;


	cin >> N >> M;

	string name;

	int cnt = 0;

	map<string, int> m;

	vector<string> n;

	// 듣도 못한 사람
	for (int i{ 0 }; i < N; i++) {
		cin >> name;
		m[name] = 1;

	}

	// 보도 못한 사람
	for (int i{ 0 }; i < M; i++) {
		cin >> name;
		// 듣도 못한 사람에 이미 있는 경우
		if (m[name] == 1) {
			cnt++;
			n.push_back(name);
		}
	}


	sort(n.begin(), n.end(), compare);
	

	cout << cnt << "\n";

	for (int i{ 0 }; i < n.size(); i++) {
		cout << n[i] << "\n";
	}
}