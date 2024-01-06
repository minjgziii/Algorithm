#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N; // 지도의 크기
char arr[26][26];
queue<pair<int, int>> q;
int cnt = 0; // 총 단지수
bool visited[26][26]; // 방문했는가
vector<int> v; // 각 단지내 집의 수
int xDir[4] = {1,-1,0,0};
int yDir[4] = {0,0,1,-1};
int num[26][26];

int BFS(int i, int j) {
	cnt++;
	q.push({ i, j });
	visited[i][j] = true;
	int houseNum = 0; // 단지내 집의 수

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
			if (arr[nowX][nowY] == '0') {
				continue;
			}

			visited[nowX][nowY] = true;
			q.push({ nowX, nowY });
			houseNum++;
		}
	}

	return houseNum + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (arr[i][j] == '1' && visited[i][j] == false) {
				int a = BFS(i, j);
				v.push_back(a);
			}
		}
	}

	cout << cnt << "\n";
	
	sort(v.begin(), v.end());

	for (int i{ 0 }; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}