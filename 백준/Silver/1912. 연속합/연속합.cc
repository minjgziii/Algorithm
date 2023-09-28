#include<iostream>
#include <algorithm>
#define MAX_ARR 100000

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int num = 0;

	int arr[MAX_ARR];
	int dp[MAX_ARR];
	
	cin >> n;
	
	for (int i{ 0 }; i < n; i++) {
		cin >> num;

		arr[i] = num;
	}

	int ret = arr[0];
	dp[0] = arr[0];

	for (int i{ 1 }; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ret = max(dp[i], ret);
	}
	
	cout << ret << "\n";

	return 0;
}