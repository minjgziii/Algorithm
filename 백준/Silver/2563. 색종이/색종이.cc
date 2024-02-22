#include<iostream>
using namespace std;

int n; // 색종이 수
int x, y;
bool map[101][101];
int cnt = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i{ 0 }; i < n; i++) {
		cin >> x >> y;

		for (int i{ x }; i < x + 10; i++) {
			for (int j{ y }; j < y + 10; j++) {
				if (map[i][j] == false) {
					map[i][j] = true;
					cnt++;
				}
			}
		}
	}

	cout << cnt;
}