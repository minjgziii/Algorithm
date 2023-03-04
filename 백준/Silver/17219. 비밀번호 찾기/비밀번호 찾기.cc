#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int M = 0;
	int N = 0;

	cin >> N >> M;

	string  site;
	string num;

	vector<string> v;
	map<string, string> m;

	for (int i{ 0 }; i < N; i++) {
		cin >> site >> num;
		m[site] = num;
	}

	string add;
	for (int i{ 0 }; i < M; i++) {
		cin >> add;
		cout << m[add] << "\n";
	}
}