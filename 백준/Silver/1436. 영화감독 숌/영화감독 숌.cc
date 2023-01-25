#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int count = 0;

	cin >> N;

	int i = 1;

	while (true) {
		string a = to_string(i);

		for (int j{ 0 }; j < a.length(); j++) {
			if (a[j] == '6') {
				if (a[j + 1] == '6') {
					if (a[j + 2] == '6') {
						count++;
						break;
					}
				}
			}

		}

		if (count == N) {
			cout << i;
			return 0;
		}

		i++;
	}

}