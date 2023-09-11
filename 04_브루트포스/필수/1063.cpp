#include<iostream>
#include<vector>
#include<string>
using namespace std;

string movePosiiton(string position, string m) { //�ѹ� �̵��ϴ� �Լ�
	if (m == "R") {
		if (position[0] == 'H') //�̵� �Ұ��ϸ� ESCAPE ����
			return "E";
		position[0] = (position[0] - 'A' + 1) % 26 + 'A'; //�̵������ϸ� position ����
	}
	else if (m == "L") {
		if (position[0] == 'A')
			return "E";
		position[0] = (position[0] - 'A' - 1) % 26 + 'A';
	}
	else if (m == "B") {
		if (position[1] == '1')
			return "E";
		position[1] -= 1;
	}
	else if (m == "T") {
		if (position[1] == '8')
			return "E";
		position[1] += 1;
	}
	else if (m == "RT") {
		if (position[0] == 'H' || position[1] == '8')
			return "E";
		position[0] = (position[0] - 'A' + 1) % 26 + 'A';
		position[1] += 1;
	}
	else if (m == "LT") {
		if (position[0] == 'A' || position[1] == '8')
			return "E";
		position[0] = (position[0] - 'A' - 1) % 26 + 'A';
		position[1] += 1;
	}
	else if (m == "RB") {
		if (position[0] == 'H' || position[1] == '1')
			return "E";
		position[0] = (position[0] - 'A' + 1) % 26 + 'A';
		position[1] -= 1;
	}
	else if (m == "LB") {
		if (position[0] == 'A' || position[1] == '1')
			return "E";
		position[0] = (position[0] - 'A' - 1) % 26 + 'A';
		position[1] -= 1;
	}

	return position;
}

pair<string, string> lastPositionKD(string k, string d, vector<string> move) {
	// n�� �̵� �� ������ k, d ��ġ ����

	for (int i = 0; i < move.size(); i++) { // n�� �̵�
		string temp_k = k;
		string temp_d = d;

		temp_k = movePosiiton(k, move[i]); // k �̵�
		if (d == temp_k) {
			temp_d = movePosiiton(d, move[i]); //k �̵� �� d�� ���� ��ġ�� d �̵�
		}

		if (temp_k != "E" && temp_d != "E") { //k, d �̵� �Ұ����� ������ ����
			k = temp_k;
			d = temp_d;
		}
	}

	return { k, d };
}

int main() {
	string k, d;
	int n;
	vector<string> move;

	cin >> k >> d >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		move.push_back(input);
	}

	pair<string, string> result = lastPositionKD(k, d, move);
	cout << result.first << "\n";
	cout << result.second << "\n";
}