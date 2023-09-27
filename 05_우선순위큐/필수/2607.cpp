#include<iostream>
#include<algorithm>
using namespace std;


int checkSimilar(string str, string cmpstr) {

	int strcnt[26] = { 0 };
	for (int i = 0; i < str.size(); i++) {
		strcnt[str[i] - 'A']++;
	}

	int pass = 0;
	for (int i = 0; i < cmpstr.size(); i++) {
		if (strcnt[cmpstr[i] - 'A'] > 0) {
			strcnt[cmpstr[i] - 'A']--;
			pass++;
		}
	}

	if (cmpstr.size() == str.size()) {
		if (pass >= cmpstr.size() - 1) {
			return 1;
		}
	}
	else if (cmpstr.size() == str.size() + 1) {
		if (pass >= cmpstr.size() - 1) {
			return 1;
		}
	}
	else if (cmpstr.size() == str.size() - 1) {
		if (pass >= cmpstr.size()) {
			return 1;
		}
	}

	return 0;
}

int main() {

	int cnt = 0;
	int n;
	string str;

	cin >> n;
	cin >> str;

	for (int i = 0; i < n - 1; i++) {
		string cmpstr;
		cin >> cmpstr;

		cnt += checkSimilar(str, cmpstr);
	}
	cout << cnt;
}