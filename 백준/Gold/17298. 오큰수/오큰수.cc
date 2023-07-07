#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A = 0; // 수열 A의 크기
	int number;
	stack<int> s; // 오큰수를 구할 원소들
	stack<int> s1; // 현재 원소의 오큰수 후보들
	stack<int> answer; // 구한 원소들 (답)
	

	cin >> A;
	
	for (int i{ 0 }; i < A; i++) {
		cin >> number;
		s.push(number);
	}

	s1.push(s.top());
	s.pop();
	answer.push(-1);

	while (s.size() > 0) {
		// s1에 원소가 하나도 없는 경우 -> 오큰수가 없음
		if (s1.size() == 0) {
			answer.push(-1); // 오큰수 없기 때문에 답을 넣을 스택에 -1 push
			s1.push(s.top()); // 다음 원소 비교를 위해 s1에 s의 top 원소 삽입
			s.pop();
		}
		// s의 top보다 s1의 top이 큰 경우 -> 오큰수 후보/
		else if (s.top() < s1.top()) {
			answer.push(s1.top());
			s1.push(s.top());
			s.pop();
		}
		// 오큰수가 없지만, s1의 size가 0이 아닌 경우 (아직 오큰수가 될 수 있는 후보가 있음)
		else {
			s1.pop();
		}
	}

	for (int i{ 0 }; i < A; i++) {
		cout << answer.top() << " ";
		answer.pop();
	}
}