#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    vector<int> f;
    vector<int> b;
    int size = topping.size();

    map<int, int> m;

    for (int i{ 0 }; i < size; i++) {
        m.insert({ topping[i],1 });
        f.push_back(m.size());
    }

    m.clear();

    for (int i{ size - 1 }; i >= 0; i--) {
        m.insert({ topping[i],1 });
        b.push_back(m.size());
    }

    reverse(b.begin(), b.end());

    for (int i{ 0 }; i < size - 1; i++) {
        if (f[i] == b[i + 1]) {
            answer++;
        }
    }
    return answer;
}