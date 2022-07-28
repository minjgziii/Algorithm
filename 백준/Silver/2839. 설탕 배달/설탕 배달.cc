#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int numi = 0;
	int numj = 0;
	int cnt = 0;

	cin >> N;

	for (int i{ 0 }; i <= 1000; i++) {
		for (int j{ 0 }; j <= 1666; j++) {
			if (N == 5 * i + 3 * j) {
				cnt++;
				numi = i;
				numj = j;

			}
			else
				continue;
		}
	}
	if (cnt != 0) {
		cout << numi + numj;
	}
	else
		cout << -1;
}