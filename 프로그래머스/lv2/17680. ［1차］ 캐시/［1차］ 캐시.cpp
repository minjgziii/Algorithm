#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    int answer = 0;

    deque<string> cache;

	for (int i{ 0 }; i < cities.size(); i++) {
		// 캐시에 넣을 도시
		string city = cities[i];

		// 모든 문자 대문자로 변환
		for (int j{ 0 }; j < city.length(); j++) {
			city[j] = toupper(city[j]);
		}

		//캐시 hit, miss인지 판단
		bool hit = false;
		int index = 0;
		for (index = 0; index < cache.size(); index++) {
			if (cache[index] == city) {
				hit = true;
				break;
			}
		}

		// 일단 cache 가장 뒤에 삽입(LRU)
		cache.push_back(city);


		if (hit == true) {
			// 캐시에 있는 기존 데이터 삭제
			cache.erase(cache.begin() + index);

			// cache hit 일 경우 실행시간 1
			answer += 1;
		}
		else {
			if (cache.size() > cacheSize) {
				cache.pop_front();
			}
			answer += 5;
		}
	}
    
    return answer;
}