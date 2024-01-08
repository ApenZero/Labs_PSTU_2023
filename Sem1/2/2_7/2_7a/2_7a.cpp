#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	int proverka;
	cout << "Введите n > 1, имеющее целый извлекаемый корень" << endl;
	cin >> n;
	float dlina = sqrt(n);
	proverka = dlina;
	while ((n < 2) || (proverka - dlina != 0)) {
		cout << "Введите n > 1, имеющее целый извлекаемый корень";
		cin >> n;
	}
	for (int i = 0; i < dlina; i++) {
		for (int j = 0; j < dlina; j++) {
			cout << "*";
		}
		cout << endl;
	}
}