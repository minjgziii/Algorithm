#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	int alpha[26] = {};
	int max = 0;
	int max_index = 0;
	int cnt = 0;

	cin >> input;

	for (int i{ 0 }; i < input.length(); i++) {
		if (input[i] < 97) // 대문자일 때,
			alpha[input[i] - 65]++;
		else
			alpha[input[i] - 97]++;
	}

	max = 0;

	for (int i{ 0 }; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			max_index = i;
		}
	}

	for (int i{ 0 }; i < 26; i++) {
		if (max == alpha[i])
			cnt++;
	}

	if (cnt > 1)
		cout << "?";
	else
		cout << (char)(max_index + 65);

}