#include<iostream>
#include<map>
#include<string>
using namespace std;

int N, M;
string s;
string what;
map<string, string> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i{ 1 }; i <= N; i++) {
		cin >> s;

		string a = to_string(i);
		m.insert({ a, s });
		m.insert({ s, a });
	}

	for (int i{ 0 }; i < M; i++) {
		cin >> what;

		cout << m.find(what)->second << '\n';
	}
}