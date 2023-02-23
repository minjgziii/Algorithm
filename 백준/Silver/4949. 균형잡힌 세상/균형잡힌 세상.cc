#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line;

	while (true) {
		// 조건이 틀린 것이 있는지 확인을 위함
		int cnt = 0;

		stack<char> big;
		stack<char> small;

		// false -> big , true -> small
		stack<bool> q;

		getline(cin, line);

		// 입력 종료조건
		if (line == ".") {
			break;
		}

		for (int i{ 0 }; i < line.length(); i++) {
			if (line[i] == '.') {
				break;
			}

			else if (line[i] == '(') {
				small.push('(');
				q.push(true);
			}

			else if (line[i] == ')') {
				if (small.size() == 0 || q.top() == false) {
					cnt++;
					break;
				}
				else {
					small.pop();
					q.pop();
				}
			}

			else if (line[i] == '[') {
				big.push('[');
				q.push(false);
			}

			else if (line[i] == ']') {
				if (big.size() == 0 || q.top() == true) {
					cnt++;
					break;
				}
				else {
					big.pop();
					q.pop();
				}
			}

		}

		if (big.size() != 0 || small.size() != 0) {
			cnt++;
		}

		// 틀린 조건 개수 0개 -> yes
		if (cnt == 0) {
			cout << "yes" << "\n";
		}
		// 틀린 조건 개수 0개가 아니면 -> no
		else {
			cout << "no" << "\n";
		}
	}

	return 0;
}