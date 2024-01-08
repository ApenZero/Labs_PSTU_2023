#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	cin >> n;
	while (n < 2) {
		cout << "Введите n > 1";
		cin >> n;
	}
	for (int i = 0; i < n; i++) {
		if ((i == 0) || (i == (n - 1))) {
			for (int j = 0; j < n; j++) {
				cout << "*";
			}
			cout << endl;
		}
		else {
			cout << "*";
			for (int j = 0; j < (n - 2); j++) {
				cout << " ";
			}
			cout << "*" << endl;
		}
	}
}