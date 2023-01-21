#include<iostream>
#include<cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double A = 0;

	double B = 0;

	double V = 0;
	int count = 0;

	cin >> A >> B >> V;

	count = ceil((V - A) / (A - B));
	
	cout << count + 1;
}