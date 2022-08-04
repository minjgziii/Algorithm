#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int max_div = 0;
	int range = min(a, b);

	for (int i{ 1 }; i <= range; i++) {
		if (a % i == 0 && b % i == 0) {
			max_div = i;
		}
	}

	return max_div;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int denom = 0;
	int num = 0;

	cin >> N;
	cin >> denom;

	for (int i{ 0 }; i < N-1; i++) {
		cin >> num;
		cout << denom / (gcd(denom, num)) << "/" << num / (gcd(denom, num)) << endl;
	}
}