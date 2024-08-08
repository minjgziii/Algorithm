#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> m;
    map<string, int>::iterator iter;

    for (int i{ 0 }; i < clothes.size(); i++) {
        // 키가 있으면 맵 value 값 변경
        if (m.find(clothes[i][1]) != m.end()) {
            m[clothes[i][1]] += 1;
        }
        // 없으면 맵에 삽입
        else {
            m.insert({ clothes[i][1], 1 });
        }
    }

    for (iter = m.begin(); iter != m.end(); iter++) {
        answer *= (iter->second + 1);
    }

    return answer - 1;
}