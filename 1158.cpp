#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	queue <int> q;
	vector <int> v;
	int k, n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cin >> k;

	int i = 1;

	while (q.size()) {
		if (i % k == 0) {
			v.push_back(q.front());
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		i++;
	}

	cout << "<" << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << ", " << v[i];
	}
	cout << ">";
}
