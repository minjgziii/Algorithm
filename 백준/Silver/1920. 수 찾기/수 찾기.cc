#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int num = 0;

	cin >> N;

	map<int, int> myMap;

	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		myMap[num] = 1;
	}

	cin >> M;
	for (int i{ 0 }; i < M; i++) {
		cin >> num;
		if (myMap[num] == 0) {
			cout << 0 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}
	
}