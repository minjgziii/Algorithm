#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int b = 0;
	cin >> N;

	for (int i{ 1 }; i < N; i++) {
		int num = i;

		string a = to_string(i);

		for (int j{ 0 }; j < a.length(); j++) {
			//num += (int)a[j];
			num += a[j] - '0';
		}

		if (num == N) {
			cout << i;
			b++;
			return 0;
		}
	}

	if (b == 0) {
		cout << 0;
	}
}