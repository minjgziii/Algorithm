#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int helmet = 0;
	int vest = 0;
	vector<int> v;
	vector<int> v1;

	cin >> N >> M;

	for (int i{ 0 }; i < N; i++) {
		cin >> helmet;
		v.push_back(helmet);
	}

	int max_helmet = *max_element(v.begin(), v.end());

	for (int j(0); j < M; j++) {
		cin >> vest;
		v1.push_back(vest);
	}

	int max_vest = *max_element(v1.begin(), v1.end());

	cout << max_helmet + max_vest;
}