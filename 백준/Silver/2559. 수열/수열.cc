#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; //
	int K = 0; //
	int num = 0;
	vector<int> v;
	vector<int> sum;
	int s = 0;

	cin >> N >> K;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i{ 0 }; i < K; i++) {
		s += v[i];
	}

	int answer = s;
	int left = 0;
	int right = K;

	while (right < N) {
		s -= v[left];
		s += v[right];
		left++;
		right++;

		answer = max(answer, s);
	}
	cout << answer << "\n";
}