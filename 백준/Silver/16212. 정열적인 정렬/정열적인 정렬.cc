#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int num = 0;

	cin >> N;

	vector<int> v;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i{ 0 }; i < N; i++) {
		cout << v[i] << " ";
	}


}