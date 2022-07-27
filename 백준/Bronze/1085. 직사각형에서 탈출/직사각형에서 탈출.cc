#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y, w, h = 0;

	cin >> x >> y >> w >> h;

	int xw = abs(x - w);
	int yh = abs(y - h);

	if (xw <= yh && xw <= x && xw <= y) {
		cout << xw;
	}
	else if (yh <= xw && yh <= x && yh <= y) {
		cout << yh;
	}
	else if (x <= xw && x <= yh && x <= y) {
		cout << x;
	}
	else if (y <= xw && y <= yh && y <= x) {
		cout << y;
	}
	
}