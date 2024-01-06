#include<iostream>
#include<queue>
using namespace std;

int N, M; // 행, 열
char arr[100][100];
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };
bool visited[100][100];
int dist[100][100]; // 지나야 하는 칸 수 저장하는 배열
queue<pair<int, int>> q;

int BFS() {
	dist[0][0] = 1;
	visited[0][0] = true;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 4; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			if (nowX < 0 || nowX >= N || nowY < 0 || nowY >= M) {
				continue;
			}
			if (arr[nowX][nowY] == '0') {
				continue;
			}
			if (visited[nowX][nowY]) {
				continue;
			}

			visited[nowX][nowY] = true;
			q.push({ nowX,nowY });
			dist[nowX][nowY] = dist[x][y] + 1;
		}
	}

	return dist[N - 1][M - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	cout << BFS();
}