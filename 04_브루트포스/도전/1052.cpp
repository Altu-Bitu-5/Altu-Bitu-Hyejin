#include<iostream>
#include <bitset>
using namespace std;

int findMinimumBottlesRequired(int n, int k) {
	int total_water = n;

	while (1) {
		bitset<32> total_binary(total_water);
		int count = total_binary.count();
		if (count <= k) //�ּ� ������ k���ϸ� �ߴ�
			break;

		total_water++; //�ּ� ������ k���� ũ�� ���� �߰�
	}
	return total_water - n;
}

int main() {

	int n, k;
	cin >> n >> k;

	cout << findMinimumBottlesRequired(n, k);
}