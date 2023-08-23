#include<iostream>
#include<map>
using namespace std;

int main() {
	int n, m;
	int cnt = 0;
	map <string, int> map;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		map[str] = 1;
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (map[str]) {
			cnt++;
		}
	}

	cout << cnt;

}