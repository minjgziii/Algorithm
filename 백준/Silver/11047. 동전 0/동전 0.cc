#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int K = 0;
	int num = 0;
	vector<int> v;

	cin >> N >> K;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<>());

	int cnt = 0;

	for (int i{ 0 }; i < v.size(); i++) {
		if (v[i] <= K) {
			while (v[i] <= K) {
				K -= v[i];
				cnt++;
			}
			if (K == 0) {
				break;
			}
		}
	}

	cout << cnt;
}