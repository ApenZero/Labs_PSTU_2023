#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int a, b, c, D;
	cin >> a >> b >> c;
	float x1, x2;
	D = b * b - 4 * a * c;
	x1 = ((-b) + sqrt(D)) / (2 * a);
	x2 = ((-b) - sqrt(D)) / (2 * a);
	cout << "уравнение вида: " << a << "*x^2 + " << b << "*x + " << c << " = 0" << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
}