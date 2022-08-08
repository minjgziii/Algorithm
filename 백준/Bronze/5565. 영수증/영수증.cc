#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	int num = 0;
	int vsum = 0;

	cin >> sum;

	for (int i{ 0 }; i < 9; i++) {
		cin >> num;
		vsum += num;
	}
	cout << sum - vsum;
}