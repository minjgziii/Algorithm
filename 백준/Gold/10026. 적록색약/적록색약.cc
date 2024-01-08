#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N;
char arr[101][101];
bool visited[101][101];
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 4; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			if (nowX < 0 || nowY < 0 || nowX >= N || nowY >= N) {
				continue;
			}
			if (visited[nowX][nowY]) {
				continue;
			}
			if (arr[nowX][nowY] != arr[x][y]) {
				continue;
			}
			q.push({ nowX,nowY });
			visited[nowX][nowY] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int blindAns = 0;
	int ans = 0;

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				blindAns++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (arr[i][j] == 'G') {
				arr[i][j] = 'R';
			}
		}
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				ans++;
			}
		}
	}

	cout << blindAns << " " << ans;
}