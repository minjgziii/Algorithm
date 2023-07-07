#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> open;

    for (int i{ 0 }; i < s.size(); i++) {
        // '(' 일 때
        if (s[i] == '(') {
            open.push(s[i]);
        }
        // ')' 일 때
        else {
            // ')'일 때, pop을 하려고 하는데 스택이 비어있다 -> 올바르지 않은 괄호
            if (open.size() == 0) {
                return false;
            }
            else {
                open.pop();
            }
        }
    }

    // 마지막에 스택에 데이터가 남아있다 -> 올바르지 않은 괄호
    if (open.size() != 0) {
        answer = false;
    }

    return answer;
}