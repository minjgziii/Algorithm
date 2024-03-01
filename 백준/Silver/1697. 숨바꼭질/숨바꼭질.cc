#include<iostream>
#include<queue>
using namespace std;

int N, K;
int road[100001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	queue<int> q;

	q.push(N);

	while (!q.empty()) {
		int nowN = q.front();
		q.pop();

		// 맵을 벗어난 경우
		if (nowN < 0 || nowN > 100000) {
			continue;
		}

		// 동생을 찾은 경우
		if (nowN == K) {
			cout << road[nowN];
			break;
		}

		// 뒤로 이동하는 경우
		if (nowN - 1 >= 0 && road[nowN - 1] == 0) {
			road[nowN - 1] = road[nowN] + 1;
			q.push(nowN - 1);
		}

		// 앞으로 이동하는 경우
		if (nowN + 1 <= 100000 && road[nowN + 1] == 0) {
			road[nowN + 1] = road[nowN] + 1;
			q.push(nowN + 1);
		}

		// 2배로 이동하는 경우
		if (2 * nowN <= 100000 && road[2 * nowN] == 0) {
			road[2 * nowN] = road[nowN] + 1;
			q.push(2 * nowN);
		}
	}
}