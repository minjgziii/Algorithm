#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> m;

    for (int i{ 0 }; i < record.size(); i++) {
        string behave, id, name;
        string s = record[i];
        stringstream s2(s);
        s2 >> behave >> id >> name;


        if (behave == "Enter") {
            m[id] = name;
        }
        else if (behave == "Change") {
            m[id] = name;
        }
    }

    for (int i{ 0 }; i < record.size(); i++) {
        string behave, id, name;
        string s = record[i];
        stringstream s2(s);
        s2 >> behave >> id >> name;
        
        auto item = m.find(id);

        if (item != m.end()) {
            string ans = "";
            if (behave == "Enter") {
                ans += item->second;
                ans += "님이 들어왔습니다.";
                answer.push_back(ans);
            }
            else if(behave == "Leave") {
                ans += item->second;
                ans += "님이 나갔습니다.";
                answer.push_back(ans);
            }
            else {
                continue;
            }
        }
    }

    return answer;
}