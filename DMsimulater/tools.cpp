#include "tools.h"
template <class T> T checkIn(T type) {
	T inTemp;
	cin >> inTemp;
	if (cin.good()) {
		return inTemp;
	}
	else {
		cin.clear();		//这一句很总要，将cin重新标记为正确，以达到重新输入的目的
		while (cin.get() != '\n')		//这里清空之前cin缓冲区的数据
			continue;
		cout << "输入有误，请重新输入";
		return checkIn(type);
	}
}

int rollxdyhz(int x, int y, int z)
{
	{
		//_sleep(1000);
		srand((unsigned)time(NULL));
		int* roll = new int[x];
		int Modulus = y;
		for (int i = 0; i < x; i++) {
			roll[i] = 1 + rand() % Modulus;
			cout << roll[i] << "  ";
		}
		int temp;
		for (int j = 0; j < x - 1; j++) {
			for (int k = 0; k < x - 1 - j; k++) {
				if (roll[k] < roll[k + 1]) {
					temp = roll[k];
					roll[k] = roll[k + 1];
					roll[k + 1] = temp;
				}
			}
		}
		//for (int i = 0; i < x; i++) {	cout << "|" << roll[i] << "  ";};
		int sum = 0;
		for (int i = 0; i < z; i++) {
			sum += roll[i];
		}
		cout << sum;
		return sum;
	}
}

int rollxdy_add(int x, int y, int add)
{
	srand((unsigned)time(NULL));
	int* roll = new int[x];
	int Modulus = y, sum = 0;
	for (int i = 0; i < x; i++) {
		roll[i] = 1 + rand() % Modulus;
		cout << roll[i] << "  ";
		sum += roll[i];
	}
	return sum+add;
}

int confirm()
{
	string a;
	cout << "确认？(yes/no)";
	cin >> a;
	if (a.at(0) == 'Y' || a.at(0) == 'y') {
		return 1;
	}
	else if (a.at(0) == 'N' || a.at(0) == 'n') {
		return 0;
	}
	else {
		cout << "输入错误，自动返回否认";
		return 0;
	}
	return 0;
}

void pause() {
	cout << endl;
	system("pause");
	system("cls");
}

bool changeYes()
{
	cout << "确定修改？(Yes/No)\n";
	string choice;
	cin >> choice;
	if (choice.substr(0, 1) == "y")return true;
	return false;
}

int pay(int ability, int* point, int reduce) {
	if (reduce == -4) {
		ability = 7;
		return ability;
	}
	else if (reduce == -2) {
		ability = 8;
		return ability;
	}
	else if (reduce == -1) {
		ability = 9;
		return ability;
	}
	else if (reduce == 0) {
		ability = 10;
		return ability;
	}
	else if (reduce == 1) {
		ability = 11;
		return ability;
	}
	else if (reduce == 2) {
		ability = 12;
		return ability;
	}
	else if (reduce == 3) {
		ability = 13;
		return ability;
	}
	else if (reduce == 5) {
		ability = 14;
		return ability;
	}
	else if (reduce == 7) {
		ability = 15;
		return ability;
	}
	else if (reduce == 10) {
		ability = 16;
		return ability;
	}
	else if (reduce == 13) {
		ability = 17;
		return ability;
	}
	else if (reduce == 17) {
		ability = 18;
		return ability;
	}
	else {
		return ability;
	}
}