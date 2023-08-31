#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end()); // 가장 시간이 많이 걸리는 심사위원 찾기 위해

    long long start = 1;
    long long end = (long long) times[times.size() - 1] * n; // 처리 시간이 가장 오래 걸리는 심사위원의 시간 * 총 인원

    long long mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        long long cnt = 0;

        for (int i{ 0 }; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        // 처리해야 할 사람이 남아있는 경우
        if (cnt < n) {
            start = mid + 1;
        }
        // 다 처리한 경우
        else {
            if (mid <= end) {
                answer = mid;
            }
            end = mid - 1;
        }
    }

    return answer;
}