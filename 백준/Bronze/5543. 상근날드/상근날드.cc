#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int buger[3];
	int minbuger = 2001;
	int mincoke = 2001;

	for (int i{ 0 }; i < 3; i++) {
		cin >> buger[i];
		if (minbuger > buger[i]) {
			minbuger = buger[i];
		}
	}

	int coke = 0;
	int cider = 0;

	cin >> coke >> cider;

	if (coke < cider)
		mincoke = coke;
	else
		mincoke = cider;

	cout << minbuger + mincoke - 50;
}