#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int n, a, znak;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 0) {
			cout << "Отрицательное число было первым";
			break;
		}
		if (a > 0) {
			cout << "Положительное число было первым";
			break;
		}
	}
}