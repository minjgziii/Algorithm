#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    deque<int> d;

    for (int i{ 0 }; i < prices.size(); i++) {
        d.push_back(prices[i]);
    }

    for (int i{ 0 }; i < prices.size(); i++) {
        int cnt = 0;
        int a = d.front();
        d.erase(d.begin());

        for (int i{ 0 }; i < d.size(); i++) {
            if (a <= d[i]) {
                cnt++;
            }
            else {
                cnt++;
                break;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}