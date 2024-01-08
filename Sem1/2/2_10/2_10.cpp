#include <iostream>
using namespace std;
int main() {
	int n, a, max;
	max = 0;
	cin >> n >> a;
	max = a;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		if (a > max) {
			max = a;
		}
	}
	cout << max;
}