#include<iostream>
using namespace std;

int dp[41];
int dp0[41];
int dp1[41];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T = 0;

	cin >> T;

	int N = 0;

	for (int i{ 0 }; i < T; i++) {
		cin >> N;

		dp0[0] = 1;
		dp0[1] = 0;
		dp1[0] = 0;
		dp1[1] = 1;

		for (int j{ 2 }; j <= N; j++) {
			dp0[j] = dp0[j - 1] + dp0[j - 2];
			dp1[j] = dp1[j - 1] + dp1[j - 2];
		}

		cout << dp0[N] << " " << dp1[N] << '\n';
	}
}