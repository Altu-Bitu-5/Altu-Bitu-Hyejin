#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;

	int s = 0;
	string func;
	int num;
	for (int i = 0; i < m; i++) {
		cin >> func;
		if (func == "all") {
			s = (1 << 21) - 1;
		}
		else if (func == "empty") {
			s = 0;
		}
		else if (func == "add") {
			cin >> num;
			s = s | (1 << num);
		}
		else if (func == "remove") {
			cin >> num;
			s = s & ~(1 << num);
		}
		else if (func == "check") {
			cin >> num;
			if (s & (1 << num))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (func == "toggle") {
			cin >> num;
			s = s ^ (1 << num);
		}
	}
}