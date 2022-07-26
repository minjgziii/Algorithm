#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = 0;
	int n[3];


	while (1) {
		for (int i{ 0 }; i < 3; i++) {
			cin >> num;
			n[i] = num;
		}
		if (n[0] == 0 && n[1] == 0 && n[2] == 0)
			break;
		sort(n, n + 3);

		if (n[0] * n[0] + n[1] * n[1] == n[2] * n[2]) {
			cout << "right" << endl;
		}
		else
			cout << "wrong" << endl;
	}

}