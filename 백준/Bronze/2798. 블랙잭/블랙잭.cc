#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int num = 0;
	int M = 0;
	int sum = 0;
	vector<int> v;
	vector<int> v1;
	int min = 0;
	int minnum = 0;

	cin >> N >> M;
	
	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i{ 0 }; i < N; i++) {
		sum += v[i];
		for (int j{ i + 1 }; j < N; j++) {
			sum += v[j];
			for (int k{ j + 1 }; k < N; k++) {
				sum += v[k];
				v1.push_back(sum);
				sum = sum - v[k];
			}
			sum = sum - v[j];
		}
		sum = 0;
	}

	min = M;

	for (int i{ 0 }; i < v1.size(); i++) {
		if (min >= M - v1[i] && v1[i] <= M) {
			min = M - v1[i];
			minnum = v1[i];
		}
	}
	cout << minnum;
	return 0;
}