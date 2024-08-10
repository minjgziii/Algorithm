#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    int len = priorities.size();

    for (int i{ 0 }; i < len; i++) {
        q.push({ i, priorities[i] }); // { index, 우선순위 }
        pq.push(priorities[i]);
    }

    int count = 1;

    while (true) {
        pair<int, int> temp = q.front();
        q.pop();

        if (temp.second != pq.top()) {
            q.push(temp); // 큐 뒤에 다시 삽입
        }
        // 현재 우선순위 가장 높은 경우
        else {
            // 알고 싶은 프로세스의 위치일 때
            if (temp.first == location) {
                answer = count;
                break;
            }
            else {
                count++;
                pq.pop();
            }
        }
    }

    return answer;
}