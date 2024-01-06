#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int T;
int M, N, K;
int X, Y;
int arr[51][51];
bool visited[51][51];
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
int answer;

void BFS(int i, int j) {
	answer++;
	q.push({ i,j });
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 4; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			if (nowX < 0 || nowY < 0 || nowX >= M || nowY >= N) {
				continue;
			}
			if (visited[nowX][nowY]) {
				continue;
			}
			if (arr[nowX][nowY] == 0) {
				continue;
			}

			visited[nowX][nowY] = true;
			q.push({ nowX,nowY });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i{ 0 }; i < T; i++) {
		answer = 0;

		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		cin >> M >> N >> K;



		for (int i{ 0 }; i < K; i++) {
			cin >> X >> Y;

			arr[X][Y] = 1;
		}


		for (int i{ 0 }; i < M; i++) {
			for (int j{ 0 }; j < N; j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) {
					BFS(i, j);
				}
			}
		}

		cout << answer << "\n";
	}
}