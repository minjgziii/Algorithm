#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	int layer = 0;
	int sum = 2;

	if (N == 1) {
		layer = 1;
	}

	while (N >= sum) {
		sum += 6 * layer;
		layer++;
	}

	cout << layer << "\n";
}