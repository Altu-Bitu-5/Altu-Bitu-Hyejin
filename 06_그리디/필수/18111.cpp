#include<iostream>
#include<vector>
using namespace std;

pair<int, int> getResult(vector<vector<int>> blocks, int N, int M, int h) {
	// 높이 h로 만들 때의 결과
	int down = 0, up = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (blocks[i][j] > h) { down += blocks[i][j] - h; }
			else if (blocks[i][j] < h) { up += h - blocks[i][j]; }
		}
	}

	return { down, up };
}

pair<int, int> levelGround(vector<vector<int>> blocks, int N, int M, int B, int min, int max) {
	int time = 999999999;
	int height;
	for (int i = min; i <= max; i++) { // 모든 높이의 결과 중 최소 찾기
		pair<int, int> result = getResult(blocks, N, M, i);
		int down = result.first;
		int up = result.second;
		if (down + B >= up) {
			if ((down * 2) + up <= time) {
				time = (down * 2) + up;
				height = i;
			}
		}
	}

	return { time, height };
}

int main(void) {
	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> blocks(N, vector<int>(M, 0));
	int min = 256, max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> blocks[i][j];
			if (blocks[i][j] < min) { min = blocks[i][j]; }
			if (blocks[i][j] > max) { max = blocks[i][j]; }
		}
	}

	pair<int, int> result = levelGround(blocks, N, M, B, min, max);
	cout << result.first << " " << result.second;

	return 0;
}