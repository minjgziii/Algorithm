#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, int> cnt;
    map<string, vector<string>> reports;

    vector<string>::iterator iter;

    for(string r : report) {
        stringstream ss(r);
        string reporter, reported; // 신고한 사람, 신고 당한 사람
        ss >> reporter >> reported;

        iter = find(reports[reporter].begin(), reports[reporter].end(), reported);

        if (iter != reports[reporter].end()) {
            continue;
        }

        reports[reporter].push_back(reported);
        cnt[reported]++;
    }

    for(int i=0; i<id_list.size(); i++) {
        int cnts = 0;
        string reporter = id_list[i];

        for(int j=0; j<reports[reporter].size(); j++) {
            if(cnt[reports[reporter][j]] >= k) {
                cnts++;
            }
        }
        answer.push_back(cnts);
    }

    return answer;
}