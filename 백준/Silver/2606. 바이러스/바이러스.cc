#include<iostream>
#include<queue>
using namespace std;

int num; // 컴퓨터의 수
int connectCom; // 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수
int a, b; // 컴퓨터 번호
int arr[101][101];
int cnt;
bool visited[101];
queue<int> q;

void BFS() {
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i{ 1 }; i <= num; i++) {
			if (arr[v][i] == 1 && visited[i] == 0) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	cin >> connectCom;

	for (int i{ 0 }; i < connectCom; i++) {
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	BFS();

	cout << cnt;
}