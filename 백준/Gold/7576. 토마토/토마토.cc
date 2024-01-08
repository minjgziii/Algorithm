#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int M, N;
int ans = -1;
int arr[1001][1001];
queue<pair<int, int>> q;
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 4; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			// 맵 밖을 넘어가는 경우
			if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= M) {
				continue;
			}
			// 0이 아니라면(이미 익은 토마토거나 토마토가 없는 곳이라면)
			if (arr[nowX][nowY] != 0) {
				continue;
			}
			
			arr[nowX][nowY] = arr[x][y] + 1;
			q.push({ nowX,nowY });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	BFS();

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
			else {
				ans = max(arr[i][j], ans);
			}
		}
	}

	cout << ans - 1;
}