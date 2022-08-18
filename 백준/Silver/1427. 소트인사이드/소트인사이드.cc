#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	sort(str.begin(), str.end(), greater<int>());

	cout << str;

}