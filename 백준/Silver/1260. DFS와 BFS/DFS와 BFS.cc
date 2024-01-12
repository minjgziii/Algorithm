#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, V;
int a, b;
vector<int> arr[1001];
bool visitedB[1001];
vector<int> ansB;
vector<int> ansD;

bool visitedD[1001];

void DFS(int x) {
	visitedD[x] = true;
	ansD.push_back(x);

	for (int i{ 0 }; i < arr[x].size(); i++) {
		if (!visitedD[arr[x][i]]) {
			DFS(arr[x][i]);
		}
	}
}

void BFS(int start) {
	queue<int> q;

	q.push(start);
	visitedB[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		ansB.push_back(cur);
		q.pop();

		for (int i{ 0 }; i < arr[cur].size(); i++) {
			if (!visitedB[arr[cur][i]]) {
				q.push(arr[cur][i]);
				visitedB[arr[cur][i]] = true;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	for (int i{ 0 }; i < M; i++) {
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i{ 1 }; i <= N; i++) {
		sort(arr[i].begin(), arr[i].end());
	}

	DFS(V);
	BFS(V);

	for (int i{ 0 }; i < ansD.size(); i++) {
		cout << ansD[i] << " ";
	}

	cout << '\n';

	for (int i{ 0 }; i < ansB.size(); i++) {
		cout << ansB[i] << " ";
	}
}