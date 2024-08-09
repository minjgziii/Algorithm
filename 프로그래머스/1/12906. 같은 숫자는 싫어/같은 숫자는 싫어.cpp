#include <vector>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    deque<int> s;

    for (int i{ 0 }; i < arr.size(); i++) {
        if (s.empty()) {
            s.push_back(arr[i]);
        }
        else if (s.back() != arr[i]) {
            s.push_back(arr[i]);
        }
    }

    int size = s.size();

    for (int i{ 0 }; i < size; i++) {
        answer.push_back(s.front());
        s.pop_front();
    }

    return answer;
}