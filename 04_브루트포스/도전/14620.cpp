#include<iostream>
using namespace std;

int n;
int min_cost = 3000;
int cost[10][10] = { 0 };
int garden[10][10] = { 0 };

int plantable(int index) { // index를 중심으로 한 영역에 꽃을 심을 수 있는지 확인
	if (index / n == 0 || index % n == 0 || index / n == n - 1 || index % n == n - 1)
		return -1;
	int x = index / n;
	int y = index % n;

	if (garden[x][y] != 0 || garden[x + 1][y] != 0 || garden[x][y + 1] != 0 ||
		garden[x - 1][y] != 0 || garden[x][y - 1] != 0)
		return -1;

	return cost[x][y] + cost[x + 1][y] + cost[x][y + 1] + cost[x - 1][y] + cost[x][y - 1];
}
void checkGarden(int index) { // index를 중심으로 한 영역 1로 변경
	int x = index / n;
	int y = index % n;
	garden[x][y] = 1;
	garden[x + 1][y] = 1;
	garden[x][y + 1] = 1;
	garden[x - 1][y] = 1;
	garden[x][y - 1] = 1;
}

void uncheckGarden(int index) { // index를 중심으로 한 영역 0으로 변경
	int x = index / n;
	int y = index % n;
	garden[x][y] = 0;
	garden[x + 1][y] = 0;
	garden[x][y + 1] = 0;
	garden[x - 1][y] = 0;
	garden[x][y - 1] = 0;
}

void bt(int depth, int curindex, int cost) { // 모든 경우를 backtracking으로 확인
	if (depth >= 3) { // 꽃 3개를 심은 경우
		if (cost < min_cost)
			min_cost = cost;
	}
	else {
		for (int i = curindex; i < n * n; i++) {
			int curcost = plantable(i);
			if (curcost >= 0) { // 해당 영역에 꽃을 심을 수 있으면
				checkGarden(i);
				bt(depth + 1, i + 2, cost + curcost);
				uncheckGarden(i);
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	bt(0, 1, 0);

	cout << min_cost;
}