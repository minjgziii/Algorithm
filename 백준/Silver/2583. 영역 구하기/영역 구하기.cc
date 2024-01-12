#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K;
int xR, yR;
int xL, yL;
int arr[101][101];
bool visited[101][101];
int xDir[4] = { 1,-1,0,0 };
int yDir[4] = { 0,0,1,-1 };
vector<int> v;

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = true;
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i{ 0 }; i < 4; i++) {
			int nowX = x + xDir[i];
			int nowY = y + yDir[i];

			if (nowX < 1 || nowY < 1 || nowX > N || nowY > M) {
				continue;
			}
			if (visited[nowX][nowY]) {
				continue;
			}
			if (arr[nowX][nowY] != 0) {
				continue;
			}
			
			q.push({ nowX,nowY });
			visited[nowX][nowY] = true;
			cnt++;
		}
	}

	v.push_back(cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> K;

	int num = 0;
	
	for (int i{ 0 }; i < K; i++) {
		cin >> xL >> yL >> xR >> yR;

		for (int i{ xL + 1 }; i <= xR; i++) {
			for (int j{ yL + 1 }; j <= yR; j++) {
				arr[i][j] = 1;
			}
		}
	}
	
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= M; j++) {
			if (!visited[i][j] && arr[i][j] == 0) {
				BFS(i, j);
				num++;
			}
		}
	}

	sort(v.begin(), v.end());

	cout << num << '\n';

	for (int i{ 0 }; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}