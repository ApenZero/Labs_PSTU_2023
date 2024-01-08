#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	cout << "Введите число n - катет треугольника" << endl;
	int n;
	cin >> n;
	int zv = n;
	int schet;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < zv; j++) {
			cout << '*';
		}
		zv -= 1;
		for (int j = n; j < (n - i); j++) {
			cout << ' ';
		}
		cout << endl;
	}
}