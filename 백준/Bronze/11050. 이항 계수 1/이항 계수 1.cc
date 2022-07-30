#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 1;
	int K = 1;

	cin >> N >> K;
	
	int denom = 1; // 분모
	int numer = 1; // 분자
	
	for (int i{ N }; i >= 1; i--) {
		denom *= i;
	}
	
	for (int i{ K }; i >= 1; i--) {
		numer *= i;
	}

	for (int i{ N - K }; i >= 1; i--) {
		numer *= i;
	}

	cout << denom / numer;
}