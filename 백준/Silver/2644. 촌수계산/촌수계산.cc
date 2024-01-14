#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n; // 사람의 수
int a, b; // 촌수를 계산할 서로 다른 두 사람의 번호
int m; // 부모 자식들 간의 관계의 개수
int x, y; // 부모 자식 간의 관계를 나타내는 번호
vector<int> vec[101];
bool visited[101];
int ans = -1;

void DFS(int a,int b, int cnt) {
	visited[a] = true;

	if (a == b) {
		ans = cnt;
		return;
	}

	for (int i{ 0 }; i < vec[a].size(); i++) {
		if (!visited[vec[a][i]]) {
			DFS(vec[a][i], b, cnt + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i{ 0 }; i < m; i++) {
		cin >> x >> y;
		
		vec[x].push_back(y);
		vec[y].push_back(x);
	}

	DFS(a, b, 0);

	cout << ans;

}