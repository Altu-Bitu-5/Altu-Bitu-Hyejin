#include<iostream>
#include<stack>
#include <string>
using namespace std;

int main() {
	stack<char> s;
	while (true) {
		string str;
		getline(cin, str);

		if (str == ".") {
			break;
		}

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					s.push('.');
					break;
				}
			}
			else if (str[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					s.push('.');
					break;
				}
			}
		}

		if (s.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
			while (!s.empty()) {
				s.pop();
			}
		}

	}
}