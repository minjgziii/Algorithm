#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int direction[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
bool visited[101][101];
int dist[101][101];
queue<pair<int, int>> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();

    visited[0][0] = true;
    q.push({ 0,0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i{ 0 }; i < 4; i++) {
            int now_x = x + direction[i][0];
            int now_y = y + direction[i][1];

            if (now_x < 0 || now_x >= n || now_y < 0 || now_y >= m) {
                continue;
            }
            if (visited[now_x][now_y]) {
                continue;
            }
            if (maps[now_x][now_y] == 0) {
                continue;
            }

            visited[now_x][now_y] = true;
            q.push({ now_x,now_y });
            dist[now_x][now_y] = dist[x][y] + 1;
        }
    }

    if (dist[n - 1][m - 1] == 0) {
        answer = -1;
    }
    else {
        answer = dist[n - 1][m - 1];
    }

    return answer;
}