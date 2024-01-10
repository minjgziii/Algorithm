#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
int u, v;
vector<int> vec[1001];
bool visited[1001];
int cnt;
queue<int> q;

void BFS(int start) {
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i{ 0 }; i < vec[cur].size(); i++) {
			if (visited[vec[cur][i]] == false) {
				visited[vec[cur][i]] = true;
				q.push(vec[cur][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i{ 0 }; i < M; i++) {
		cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i{ 1 }; i <= N; i++) {
		if (visited[i] == false) {
			BFS(i);
			cnt++;
		}
	}

	cout << cnt;
}