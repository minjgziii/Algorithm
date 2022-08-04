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

	int num1, num2 = 0;
	cin >> num1 >> num2;

	cout << gcd(num1, num2) << "\n";
	cout << (num1 / gcd(num1, num2)) * (num2 / gcd(num1, num2)) * gcd(num1, num2);

	return 0;
}