#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> v;
    string tmp;

    int a = s.length();

    for (int i{ 0 }; i < a; i++) {
        // 공백이 아니면
        if (s[i] != ' ') {
            tmp += s[i];
        }
        // 공백이면
        else {
            v.push_back(stoi(tmp));
            tmp.clear();
        }
    }

    v.push_back(stoi(tmp));

    sort(v.begin(), v.end());

    answer = to_string(v.front()) + " " + to_string(v.back());

    return answer;
}