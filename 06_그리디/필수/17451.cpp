#include <iostream>
#include<vector>
using namespace std;

long long getMinSpeed(vector<int> arr) {
	long long cur = arr[arr.size() - 1];
	for (int i = arr.size() - 2; i >= 0; i--) {
		if (cur % arr[i] == 0) { // �ӵ� ����
			continue;
		}
		else { // ���� �ӵ����� ũ�� arr[i]�� ����� ��
			cur = arr[i] * (cur / arr[i] + 1);
		}
	}
	return cur;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> arr;
	int n, input;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
	}

	cout << getMinSpeed(arr);

	return 0;
}