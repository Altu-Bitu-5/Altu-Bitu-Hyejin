#include<iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, greater<>> pq;
	int n;
	cin >> n;

	int input;
	for (int i = 0; i < n * n; i++) {
		cin >> input;
		if (pq.size() >= n) {
			if (input > pq.top()) {
				pq.pop();
				pq.push(input);
			}
		}
		else {
			pq.push(input);
		}
	}

	cout << pq.top();
}