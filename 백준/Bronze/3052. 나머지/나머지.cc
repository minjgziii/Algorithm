#include<bits/stdc++.h>
using namespace std;

int main() {
	int a = 0;
	int mod = 0;
	int arr1[10] = {};
	int cntt = 0;
	int cnt = 0;
	for (int i{ 0 }; i < 10; i++) {
		cin >> a;
		mod = a % 42;
		arr1[i] = mod;
	}



	for (int j{ 0 }; j < 10; j++) {
		cnt = 0;
		for (int i{ j }; i < 10; i++) {
			if (arr1[j] == arr1[i+1])
				cnt++;
			else
				continue;
		}
		if (cnt != 0)
			cntt++;
		else
			continue;
	}
	cout << 10 - cntt;
}