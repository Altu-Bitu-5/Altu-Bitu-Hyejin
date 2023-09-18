#include <iostream>
#include<cstring>
#include<vector>
using namespace std;

bool p[1000001];
vector<int> primes;

void setPrimes() {
	memset(p, true, sizeof(p));
	for (int i = 2; i <= 500000; i++) {
		for (int j = 2; i * j <= 1000000; j++)
			p[i * j] = 0;
	}
	for (int i = 3; i < 1000000; i = i + 2) {
		if (p[i]) {
			primes.push_back(i);
		}
	}
}

int printCases(int n) {

	for (int i = 0; primes[i] <= n / 2; i++) {
		if (p[n - primes[i]] == 1) {
			cout << n << " = " << primes[i] << " + " << n - primes[i] << "\n";
			return 0;
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	setPrimes();

	int input;
	while (1) {
		cin >> input;
		if (input == 0)
			return 0;
		printCases(input);
	}

	return 0;
}