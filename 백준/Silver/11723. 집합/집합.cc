#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int M = 0;
	string mode;
	int num = 0;

	vector<int> v;
	vector<int> all = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	cin >> M;

	while (M--) {
		cin >> mode;
		if (mode == "add") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it == v.end()) {
				v.push_back(num);
			}
		}
		else if (mode == "remove") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				v.erase(v.begin() + (it - v.begin()));
			}
		}
		else if (mode == "check") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (mode == "toggle") {
			cin >> num;
			auto it = find(v.begin(), v.end(), num);
			if (it != v.end()) {
				v.erase(v.begin() + (it - v.begin()));
			}
			else {
				v.push_back(num);
			}
		}
		else if (mode == "all") {
			v = all;
		}
		else if (mode == "empty") {
			v.clear();
		}
	}
}