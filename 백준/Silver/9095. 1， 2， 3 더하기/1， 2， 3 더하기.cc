#include<iostream>
using namespace std;

int n;
int num;
int cnt = 0;
int dp[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i{ 0 }; i < n; i++) {
		cin >> num;
		
		cnt = 0;

		for (int i{ 4 }; i <= num; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}

		cout << dp[num] << '\n';
	}
}