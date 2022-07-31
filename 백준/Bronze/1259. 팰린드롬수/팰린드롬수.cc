#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s = "";
	string scopy = "";

	while (1) {
		cin >> s;
		if (s == "0")
			break;
		else
			for (int i = s.size() - 1; i >= 0; i--) {
				scopy += s[i];
			}
		if (scopy == s) {
			cout << "yes" << "\n";
			scopy = "";
		}
		else {
			cout << "no" << "\n";
			scopy = "";
		}
	}
}