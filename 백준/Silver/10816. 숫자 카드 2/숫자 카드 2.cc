#include<iostream>
#include<algorithm>
using namespace std;

int arr[500002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int num = 0;

	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		arr[i] = num;
	}

	sort(arr, arr + N);

	cin >> M;

	for (int i{ 0 }; i < M; i++) {
		cin >> num;
		cout << upper_bound(arr, arr + N, num) - lower_bound(arr, arr + N, num) << " ";
	}
}