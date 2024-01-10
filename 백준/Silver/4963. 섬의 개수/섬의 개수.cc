#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int t;
int w, h;
int arr[51][51];
bool visited[51][51];
int xDir[8] = { 1,-1,0,0,1,1,-1,-1 };
int yDir[8] = { 0,0,1,-1,1,-1,1,-1 };

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 8; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			if (nowX < 0 || nowY < 0 || nowX >= h || nowY >= w) {
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

	while (true) {
		int ans = 0;
		memset(visited, false, sizeof(visited));

		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		for (int i{ 0 }; i < h; i++) {
			for (int j{ 0 }; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i{ 0 }; i < h; i++) {
			for (int j{ 0 }; j < w; j++) {
				if (arr[i][j] == 1 && visited[i][j] == false) {
					BFS(i, j);
					ans++;
				}
			}
		}

		cout << ans << "\n";
	}
}