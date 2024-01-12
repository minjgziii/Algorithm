#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int a, b;
vector<int> vec[100001];
vector<pair<int, int>> ans;
bool visited[100001];

void DFS(int x) {
	visited[x] = true;

	for (int i{ 0 }; i < vec[x].size(); i++) {
		if (!visited[vec[x][i]]) {
			ans.push_back({ vec[x][i], x });
			DFS(vec[x][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i{ 0 }; i < N - 1; i++) {
		cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	DFS(1);

	sort(ans.begin(), ans.end());

	for (int i{ 0 }; i < N - 1; i++) {
		cout << ans[i].second << '\n';
	}
}