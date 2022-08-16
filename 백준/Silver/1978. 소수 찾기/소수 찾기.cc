#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int num = 0;
	int cnt = 0;
	int sum = 0;
	vector<int> v;
	
	cin >> N;


	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i{ 0 }; i < N; i++) {
		cnt = 0;
		if (v[i] == 1) {
			cnt++;
		}
		else if (v[i] != 1) {
			for (int j{ 2 }; j < v[i]; j++) {
				if (v[i] == 1) {
					cnt++;
					break;
				}
				if (v[i] % j == 0) {
					cnt++;
					break;
				}
			}
		}
		if (cnt == 0) {
			sum++;
		}
	}
	cout << sum;
}