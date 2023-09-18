#include<iostream>
using namespace std;

int findGCD(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int findLCM(int a, int b) {
	int gcd = findGCD(a, b);
	int lcm = (a * b) / gcd;
	return lcm;
}

void printFracSum(int num1, int den1, int num2, int den2) {

	int gdc1 = findGCD(num1, den1);
	num1 = num1 / gdc1;
	den1 = den1 / gdc1;

	int gdc2 = findGCD(num2, den2);
	num2 = num2 / gdc2;
	den2 = den2 / gdc2;

	int den3 = findLCM(den1, den2);
	int t1 = den3 / den1;
	int t2 = den3 / den2;
	int num3 = num1 * t1 + num2 * t2;

	int gdc3 = findGCD(num3, den3);
	num3 = num3 / gdc3;
	den3 = den3 / gdc3;

	cout << num3 << " " << den3;
}

int main() {

	int frac1[2];
	int frac2[2];

	cin >> frac1[0] >> frac1[1];
	cin >> frac2[0] >> frac2[1];

	printFracSum(frac1[0], frac1[1], frac2[0], frac2[1]);
}