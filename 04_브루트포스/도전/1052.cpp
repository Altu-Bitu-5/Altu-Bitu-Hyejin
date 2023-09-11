#include<iostream>
#include <bitset>
using namespace std;

int findMinimumBottlesRequired(int n, int k) {
	int total_water = n;

	while (1) {
		bitset<32> total_binary(total_water);
		int count = total_binary.count();
		if (count <= k) { //최소 물병이 k이하면 중단
			break;
		}

		total_water++; //최소 물병이 k보다 크면 물병 추가
	}
	return total_water - n;
}

int main() {

	int n, k;
	cin >> n >> k;

	cout << findMinimumBottlesRequired(n, k);
}