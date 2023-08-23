#include<iostream>
#include<vector>
#include<string>
#include <cctype>
#include<algorithm>
using namespace std;

bool compare(string a, string b) {

	if (a.length() != b.length()) {
		return a.length() < b.length();
	}

	int asum = 0;
	int bsum = 0;

	for (char c : a) {
		if (isdigit(c)) {
			int digit = c - '0';
			asum += digit;
		}
	}

	for (char c : b) {
		if (std::isdigit(c)) {
			int digit = c - '0';
			bsum += digit;
		}
	}

	if (asum != bsum) {
		return asum < bsum;
	}

	return a < b;
}

int main() {
	vector <string> list;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		list.push_back(str);
	}

	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << list[i] << "\n";
	}

}