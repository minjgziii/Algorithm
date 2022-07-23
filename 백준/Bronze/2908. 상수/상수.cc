#include<bits/stdc++.h>
using namespace std;

int main() {
	string a;
	string b;
	string result;

	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		if (a[i] == b[i])
			continue;
		else if (a[i] > b[i]) {
			result = a;
			break;
		}
		else {
			result = b;
			break;
		}
	}

	cout << result[2] << result[1] << result[0];

}