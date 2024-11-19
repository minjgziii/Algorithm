#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string,int> m;
    map<int, string> m2;

    for(int i=0; i<players.size(); i++) {
        m.insert({players[i],i+1}); // 선수 별 등수 저장
        m2.insert({i+1, players[i]});
    }

    for(int i=0; i<callings.size(); i++) {
        // 현재 불린 선수 (등수 -1 해야 함)

        m[callings[i]]--; // kai 4 -> 3
        int a = m[callings[i]]; // kai  -> 3등

        // 현재 불린 선수 앞에 있던 선수 (등수 +1 해야 함)
        string loser = m2[a]; // poe
        m[loser]++; // poe 3 -> 4

        // m2도 업데이트
        m2[a] = callings[i]; // 3, kai
        m2[a+1] = loser; // 4, poe
    }

    for(int i=1; i<=players.size(); i++) {
        answer.push_back(m2[i]);
    }

    return answer;
}