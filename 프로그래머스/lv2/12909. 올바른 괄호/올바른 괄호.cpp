#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> s1; // (
    stack<char> s2; // )

    for (int i{ 0 }; i < s.size(); i++) {
        if (s[i] == '(') {
            s1.push('(');
        }
        else {
            s2.push(')');
            if (s1.size() <= 0) {
                return false;
            }
            else {
                s1.pop();
                s2.pop();
            }
        }
    }

    if (s2.size() == 0 && s1.size() == 0) {
        answer = true;
    }
    else {
        answer = false;
    }

    return answer;
}