#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";

    string tmp = "";
    vector<string> v;


    for (int i{ 0 }; i < s.size(); i++) {
        // 공백이 아닐 때
        if (s[i] != ' ') {
            tmp += s[i];
        }
        // 공백일 때
        else {
            tmp += ' ';
			if (s[i + 1] != ' ') {
				if (tmp[0] >= 'a' && tmp[0] <= 'z') {
					tmp[0] = toupper(tmp[0]);
				}
				for (int i{ 1 }; i < tmp.size(); i++) {
					if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
						tmp[i] = tolower(tmp[i]);
					}
				}
				answer += tmp;
				tmp.clear();
			}
        
		}
	}

    if (tmp[0] >= 'a' && tmp[0] <= 'z') {
        tmp[0] = toupper(tmp[0]);
    }
    for (int i{ 1 }; i < tmp.size(); i++) {
        if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
            tmp[i] = tolower(tmp[i]);
        }
    }
    answer += tmp;

    return answer;
}