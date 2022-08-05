#include<bits/stdc++.h>;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	cin >> N; 
	int num = 0;
	vector<int> v;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	cout << v[0] << endl;
	for (int i{ 1 }; i < N; i++) {
		if (v[i] == v[i - 1])
			continue;
		else
			cout << v[i] << endl;
	}

	return 0;
}