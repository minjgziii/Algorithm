#include<iostream>
#include<string>
using namespace std;

int main() {
	
	int T = 0;
	int k = 0;
	int n = 0;
	
	cin >> T;


	for (int i{ 0 }; i < T; i++) {
		int arr[15][15] = { 0 };

		for (int i{ 0 }; i < 15; i++) {
			arr[0][i] = i;
		}

		cin >> k >> n;

		for (int i{ 1 }; i <= k; i++) {
			for (int j{ 1 }; j <= n; j++) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}

		cout << arr[k][n] << "\n";
	}
	

}