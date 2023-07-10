#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
    bool answer = true;

    int mx = max(a.size(), b.size());

    for (int i{ 0 }; i < mx; i++) {
        if (int(a[i]) == int(b[i])) {
            answer = stoi(a + b) > stoi(b + a);
            break;
        }
        else {
            answer = a[i] > b[i];
            break;
        }
    }
    
    return answer;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;

    for (int i{ 0 }; i < numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
    }

    sort(v.begin(), v.end(),compare);

    if (v[0] == "0") {
        return "0";
    }

    for (int i{ 0 }; i < v.size(); i++) {
        answer += v[i];
    }

    return answer;
}