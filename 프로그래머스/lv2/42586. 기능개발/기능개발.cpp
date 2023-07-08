#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<int> d;

    for (int i{ 0 }; i < progresses.size(); i++) {
        d.push_back(100 - progresses[i]);
    }
    vector<pair<int, int>> v;

    for (int i{ 0 }; i < progresses.size(); i++) {
        int a = 0;

        if (d[i] % speeds[i] == 0) {
            a = d[i] / speeds[i];
            v.push_back(make_pair(a, 1));
        }
        else {
            a = (d[i] / speeds[i]) + 1;
            v.push_back(make_pair(a, 1));
        }
    }

    int i = 0;
    int size = v.size();

    while(true) {

        int cnt = 1;
        int a = v[i].first;

        for (int j{ i + 1 }; j < v.size(); j++) {
            if (a < v[j].first) {
                break;
            }
            else {
                cnt++;
            }
        }

        answer.push_back(cnt);
        i += cnt++;

        if (i >= v.size()) {
            break;
        }
    }

    return answer;
}