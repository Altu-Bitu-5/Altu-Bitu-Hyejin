#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string a;
	string b;
	vector<int> result;
	int len;

	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.size() > b.size()) {
		len = a.size();
	}
	else {
		len = b.size();
	}


	int t = 0;
	for (int i = 0; i < len; i++) {
		int r;
		if (i < a.size() && i < b.size()) {
			r = (a[i] - '0') + (b[i] - '0');
		}
		else if (i < a.size()) {
			r = (a[i] - '0');
		}
		else {
			r = (b[i] - '0');
		}

		r += t;
		if (r >= 10) {
			r -= 10;

			result.push_back(r);

			t = 1;
		}
		else {
			result.push_back(r);

			t = 0;
		}

	}

	reverse(result.begin(), result.end());
	if (t == 1) {
		cout << 1;
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

}
