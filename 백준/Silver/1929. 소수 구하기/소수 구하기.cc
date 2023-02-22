#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) {
	for (int i{ 2 }; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M = 0;
	int N = 0;

	cin >> M >> N;

	for (int i{ M }; i <= N; i++) {
		if (i == 1) {
			continue;
		}
		if (isPrime(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}