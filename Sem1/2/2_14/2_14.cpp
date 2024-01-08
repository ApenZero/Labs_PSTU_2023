#include <iostream>
using namespace std;
int main() {
	int n, b;
	b = 0;
	cin >> n;
	while (n > 0) {
		b = b + n % 10;
		n = n / 10;
	}
	cout << b;
}