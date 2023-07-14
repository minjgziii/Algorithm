#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int> q;

    for (int i{ 0 }; i < enemy.size(); i++) {
        q.push(enemy[i]);
        // 무적권이 남아있고 적의 수가 병사보다 많을 때 => 무적권을 써야함
        if (k > 0 && n < enemy[i]) {
            n += q.top();
            q.pop();
            k--;
        }

        n -= enemy[i];

        if (n < 0) {
            break;
        }

        answer++;
    }

    return answer;
}