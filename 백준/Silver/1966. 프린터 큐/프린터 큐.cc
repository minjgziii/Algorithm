#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 0; // 테스트 케이스 수
	int N = 0; // 문서의 개수
	int M = 0; // 궁금한 문서가 현재 큐에서 몇 번째에 놓여 있는지
	int num = 0;
	
	cin >> t;


	for (int i{ 0 }; i < t; i++) {
		cin >> N >> M;

		queue<pair<int, int>> doc; // 문서 정보
		priority_queue<int> import; // 중요도

		int count = 0;

		for (int i{ 0 }; i < N; i++) {
			cin >> num;

			doc.push(make_pair(i, num));
			import.push(num);
		}


		while (!doc.empty()) {
			int index = doc.front().first;
			int importance = doc.front().second;

			if (import.top() > importance) {
				doc.push(doc.front());
				doc.pop();
			}

			else {
				doc.pop();
				import.pop();
				count++;


				if (index == M) {
					cout << count << "\n";
					break;
				}
			}
		}
	}
}