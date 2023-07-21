#include<iostream>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int number = 0;
	int num = 0;

	map<int, int> m;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		cin >> number;
		m.insert({ number,1 });
	}

	cin >> M;

	for (int i{ 0 }; i < M; i++) {
		cin >> num;
		if (m.find(num) != m.end()) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
}