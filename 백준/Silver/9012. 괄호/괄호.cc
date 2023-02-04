#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;
	
	cin >> T;

	for (int i{ 0 }; i < T; i++) {
		int cnt = 0;

		string s;
		stack<char> st;

		cin >> s;

		for (int i{ 0 }; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(s[i]);
			}
			else {
				if (st.size() == 0) {
					cnt++;
					cout << "NO" << "\n";
					break;
				}
				else {
					st.pop();
				}
			}
		}


		if (cnt == 0) {
			if (st.size() == 0) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
		
	}
}