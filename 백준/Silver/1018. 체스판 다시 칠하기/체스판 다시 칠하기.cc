#include<iostream>
using namespace std;

char arr[51][51];

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

// 처음이 W
int f_white(int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != WB[i][j]) {
				result++;
			}
		}
	}
	return result;
}

// 처음이 B
int f_black(int x, int y) {
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != BW[i][j]) {
				result++;
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int N = 0;
	int M = 0;

    int result = 64;
	int white;
    int black;

	cin >> N >> M;

    // 체스판 입력 받기
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			cin >> arr[i][j];
		}
	}
    

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
			white = f_white(i, j);
			black = f_black(i, j);
			if (white < black) {
				result = (white < result) ? white : result;
			}
			else {
				result = (black < result) ? black : result;
			}
        }
    }
    
	cout << result << '\n';

}