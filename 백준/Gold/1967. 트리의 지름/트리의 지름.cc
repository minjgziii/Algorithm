#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n;
int par, child, weight;
vector<pair<int, int>> vec[10001];
bool visited[10001];

int DFS(int x) {
	// 이미 방문한 노드라면
	if (visited[x]) {
		return -1000;
	}

	int sum = 0;

	visited[x] = true;

	for (int i{ 0 }; i < vec[x].size(); i++) {
		int node = vec[x][i].first;
		int value = vec[x][i].second;

		sum = max(sum, value + DFS(node));
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i{ 0 }; i < n - 1; i++) {
		cin >> par >> child >> weight;

		vec[par].push_back({ child, weight });
		vec[child].push_back({ par, weight });
	}

	int answer = 0;

	for (int i{ 1 }; i <= n; i++) {
		memset(visited, false, sizeof(visited));

		answer = max(answer, DFS(i));
	}
	
	cout << answer;
}