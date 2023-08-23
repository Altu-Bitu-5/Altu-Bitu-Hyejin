#include<iostream>
#include <cstdlib>
using namespace std;

int main() {

	int w0, i0, t, d, i, a;


	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	int w01 = w0;
	int w02 = w0;
	int i01 = i0;
	int i02 = i0;


	w01 = w0 + (i - i0 - a) * d;
	if (w01 > 0) {
		cout << w01 << " " << i0 << "\n";
	}
	else {
		cout << "Danger Diet\n";
	}



	for (int k = 0; k < d; k++) {
		int w = i - i02 - a;
		w02 += w;

		if (w > t || w < -t) {
			i02 = w % 2 ? i02 + w / 2 - 1 : i02 + w / 2;
		}
		//cout << "day" << k+1 << "\n";
		//cout << "w=" << w02 << " i=" << i02 << "\n";
	}

	if (w02 > 0 && i02 > 0) {
		cout << w02 << " " << i02 << " ";
		int e = i02;
		int w = i0 - e;
		if (w > 0) {
			cout << "YOYO";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "Danger Diet";
	}

}