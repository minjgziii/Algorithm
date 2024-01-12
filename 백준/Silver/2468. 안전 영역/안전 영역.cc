#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N;
int arr[101][101];
bool visited[101][101];
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };

void BFS(int i,int j, int bound) {
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
			// 물에 잠긴 경우 (bound이하)
			if (arr[nowX][nowY] <= bound) {
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

	cin >> N;

	int maxHeight = -1;
	int max = 0;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			cin >> arr[i][j];
			if (maxHeight < arr[i][j]) {
				maxHeight = arr[i][j];
			}
		}
	}

	for (int x{ 0 }; x <= maxHeight; x++) {
		memset(visited, false, sizeof(visited));
		int ans = 0;

		for (int i{ 0 }; i < N; i++) {
			for (int j{ 0 }; j < N; j++) {
				// 방문하지 않았고 안전한 구역
				if (!visited[i][j] && arr[i][j] > x) {
					BFS(i, j, x);
					ans++;
				}
			}
		}

		if (max < ans) {
			max = ans;
		}
	}

	cout << max;
}