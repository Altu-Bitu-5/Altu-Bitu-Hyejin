#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool check666(int num) { // 연속된 666이 있는지 확인
	string str = to_string(num);
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '6') {
			cnt += 1;
		}
		else {
			cnt = 0;
		}

		if (cnt >= 3) {
			return true;
		}
	}

	return false;
}

int findNumber(int n) { // n번째 666을 포함한 숫자 리턴
	vector<int> number666;

	int num = 666;
	while (number666.size() < n) {
		if (check666(num)) {
			number666.push_back(num);
		}
		num++;
	}

	return number666[n - 1];
}

int main() {

	int n;
	cin >> n;
	cout << findNumber(n);
}