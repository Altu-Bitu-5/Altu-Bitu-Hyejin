#include <iostream>
using namespace std;

string getPalindrome(string s) {
	int alpha[26] = { 0 };
	int odd = 0;
	int p1 = 0, p2 = s.size() - 1;

	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) {
			continue;
		}
		if (alpha[i] % 2 == 1) {//È¦¼ö
			char ch = i + 'A';
			s[s.size() / 2] = ch;
			alpha[i]--;
			odd++;
		}
		if (alpha[i] % 2 == 0) {//Â¦¼ö
			for (int j = 0; j < alpha[i] / 2; j++) {
				s[p1++] = i + 'A';
				s[p2--] = i + 'A';
			}
		}

		if (odd >= 2) { // È¦¼ö°³ÀÎ ¹®ÀÚ°¡ 2°³ ÀÌ»óÀÌ¸é
			return "I'm Sorry Hansoo\n";
		}
	}

	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	cout << getPalindrome(s);

	return 0;
}