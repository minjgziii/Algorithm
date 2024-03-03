#include<iostream>
#include<queue>
#include<string>

using namespace std;

long long A, B;
queue<pair<long long, long long>> q;

int BFS() {
	q.push({ A,1 });

	while (!q.empty()) {
		long long now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// map을 벗어나는 경우
		if (now < 0 || now > B) {
			continue;
		}

		// 답을 찾은 경우
		if (now == B) {
			return cnt;
		}

		// 2배를 하는 경우
		if (2 * now <= B) {
			q.push({ 2 * now, cnt + 1 });
		}

		// 가장 오른쪽에 1을 추가하는 경우
		if (now * 10 + 1 <= B) {
			q.push({ now * 10 + 1, cnt + 1 });
		}
	}

	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	cout << BFS();
}