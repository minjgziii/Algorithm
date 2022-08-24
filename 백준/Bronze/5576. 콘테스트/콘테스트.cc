#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int wnum = 0;
	int knum = 0;
	int wsum = 0;
	int ksum = 0;

	vector<int> v;
	vector<int> v1;

	for (int i{ 0 }; i < 10; i++) {
		cin >> wnum;
		v.push_back(wnum);
	}
	sort(v.rbegin(), v.rend());
	wsum = v[0] + v[1] + v[2];

	for (int i{ 0 }; i < 10; i++) {
		cin >> knum;
		v1.push_back(knum);
	}
	sort(v1.rbegin(), v1.rend());
	ksum = v1[0] + v1[1] + v1[2];

	cout << wsum << " " << ksum;
}