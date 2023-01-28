#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 0;
	int H = 0;
	int W = 0;
	int N = 0;
	
	cin >> T;

	for (int i{ 0 }; i < T; i++) {
		int a = 1;
		
		cin >> H >> W >> N;

		vector<vector<int>> v(H, vector<int>(W, 0));


		for (int i{ 0 }; i < W; i++) {
			for (int j{ 0 }; j < H; j++) {
				v[j][i] = a;

				if (a == N) {
					string room = "";

					string jj = to_string(j + 1);
					string ii = to_string(i + 1);
					
					if ((std::stoi(jj) >= 10 && std::stoi(ii) >= 10) || std::stoi(jj) >= 10 || std::stoi(ii) >= 10) {
						room = jj + ii;
					}
					else {
						room = jj + "0" + ii;
					}
					cout << 100 * std::stoi(jj) + std::stoi(ii) << "\n";
				}
				a++;
			}
		}
	}

}