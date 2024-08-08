#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int max = nums.size() / 2;

    map<int, int> m;

    for (int i{ 0 }; i < nums.size(); i++) {
        m.insert({ nums[i], 1 });
    }

    for (int i{ 0 }; i < m.size(); i++) {
        if (answer < max) {
            answer++;
        }
    }

    return answer;
}