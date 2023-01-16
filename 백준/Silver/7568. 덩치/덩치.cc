#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N = 0;
	int x = 0;
	int y = 0;

	cin >> N;

	vector<int> xv;
	vector<int> yv;
	
	for (int i{ 0 }; i < N; i++) {
		cin >> x >> y;
		xv.push_back(x);
		yv.push_back(y);
	}


	for (int i{ 0 }; i < N; i++) {
		int count = 1;

		
		for (int j{ 0 }; j < N; j++) {
			if (xv[i] < xv[j]) {
				if (yv[i] < yv[j]) {
					count++;
				}
			}
		}
		cout << count << " ";
	}


}