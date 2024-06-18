# include <iostream>
#include <cmath>
using namespace std;
//(1/((2*i)+1) * pow((x-1)/(x+1), ((2*i)+1))
double n;
double suma1 = 0;
double funcrow(double n, double x) {
	double ar = (x - 1) / (x + 1);
	double arr;
	if (n == -1) {
		return suma1;
	}
	else {
		arr = 2 * n + 1;
		suma1 += (1 / arr * pow(ar, arr));
		funcrow(n - 1, x);

	}
}
double dircalc(double x) {
	double suma = 0;
	double ar = (x - 1) / (x + 1);
	double arr;
	for (int i = 0; i < n; i++) {
		arr = 2 * i + 1;
		suma += (1 / arr * pow(ar, arr));
	}
	return suma;
}
int main() {
	double x;
	cout << "Enter n " << endl;
	cin >> n;
	cout << "Enter x " << endl;
	cin >> x;
	cout << "Direct calculation value " << dircalc(x) << endl;
	cout << "Recursive calculation value " << funcrow(n, x);
	return 0;
}