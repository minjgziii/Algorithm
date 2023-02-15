#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;
	double num = 0;
	double sum = 0;

	double aver = 0; // 산술평균
	int mid = 0; // 중앙값
	int much = 0; // 최빈값
	int minus = 0; // 범위

	cin >> N;

	vector<pair<int, int>> vm;
	vector<int> v;


	for (int i{ 0 }; i < N; i++) {
		cin >> num;
		v.push_back(num);
		sum += num;
	}

	sort(v.begin(), v.end());

	aver = round(sum / N);
	mid = v[N / 2];
	minus = v.back() - v.front();
	
	for (int i{ 0 }; i < v.size(); i++) {
		
		// vm에 원소를 처음 넣는 경우
		if (vm.empty()) {
			vm.push_back(make_pair(v[i], 1));
			continue;
		}

		
		if (vm.back().first == v[i]) {
			vm.back().second++;
		}
		else {
			vm.push_back(make_pair(v[i], 1));
		}


	}

	sort(vm.begin(), vm.end(), compare);


	if (aver == -0) {
		cout << 0 << "\n";
	}
	else {
		cout << aver << "\n";
	}

	cout << mid << "\n";

	if (N == 1) {
		cout << vm[0].first << "\n";
	}
	else if (vm[0].second == vm[1].second) {
		cout << vm[1].first << "\n";
	}
	else {
		cout << vm[0].first << "\n";
	}

	cout << minus << "\n";

}