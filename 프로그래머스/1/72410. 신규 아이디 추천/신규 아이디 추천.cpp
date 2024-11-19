#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    bool flag = false;
    vector<int> v;

    // 1. 대문자 -> 소문자 치환
    for(int i=0; i<new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);

        // 2. new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
        if ((isalpha(new_id[i])!=0) || isdigit(new_id[i]) == true || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            continue;
        }
        else {
            new_id[i] = '+';
        }
    }

    new_id.erase(remove(new_id.begin(), new_id.end(), '+'), new_id.end());
    string temp = "";

    // 3. new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    for(char c : new_id) {
        if( c== '.' && temp.back() == '.') {
            continue;
        }
        temp += c;
    }

    new_id = temp;

    // 4. new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거
    if(new_id.front() == '.') new_id.erase(0, 1);
    if(new_id.back() == '.') new_id.pop_back();

    // 5. new_id가 빈 문자열이라면, new_id에 "a"를 대입
    if(new_id.empty()) {
        new_id = 'a';
    }

    // 6. new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    if(new_id.size() >= 16) {
        new_id.erase(new_id.begin()+15, new_id.end());
    }
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
    if(new_id.back() == '.') {
        new_id.pop_back();
    }


    // 7. new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙임
    if(new_id.size()<= 2) {
        char a = new_id[new_id.size()-1];

        while(new_id.size()<3) {
            new_id += a;
        }
    }

    return new_id;
}