#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int cnt = 0;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;

	for (int i{ 0 }; i < strlen(alphabet); i++) {
		for (int j = 0; j < s.length(); j++) {
			if (alphabet[i] == s[j]) {
				cout << j << " ";
				cnt = 0;
				break;
			}
			else
				cnt = 1;
		}
		if (cnt == 1)
			cout << "-1 ";
	}
	return 0;
}