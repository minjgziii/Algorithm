#include<iostream>
#include<stack>
#include<deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A = 0; // 수열 A의 크기
	int number;
	stack<int> s;
	stack<int> answer;
	stack<int> s1;

	cin >> A;
	
	for (int i{ 0 }; i < A; i++) {
		cin >> number;
		s.push(number);
	}

	s1.push(s.top());
	s.pop();
	answer.push(-1);

	while (s.size() > 0) {
		if (s1.size() == 0) {
			answer.push(-1);
			s1.push(s.top());
			s.pop();
		}
		else if (s.top() < s1.top()) {
			answer.push(s1.top());
			s1.push(s.top());
			s.pop();
		}
		else if (s1.size() == 0) {

		}
		else {
			s1.pop();
		}
	}

	for (int i{ 0 }; i < A; i++) {
		cout << answer.top() << " ";
		answer.pop();
	}
}