#include<iostream>
#include<vector>
using namespace std;

void findAlp(int n, int k) {

	vector<char> list(n);
	vector<bool> check_rep(31);
	bool impossible = false;
	int index = 0;

	for (int i = 0; i < k; i++) {
		int s;
		char alp;
		cin >> s >> alp;

		if (!impossible) {
			index += s;

			if (list[index % n] != NULL) {
				if (list[index % n] != alp) {
					impossible = true;
				}
			}
			else {
				if (check_rep[alp % 31]) {
					impossible = true;
				}
				else {
					list[index % n] = alp;
					check_rep[alp % 31] = true;
				}
			}
		}
	}

	if (impossible) {
		cout << "!";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (list[index % n] != NULL) {
			cout << list[index % n];
		}
		else {
			cout << "?";
		}
		index--;
		if (index < 0) {
			index += n;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	findAlp(n, k);

}