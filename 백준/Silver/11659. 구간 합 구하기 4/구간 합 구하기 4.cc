#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	int M = 0;
	int num = 0;
	int a = 0;
	int b = 0;
	int sum = 0;

	cin >> N >> M;
	
	vector<int> v;
	vector<int> s;

	v.push_back(0);
	s.push_back(0);

	for (int i{ 1 }; i <= N; i++) {
		cin >> num;	
		v.push_back(num);
		sum += v[i];
		s.push_back(sum);
	}

	
	for (int i{ 0 }; i < M; i++) {
		cin >> a >> b;
		cout << s[b] - s[a - 1] << "\n";
	}
}