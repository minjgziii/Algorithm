#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	unsigned long long answer = 1;

	int cnt10 = 0;
	int cnt5 = 0;
	int cnt2 = 0;

	for (int i{ N}; i >= 1; i--) {
		int num = i;
		if (num % 10 == 0) {
			while (num % 10 == 0) {
				num /= 10;
				cnt10++;
			}
		}
		if (num % 2 == 0) {
			while (num % 2 == 0) {
				num /= 2;
				cnt2++;
			}
		}
		if (num % 5 == 0) {
			while (num % 5 == 0) {
				num /= 5;
				cnt5++;
			}
		}
	}
	
	int cnt25 = min(cnt2, cnt5);

	cout << cnt10 + cnt25;
}