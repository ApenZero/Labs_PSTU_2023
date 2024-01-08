#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "RU");
	int s, b, a;
	long int n;
	b = 0;
	a = 0;
	cin >> n >> s;
	while (n > 0) {
		b = n % 10;
		if (b == s) {
			cout << "Число " << s << " входит в n";
			a = 1;
			break;
		}
		n = n / 10;
	}
	if (a == 0) {
		cout << "Число " << s << " не входит в n";
	}
}