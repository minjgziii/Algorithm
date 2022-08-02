#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int people = 0;
	int area = 0;
	int penum = 0;

	cin >> people >> area;

	for (int i{ 0 }; i < 5; i++) {
		cin >> penum;
		cout << penum - people * area << " ";
	}

	return 0;
}