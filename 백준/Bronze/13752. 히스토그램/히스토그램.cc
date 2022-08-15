#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	int num = 0;
	cin >> n;
	vector<int> v;
	
	for (int i{ 0 }; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < v[i]; j++) {
			cout << "=";
		}
		cout << "\n";
	}
}