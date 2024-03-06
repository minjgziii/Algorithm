#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int map[501][501];
bool visited[501][501] = { 0, };
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };
int maxArea = 0;;

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	int cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = 1;
		cnt++;

		for (int i{ 0 }; i < 4; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			if (nowX < 0 || nowY < 0 || nowX >= n || nowY >= m) {
				continue;
			}
			if (visited[nowX][nowY] == true) {
				continue;
			}
			if (map[nowX][nowY] == 0) {
				continue;
			}

			q.push({ nowX,nowY });
			visited[nowX][nowY] = true;
		}
	}
	maxArea = max(maxArea, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;

	cin >> n >> m;

	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < m; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				cnt++;
				BFS(i, j);
			}
		}
	}
	cout << cnt << "\n";
	cout << maxArea;
}