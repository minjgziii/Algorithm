#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Pair {
public:
	int age;
	string name;
	int idx;
};

bool compare(Pair a, Pair b) {
	if (a.age == b.age) {
		return a.idx < b.idx;
	}
	else {
		return a.age < b.age;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 0;

	cin >> N;

	vector<Pair> v(N);
	
	for (int i{ 0 }; i < N; i++) {
		cin >> v[i].age >> v[i].name;
		v[i].idx = i;
	}

	sort(v.begin(), v.end(), compare);

	for (int i{ 0 }; i < N; i++) {
		cout << v[i].age << " " << v[i].name << "\n";
	}
}