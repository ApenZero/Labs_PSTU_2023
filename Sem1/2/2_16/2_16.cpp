#include <iostream>
using namespace std;
int main() {
	int n, a, b, s;
	a = -1;
	b = 2;
	s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		s = s + (a + b);
		a -= 2;
		b += 2;
	}
	cout << s;
}