#include<iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> CITIES; // 대문자로 변환 후 삽입
    deque<string> d; // 캐시

    // 대문자로 변환
    for (int i{ 0 }; i < cities.size(); i++) {
        string a = cities[i];
        for (int j{ 0 }; j < a.size(); j++) {
            a[j] = toupper(a[j]);
        }
        
        int miss = 0;

        int index = 0;

        for (index = 0; index < d.size(); index++) {
            // cache hit
            if (d[index] == a) {
                miss++;
                break;
            }
        }

        d.push_back(a);

        // cache hit
        if (miss != 0) {
            answer += 1;
            // cache에 있던 기존 데이터 삭제
            d.erase(d.begin() + index);
        }

        // cache miss
        else {
            answer += 5;
            // 만약 cacheSize 넘쳤을 때
            if (d.size() > cacheSize) {
                d.pop_front();
            }
        }
    }

    return answer;
}