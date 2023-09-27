#include<iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	int n;
	int input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 0) {
			if (pq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			int val;
			for (int j = 0; j < input; j++) {
				cin >> val;
				pq.push(val);
			}
		}
	}
}