#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int K = 0;
	int N = 0;

	int num = 0;

	vector<int> v;

	cin >> K >> N;

	for (int i{ 0 }; i < K; i++) {
		cin >> num;
		v.push_back(num);
	}

	// sort 오름차순 정렬
	sort(v.begin(), v.end());

	long long left = 1;
	long long right = v.back();

	long long answer = 0;


	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		int cnt = 0;

		for (int i{ 0 }; i < v.size(); i++) {
			sum += v[i] / mid;
		}

		// 가져가려는 개수보다 작거나 클 때
		if (sum >= N) {
			left = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}
		// 가져가려는 개수보다 적을 때 (sum < N)
		else {
			right = mid - 1;
		}

		
		
	}

	cout << answer;
	return 0;
}