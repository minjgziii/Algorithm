#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	vector<int> v;
	int num = 0;
	int cnt = 0;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int j{ 0 }; j < v.size(); j++) {
		if (v[j] == 0) {
			v.erase(v.begin() + j);
			v.erase(v.begin() + j - 1);
			j -= 2;
		}
	}
	cout << accumulate(v.begin(), v.end(), 0);
}