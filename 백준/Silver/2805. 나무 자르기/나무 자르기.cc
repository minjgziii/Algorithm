#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int tree = 0;

	vector<int> v;

	cin >> N >> M;

	for (int i{ 0 }; i < N; i++) {
		cin >> tree;
		v.push_back(tree); // 10 15 17 20
	}

	sort(v.begin(), v.end());

	long long left = 0;
	long long right = v.back();
	long long answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (int i{ 0 }; i < N; i++) {
			// 설정한 값보다 큰 나무들 절단
			if (mid < v[i]) {
				sum += v[i] - mid;
			}
		}

		if (sum == M) {
			answer = mid;
			break;
		}

		// 가져가려는 나무 길이보다 클 때
		else if (sum > M) {
			if (answer < mid) {
				answer = mid;
			}
			left = mid + 1;
		}

		// 가져가려는 나무 길이보다 작을 때
		else if (sum < M) {
			right = mid - 1;
		}
	}

	cout << answer;
	return 0;
}